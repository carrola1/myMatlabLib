function myXmtDataParams(dataI,dataQ,symbRate,fs)
% Designer:     Andrew Carroll
%
% Description:  Accepts I/Q data input from a simulation output and
%               calculates performance parameters (bit jitter, asymmetry,
%               skew). Inputs are interpolated to give accuracy of about
%               +/- 1 ns. If only a single channel is desired or data is 
%               not staggered, set input dataQ to 0.
%
% Inputs:       dataI       : I channel data array
%               dataQ       : Q channel data array
%               symbRate    : symbol rate in Hz
%               fs          : sampling freq of inputs in Hz
%
% Outputs       Histograms of bit width and skew
%               Printout of bit jitter, asymmetry, and skew

%%

MidBit = mean(dataI);               % find midbit to trigger on
LowBit = min(dataI) + .2*(max(dataI)-min(dataI));    % lower values than this guaranteed to be part of a negative bit
HiBit  = max(dataI) - .2*(max(dataI)-min(dataI));    % higher values than this guaranteed to be part of a positive bit

% interpolate to get error down to about 1 ns
numInterp   = round((1/fs)/1e-9);   
dataInterpI = interp(dataI,numInterp);
if length(dataQ) > 1
    dataInterpQ = interp(dataQ,numInterp);
else
    dataInterpQ = 0;
end
fsInterp    = fs*numInterp;
QuarterBit  = round(fsInterp/symbRate/4);
HalfBit     = round(fsInterp/symbRate/2);

%% Find Positive Widths
FoundLowBit  = 0;
Found1stEdge = 0;
PosWidth     = 0;
FindSkewRise = 0;
FindSkewFall = 0;
FindSkew     = 0;
Skew         = 0;
jj           = 1;
for ii = 1:length(dataInterpI)
    %Find Low Bit
    if dataInterpI(jj) < LowBit
        FoundLowBit = 1;
    end
    if FoundLowBit == 1
        if Found1stEdge == 1
            if dataInterpI(jj) < MidBit
                TimeStamp1 = jj-1;
                PosWidth = [PosWidth (TimeStamp1 - TimeStamp0)];
                Found1stEdge = 0;
                FoundLowBit  = 0;
                TimeStamp0   = 0;
                TimeStamp1   = 0;
                FindSkewRise = 0;
                FindSkewFall = 0;
                FindSkew     = 0;
                jj           = jj + QuarterBit;
            end
        elseif dataInterpI(jj) > MidBit
            TimeStamp0   = jj;
            Found1stEdge = 1;
            jj           = jj + QuarterBit;     % jump forward to save time
        end
        
        if length(dataQ) > 1
            if Found1stEdge == 1
                if FindSkew == 0
                    if dataInterpQ(jj) < MidBit
                        FindSkewRise = 1;
                    else
                        FindSkewFall = 1;
                    end
                    FindSkew = 1;
                elseif FindSkewRise == 1
                    if dataInterpQ(jj) > MidBit
                        Skew = [Skew (jj - TimeStamp0)];
                        FindSkewRise = 0;
                    end
                elseif FindSkewFall == 1
                    if dataInterpQ(jj) < MidBit
                        Skew = [Skew (jj - TimeStamp0)];
                        FindSkewFall = 0;
                    end
                end
            end
        end
        
    end
    jj = jj + 1;
    if jj >= length(dataInterpI)
        break
    end
end

%% Find Negative Widths
FoundHiBit   = 0;
Found1stEdge = 0;
NegWidth     = 0;
jj           = 1;
for ii = 1:length(dataInterpI)
    %Find High Bit
    if dataInterpI(jj) > HiBit
        FoundHiBit = 1;
    end
    if FoundHiBit == 1
        if Found1stEdge == 1
            if dataInterpI(jj) > MidBit
                TimeStamp1 = jj;
                NegWidth = [NegWidth (TimeStamp1 - TimeStamp0)];
                Found1stEdge = 0;
                FoundHiBit   = 0;
                TimeStamp0   = 0;
                TimeStamp1   = 0;
                jj           = jj + HalfBit;
            end
        elseif dataInterpI(jj) < MidBit
            TimeStamp0   = jj-1;
            Found1stEdge = 1;
            jj           = jj + HalfBit;
        end
    end
    
    jj = jj + 1;
    if jj >= length(dataInterpI)
        break
    end
end


%% Adjust Outputs
PosWidth    = PosWidth(2:length(PosWidth)).*(1/fsInterp*1e9);
NegWidth    = NegWidth(2:length(NegWidth)).*(1/fsInterp*1e9);
Skew        = Skew(2:length(Skew)).*(1/fsInterp*1e9);
minLength   = min(length(PosWidth),length(NegWidth));
PosWidth    = PosWidth(1:minLength);
NegWidth    = NegWidth(1:minLength);

% Only want to look at single bits (get rid of strings of 1's and 0's)
realPosWidth    = 0;
realNegWidth    = 0;
realSkew        = 0;
widthThreshMax  = 1/symbRate*1e9*1.2; 
widthThreshMin  = 1/symbRate*1e9*0.8;
skewThresh      = 1/symbRate/2*1e9*1.5;
for jj = 1:length(PosWidth)
    if (PosWidth(jj) < widthThreshMax) && (PosWidth(jj) > widthThreshMin)
        realPosWidth = [realPosWidth PosWidth(jj)];
    end
    if (NegWidth(jj) < widthThreshMax) && (NegWidth(jj) > widthThreshMin)
        realNegWidth = [realNegWidth NegWidth(jj)];
    end
    if jj <= length(Skew)
        if Skew(jj) < skewThresh
            realSkew = [realSkew Skew(jj)];
        end
    end
end
PosWidth   = realPosWidth(2:length(realPosWidth));
NegWidth   = realNegWidth(2:length(realNegWidth));
Width      = [PosWidth NegWidth];
Skew       = realSkew(2:length(realSkew));

%% Calculate parameters
jitterPeak      = (max(PosWidth) - min(PosWidth) )/2;
perJitterPeak   = jitterPeak/(1/symbRate*1e9)*100;
perAsymmetry    = abs((mean(PosWidth) - mean(NegWidth))/(mean(PosWidth) + mean(NegWidth)))*100;
skewNom         = 1/symbRate/2*1e9;
skewMaxError    = max(max(Skew) - skewNom, skewNom - min(Skew)); 
perSkew         = skewMaxError/(1/symbRate*1e9)*100;

figure
numBins = ceil((max(Width) - min(Width))*fs/1e9)*2;
hist(Width,numBins)
title('Histogram of Bit Width')
xlabel('Width (ns)')
ylabel('# of Bits')

if length(dataQ) > 1
    figure
    hist(Skew,10)
    title('Histogram of Skew')
    xlabel('Skew (ns)')
    ylabel('# of Bits')
end

fprintf('\nPeak Jitter = %.3g %%\n',perJitterPeak)
fprintf('\nAsymmetry   = %.3g %%\n',perAsymmetry)
if length(dataQ) > 1
    fprintf('\nMax Skew    = %.3g %%\n\n',perSkew)
end


end