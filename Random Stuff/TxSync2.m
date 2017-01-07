
%% Simulation Parameters
numSamps  = 2^20;
phaseOff  = 0;  % starting phase offset
fSym      = 3e6;

%% System Parameters
fSys      = 48e6;
fSymNom   = fSym;

%% Transmitter Parameters
ncoWidth  = 32;
if fSym > 500e3
    pCoeff = 1/2^8;   % P=1/2^8, I = 1/2^10 stops working at sym rate of 100e3 and below
elseif fSym > 100e3
    pCoeff = 1/2^10;
else
    pCoeff = 1/2^12;
end
iCoeff    = pCoeff/4;
dacWidth  = 10;
dacMax    = 2^(dacWidth-1)-1;

% Phase Filter
% To get < 1% jitter you need the ratio of N/bitsPerFilt to be > 100,
%   increasing the ratio continues to improve jitter. Decreasing the
%   ratio gives better filter response. Increasing the ratio also pushes
%   out image frequencies which will show up around the ratio*fSym.
% High N gives more accurate filter response.
bitsPerFilt = 4;
N    = 1024;                 % Order
Fs   = fSys/1e6;             % sampling frequency
FcP  = 1.5;                  % Fc as % of symbol rate
Fc   = bitsPerFilt*Fs/N*1.5; % Cutoff Frequency
TM   = 'Rolloff';            % Transition Mode
R    = 0.3;                  % Rolloff
DT   = 'sqrt';               % Design Type
Beta = 0.5;                  % Window Parameter

win = kaiser(N+1, Beta);

filtCoeffs  = firrcos(N, Fc/(Fs/2), R, 2, TM, DT, [], win);
filt        = cumsum(filtCoeffs);
filt        = round(spline(1:N+1,filt,1:N)*dacMax);
filtLen     = length(filt);

%% Derived Parameters
maxNco     = 2^ncoWidth;
ncoNomOff  = round(maxNco*fSymNom/fSys);

%% Initialize Variables
txMu       = 0;
txClk      = 0;
fallTx     = 0;
txD        = [-1,-1];
nco        = round(maxNco*phaseOff/(2*pi));
errFilt    = 0;
fallRef    = 0;
refClk     = 1;
iFilt      = 0;
refClkLast = 0;
txClkLast  = 0;
phaseRef   = 0;
txDLast    = [1,1];
ncoLast    = 0;
symReg     = ones(2,bitsPerFilt+1)*-1;
phaseAccum = zeros(1,bitsPerFilt+1);
newPhase   = 0;
accumInd   = 1;
refSym     = [-1,-1];
txDStore   = txD;
tp0       = zeros(1,numSamps);
tp1       = zeros(1,numSamps);
tp2       = zeros(1,numSamps);
tp3       = zeros(1,numSamps);
tp4       = zeros(1,numSamps);
tp5       = zeros(1,numSamps);
tp6       = zeros(1,numSamps);
tp7       = zeros(1,numSamps);
tp8       = zeros(1,numSamps);
tp9       = zeros(1,numSamps);

%% Simulation
for ii = 1:numSamps
    
    %% Generate Transmit Data and Clock
    txMu = txMu + 1/fSys;
    if txMu >= 1/fSym
        txMu   = txMu - 1/fSym;
        txD    = sign(randn(1,2));
        txDStore = [txDStore; txD];
        txClk  = not(txClk);
        fallTx = 0;
    elseif (txMu >= 1/fSym/2) && (fallTx == 0)
        fallTx = 1;
        txClk  = not(txClk);
    end
    tp0(ii) = txClk;
    
    %% NCO
    nco = nco + ncoNomOff + errFilt;
    if nco >= maxNco
        nco     = nco - maxNco;
    elseif nco < 0
        nco = nco + maxNco;
    end
    if nco < maxNco/2
        refClk = 1;
    else
        refClk = 0;
    end
    tp1(ii) = refClk;
    tp2(ii) = nco;
    
    %% Phase Detector
    err = 0;
    if txClk == 1 && txClkLast == 0
        if nco <= maxNco/2
            err = -nco;
        else
            err = maxNco - nco;
        end
    end
    txClkLast  = txClk;
    tp3(ii) = err;
    
    %% PI Controller
    pFilt = err*pCoeff;
    iFilt = iFilt + err*iCoeff;
    if iFilt > 2^(ncoWidth-2)       % clamp integrator
        iFilt = 2^(ncoWidth-2);
    elseif iFilt < -2^(ncoWidth-2)
        iFilt = -2^(ncoWidth-2);
    end
    errFilt = round(pFilt + iFilt);
    tp4(ii) = errFilt;
    
    %% Filter
    
    % Calculate phase change from last sample and add to phaseAccums
    if ncoLast > maxNco/2 && nco < maxNco/4
        ncoAdj = nco + maxNco - ncoLast + 1;  
    else
        ncoAdj = abs(nco-ncoLast);
    end
    newPhase = abs(round(ncoAdj/2^(log2(bitsPerFilt))));
    ncoLast  = nco;
    
    for jj = 1:bitsPerFilt+1
        phaseAccum(jj) = phaseAccum(jj) + newPhase;
    end
    
    % If new symbol is available, shift the phaseAccums
    if refClk == 1 && refClkLast == 0
        symReg(:,2:end)      = symReg(:,1:end-1);
        symReg(:,1)          = txD;
        phaseAccum(2:end)    = phaseAccum(1:end-1);
        phaseAccum(1)        = round(nco/2^(log2(bitsPerFilt)));
    end
    refClkLast = refClk;
    
    
    % Calculate filter output
    iReg    = symReg(1,end)*dacMax;
    qReg    = symReg(2,end)*dacMax;
    filtInd = round(phaseAccum/2^(ncoWidth-log2(N)))+1;
    for jj = bitsPerFilt:-1:1
        if filtInd(jj) > filtLen
            filtInd(jj) = filtLen;
        end
        if symReg(1,jj) ~= symReg(1,jj+1)
            iReg = iReg + filt(filtInd(jj))*symReg(1,jj)*2;
        end
        if symReg(2,jj) ~= symReg(2,jj+1)
            qReg = qReg + filt(filtInd(jj))*symReg(2,jj)*2;
        end
    end
    
    tp6(ii) = complex(iReg,qReg);
    
    %% Straight Sampled Comparison
    iRef = txD(1);
    qRef = txD(2);
    tp9(ii) = complex(iRef,qRef);
    
end

%% Ideal Filter Comparison
Fs   = fSys/1e6; % sampling frequency
Fc   = fSym/1e6*FcP;

refFiltCoeffs  = firrcos(N, Fc/(Fs/2), R, 2, TM, DT, [], win);
refFilt = filter(refFiltCoeffs,1,tp9);

%% Analyze Results
figure(1)
plot(tp4)
% figure(2)
% plot(tp0(end-100:end)+1.2)
% hold on
% plot(tp1(end-100:end),'r')
% hold off
figure(3)
plot(real(tp6(end/2:end)),imag(tp6(end/2:end)))
[freq,amp] = myFftC(tp6(end/4:end),fSys,16,'MHz',0);
figure(4)
plot(freq,amp)
myPlotNTIA(freq,amp,20,fSym,1,'MHz',1)
%myXmtDataParams(real(tp6(end/2:end)),imag(tp6(end/2:end)),fSym,fSys)
