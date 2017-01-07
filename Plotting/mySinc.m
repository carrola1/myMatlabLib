function [freq, sincOut] = mySinc(dataRate,units)
% Designer:     Andrew Carroll
%
% Description:  Output sin(x)/x for given data rate
%
% Inputs:       dataRate  : data rate in Hz
%               units     : 'Hz', 'kHz', 'MHz', 'GHz'
%
% Outputs       freq      : frequency axis
%               sincOut   : sin(x)/x data

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

w       = [0:pi/200:25*pi];
sinx    = sin(w)./(w);
freq    = w*(dataRate/range/pi);
freq    = freq(2:length(freq));
sincOut = 10*log10(sinx.^2);
sincOut = sincOut(2:length(sincOut));

% cap off at -70 dB
for ii = 1:length(sincOut)
    if sincOut(ii) < -70
        sincOut(ii) = -70;
    end
end


end