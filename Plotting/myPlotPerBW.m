function myPlotPerBW(freq,amp,perBW,numAvg,SymRate,units)
% Designer:     Andrew Carroll
%
% Description:  Accepts frequency and amplitude (in dB) data generated from
%               myFft outptut and calculates perBW % bandwidth. 
%
% Inputs:       freq         : frequency data in 'units'
%               amp          : corresponding amplitude data in dB
%               perBW        : desired %BW to be calculated in %
%               numAvg       : # of pts to average for myAdjDbc
%               SymRate      : symbol rate in 'units'
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

amp = myAdjDbc(amp,numAvg,0);

%%
% Only look at first 12 lobes
maxFreq  = SymRate*12;
maxIndex = length(freq);
for ii = 1:length(freq)
    if freq(ii) > maxFreq
        maxIndex = ii;
        break
    end
end
freq   = freq(1:maxIndex);
amp    = amp(1:maxIndex);

ampLin = 10.^(amp/20);              % un-loggify

areaTot   = trapz(ampLin.^2);       % integrate power of 1st 12 lobes
areaPerBW = perBW/100*areaTot;      % perBW of total energy

% Find bandwidth at which perBW energy is located
areaInt    = 0;
perBWIndex = 0;
for jj = 1:length(ampLin)
    if  areaInt < areaPerBW
        areaInt = trapz(ampLin(1:jj).^2);
    else
        perBWIndex = jj;
        break
    end
end

fourLobes = round(maxIndex/2);
figure1 = figure;
plot(freq(1:fourLobes),amp(1:fourLobes),'r')
hold on
axis([0 freq(fourLobes) min(amp(1:fourLobes))-8 max(amp(1:fourLobes))+2])
area(freq(1:perBWIndex),amp(1:perBWIndex),min(amp(1:fourLobes))-8)
titleRate = sprintf([units ' Symbol Rate']);
title(['Output Spectrum - ',num2str(SymRate), titleRate])
xlabel(['Frequency (' units ')'])
ylabel('Power (dBc)')

% Create textbox
textBoxStrg = sprintf([num2str(perBW) '%% BW = %.4g ' units],freq(perBWIndex));
annotation(figure1,'textbox',[0.5489 0.6468 0.45 0.135],...
    'String',{textBoxStrg},...
    'FitBoxToText','on');

hold off





end