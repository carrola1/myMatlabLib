function [adjData] = myAdjDbc(data,numAvg,singleOrDouble)
% Designer:     Andrew Carroll
%
% Description:  Offset fft data in dB to be referenced to 0 dBm at carrier.
%               Need to input # of points to average to locate carrier
%               depending on width of carrier.
%
% Inputs:       data         : input fft data in dB
%               numAvg       : # of pts to average for offset
%               singleOrDbl  : 0 = single-sided spectrum, 1 = double
%
% Outputs       adjdata      : adjusted data

%%
if singleOrDouble == 0
    carrierPwr = mean(data(1:numAvg));
else
    [maxVal,maxIndex] = max(data);   
    carrierPwr = mean(data(maxIndex - round(numAvg/2):maxIndex + round(numAvg/2)));
end

adjData = data - carrierPwr;

end

