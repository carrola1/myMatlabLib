
%% Parameters
% Configuration
fs        = 1e9;        % Sample rate (Hz)
symRate   = 1e6;       % Symbol rate (Hz)
carFreq   = 100e6;         % Carrier freq (Hz)
numData   = 1000;         % # of symbols to simulate
staggerOn = 1;
constAmp  = 1;            % Use constellation points or gain/offset to adjust I/Q

% I/Q Characteristics
% Worst case scenario when : amp1 and amp3 are equally out of balance
%   phase0 and phase2 have pos offset, phase1 and phase3 have neg offset
iPat      = 'Square';     % 'Off','Square', or 'Rand' data
qPat      = 'Square';     % 'Off, 'Square', or 'Rand' data
amp0      = 1;       % Amplitude of constellation pt. 0
phaseOff0 = 5/180*pi;          % Phase offset of constellation pt. 0 (rad)
amp1      = 1;
phaseOff1 = 0/180*pi;
amp2      = 1;
phaseOff2 = 0/180*pi;
amp3      = 1;
phaseOff3 = 0/180*pi;

iAmp      = 1;        % Percent skew
qAmp      = 1;          % Percent skew
iOffset   = .01;
qOffset   = .01;

%% Modulator
tstamp = 1/fs;
t      = 0:tstamp:1/symRate*numData-tstamp;

if strcmp(iPat,'Rand')
  dataI = myGenRndData(numData,round(fs/symRate),1);
elseif strcmp(iPat,'Off')
  dataI = ones(1,numData*round(fs/symRate));
else
  dataI = myGenSqWave(numData,round(fs/symRate),1);
end

if strcmp(qPat,'Rand')
  dataQ = myGenRndData(numData,round(fs/symRate),1);
elseif strcmp(qPat,'Off')
  dataQ = ones(1,numData*round(fs/symRate));
else
  dataQ = myGenSqWave(numData,round(fs/symRate),1);
end

if staggerOn == 1
    dataQ = [ones(1,round(fs/symRate/2))*-1 dataQ(1:end-round(fs/symRate/2))];
end

modI = zeros(1,length(dataI));
modQ = zeros(1,length(dataQ));
for ii = 1:length(dataI)
  if dataI(ii)==1 && dataQ(ii)==1
    modI(ii) = amp0*cos(pi/4+phaseOff0);
    modQ(ii) = amp0*sin(pi/4+phaseOff0);
  elseif dataI(ii)==-1 && dataQ(ii)==1
    modI(ii) = -amp1*cos(pi/4-phaseOff1);
    modQ(ii) = amp1*sin(pi/4-phaseOff1);
  elseif dataI(ii)==-1 && dataQ(ii)==-1
    modI(ii) = -amp2*cos(pi/4+phaseOff2);
    modQ(ii) = -amp2*sin(pi/4+phaseOff2);
   elseif dataI(ii)==1 && dataQ(ii)==-1
    modI(ii) = amp3*cos(pi/4-phaseOff3);
    modQ(ii) = -amp3*sin(pi/4-phaseOff3);
  end
end

if constAmp == 1
  modI = dataI*sqrt(2)/2*iAmp + iOffset;
  modQ = dataQ*sqrt(2)/2*qAmp + qOffset;
end

carI   = cos(2*pi*carFreq*t);
carQ   = sin(2*pi*carFreq*t);

ModOut = carI.*modI + carQ.*modQ;

%% Plot Results
[fOut, pwrOut] = myPlotSigPwr(ModOut,fs);
figure(1)
plot(fOut/1e6,pwrOut)
title('Frequency Response')
xlabel('Frequency (MHz)')
ylabel('Magnitude (dB)')
xlim([(carFreq-4*symRate)/1e6 (carFreq+4*symRate)/1e6])
ylim([-80 0])

figure(2)
plot(modI,modQ)
title('Constellation')
axis([-1.5 1.5 -1.5 1.5])
hold on
x = cos(0:pi/128:2*pi);
y = sin(0:pi/128:2*pi);
plot(x,y,'r')
hold off