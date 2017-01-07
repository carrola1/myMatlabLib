function myPlotNTIALog(freq,amp,numAvg,SymRate,k,units)
% Designer:     Andrew Carroll
%
% Description:  Accepts frequency and amplitude (in dB) data generated from
%               myFft outptut and overlays NTIA mask. 
%
% Inputs:       freq         : frequency data in 'units'
%               amp          : corresponding amplitude data in dB
%               numAvg       : # of pts to average for myAdjDbc
%               SymRate      : symbol rate in Hz
%               k            : k for Necessary Bandwidth calculation
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
ampAdj = myAdjDbc(amp,numAvg,0);

[y,maxIndex] = max(ampAdj);
freq   = freq(maxIndex:end) - freq(maxIndex);
ampAdj = ampAdj(maxIndex:end);

%% Adjust frequency for offset as % of Necessary Bandwidth
fd = SymRate/range;
Bn = 2*k*fd;                            % Necessary Bandwidth
freq     = (freq)/Bn*100;              % Freq as % of necessary bandwidth

freq     = freq(2:length(freq));
ampAdj   = ampAdj(2:length(ampAdj));

%% Plot Data and NTIA Mask
% Create figure
figure1 = figure;


% Create axes

axes1 = axes('Parent',figure1,'XTickLabel',{'10','100','1,000'},...
    'XTick',[10 100 1000],...
    'XScale','log',...
    'XMinorTick','on');
xlim(axes1,[10 max(freq)]);
ylim(axes1,[min(ampAdj-5) max(ampAdj+5)]);
box(axes1,'on');
hold(axes1,'all');

% Plot Data
semilogx(freq,ampAdj,'red')

hold on

% Plot NTIA Mask for input K
fNTIA   = 50:.01:1000;                                        % 50-1000% of Necessary Bandwidth
NTIA    = -8 + log10(fNTIA/(50))*-40;                         % NTIA curve = -40dB/decade
semilogx([1 50 50 fNTIA 10000], [0 0 -8 NTIA -60],'g')
axis([10 10000 -80 max(ampAdj+5)])

% Plot Parameters
titleRate = sprintf([units ' Symbol Rate']);
title(['Output Spectrum - ',num2str(SymRate/range), titleRate])
xlabel('Frequency Offset as a % of the Necessary Bandwidth')
ylabel('Power (dBsd)')
legend('Spectrum Data', ['NTIA K = ',num2str(k)])
hold off
end