function myPlotSFCG(freq,amp,numAvg,SymRate,units)
% Designer:     Andrew Carroll
%
% Description:  Accepts frequency and amplitude (in dB) data generated from
%               myFft outptut and overlays SFCG mask. Chooses between 2
%               SFCG masks based on data rate (>2MSPS uses stricter mask). 
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
ampAdj = myAdjDbc(amp,numAvg,0);

[y,maxIndex] = max(ampAdj);
freq   = freq(maxIndex:end) - freq(maxIndex);
ampAdj = ampAdj(maxIndex:end);

freq   = freq/(SymRate/range);     % Freq as off-carrier to sym rate ratio

figure
plot(freq,ampAdj,'red')
hold on
if SymRate >= 2e6
    plot([0 .5 1.4 3 5 9], [0 0 -30 -60 -60 -60],'g')
else
    plot([0 .5 3 8 9], [0 0 -30 -60 -60],'g')
end
axis([0 9 -80 10]);

% Plot Parameters
titleRate = sprintf([units ' Symbol Rate']);
title(['Output Spectrum - ',num2str(SymRate/range), titleRate])
xlabel(['Frequency-off-carrier to Symbol Rate Ratio (F/Rs)'])
ylabel('Power (dBsd)')
if SymRate >= 2e6
    legend('Spectrum Data', ['SFCG Mask (>2MSPS)'])
else
    legend('Spectrum Data', ['SFCG Mask (<2MSPS)'])
end
hold off

end