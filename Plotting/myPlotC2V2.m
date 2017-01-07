function myPlotC2V2(freq,amp,numAvg,SymRate,units,singleOrDouble)
% Designer:     Andrew Carroll
%
% Description:  Accepts frequency and amplitude (in dB) data generated from
%               myFft outptut and overlays C2V2 mask. 
%
% Inputs:       freq         : frequency data in 'units'
%               amp          : corresponding amplitude data in dB
%               numAvg       : # of pts to average for myAdjDbc
%               SymRate      : symbol rate in Hz
%               units        : string input to specify freq units of input
%                              ('GHz','MHz','kHz','Hz')
%
% Outputs:      Plot
%
%%

if strcmp(units,'GHz')
    range  = 1e9;
elseif strcmp(units,'MHz')
    range  = 1e6;
elseif strcmp(units,'kHz')
    range  = 1e3;
elseif strcmp(units,'Hz')
    range  = 1e0; 
else
    fprintf('Error : Invalid units input\n')
    return
end

%% Adjust Plot
ampAdj = myAdjDbc(amp,numAvg,singleOrDouble);

[y,maxIndex] = max(ampAdj);
freq   = freq(maxIndex:end) - freq(maxIndex);
ampAdj = ampAdj(maxIndex:end);

%% Adjust frequency for offset as % of Necessary Bandwidth
fd = SymRate/range;
Bn = 2*fd;                             % Necessary Bandwidth
freq     = (freq)/Bn*100;              % Freq as % of necessary bandwidth

freq     = freq(2:length(freq));
ampAdj   = ampAdj(2:length(ampAdj));

%% Plot Data and NTIA Mask
% Create figure
figure1 = figure;

% Create axes
plot(freq,ampAdj,'red')
hold on

% Plot C2V2 Mask for input K
fMask     = (50:.1:833);                                         % 50-833% of Necessary Bandwidth
dBperDec  = -67.120961000956981;                                 % Calculation commented out below
Mask      = -8 + log10(fMask/(50))*dBperDec;                     % Mask
plot([0 50 50 fMask], [0 0 -8 Mask],'b')

axis([0 500 -80 10]);

% Plot Parameters
titleRate = sprintf([units ' Symbol Rate']);
title(['Output Spectrum - ',num2str(SymRate/range), titleRate])
xlabel('Frequency Offset as a % of the Necessary Bandwidth')
ylabel('Power (dBsd)')
legend('Spectrum Data', 'C2V2 Mask')
hold off
end