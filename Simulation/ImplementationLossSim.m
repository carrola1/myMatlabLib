% Designer:     Andrew Carroll
%
% Description:  Creates a vector of random data, oversamples by 1000, adds
%               a specified percentage of asymmetry and jitter, and then
%               calculates the implementation loss compared to the original
%               vector in dB. Also outputs the predicted loss from an 
%               equation found in a paper published by ITT Industries on 
%               PN power suppression.

%% Parameters
JitterPer  = 8;              % RMS Jitter/(1/1MHz) * 100
AsymmPer   = 0;              % Percent asymmetry
numBits    = 10000;

%% Generate random data, 1MHz bit rate, 1 ns time increments
Tc      = 1000;                             % 1000 ns period (1 MHz)
data    = myGenRndData(numBits,Tc,0);
dataRef = data;

%% Apply asymmetry
asymmShift = round(abs((AsymmPer*10)/(AsymmPer/100-2)));
for ii = 1001:1000:length(data)
    if data(ii) == 1 && data(ii-1) == 0           % Detect rising edge
        data(ii-asymmShift:ii) = 1;
    end
end

%% Apply random jitter
JitterRMS  = round(JitterPer/100*1e3);            % ns rms
u          = 0;
sigma      = sqrt((JitterRMS^2)/2);               % divide sigma by 2 to divide total jitter btw 2 bit edges
                                                    % these jitters add as RSS                                                    
randJitter = round(u + sigma.*randn(numBits,1));      

jj = 1;
ii = 2;
for kk = 1:length(data)
    if data(ii) ~= data(ii-1)                     % Detect edge
        if randJitter(jj) > 0
            data(ii:ii+randJitter(jj)-1) = data(ii-1);
        elseif randJitter(jj) < 0
            data(ii+randJitter(jj):ii-1) = data(ii+1);
        end
        jj = jj + 1;
        ii = ii + 500;
    end
    ii = ii+1;
    if ii > length(data)-500
        break
    end
end

%% Trigger on rising edges and plot
figure(1)
for kk = 500:length(data)-2000
    if data(kk) == 1 && data(kk-1) == 0
        plot([zeros(1,500) data(kk:kk+1500)]);
        hold on
    end
end
axis([0 2000 -.1 1.1])
hold off

%% Find Positive Widths
prvBit = 1;
riseEdgeFound = 0;
PosWidth = 0;
for kk = 1:length(data)-2000
    if riseEdgeFound == 1
        if data(kk) == 0
            PosWidth = [PosWidth kk-timeStamp];
            riseEdgeFound = 0;
            prvBit        = 0;
        end
    elseif prvBit == 0
       if data(kk) == 1
           riseEdgeFound = 1;
           timeStamp     = kk;
       end
    else
        if data(kk) == 0
            prvBit = 0;
        end
    end
end
PosWidth = PosWidth(2:end);

%% Remove runs of '1' bits
PosWidthCorrected = 0;
for ii = 1:length(PosWidth)
    if PosWidth(ii) < 1500
        PosWidthCorrected = [PosWidthCorrected PosWidth(ii)];
    end
end

PosWidth = PosWidthCorrected(2:end);

figure(2)
hist(PosWidth,100)
MeasuredJitter = std(PosWidth-1000)


%% Calculate Implementation Loss
impLossCalc         = 20*log10(1-sum(abs(data - dataRef))/length(data)) 
impLossITT          = 20*log10(1-(asymmShift*2/Tc + sqrt(2/pi)*JitterPer/100*exp(-.5*(asymmShift*2/JitterRMS)^2)))