function myCicResp(LowRate,fs,M,N,units)
% Designer:     Andrew Carroll
%
% Description:  Plot frequency response of CIC interpolator or decimator.
%
% Inputs:       LowRate   : low data rate in Hz (input for interp, output
%                           for decimator)
%               fs        : sample rate (high rate) in Hz
%               M         : filter differential delay parameter
%               N         : # of filter stages
%               units     : 'Hz', 'kHz', 'MHz', 'GHz'
%
% Outputs       plot

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

rate = LowRate/range;
fs   = fs/range;

R = round(fs/rate);

f = (0:rate/1000:rate*10)/rate;

resp = 20*log10((sin(pi*M.*f)./sin(pi.*f/R)).^(2^N));

respNorm = resp - resp(2);

plot(f*rate,respNorm)
axis([0 rate*10 max(respNorm(end-.1*length(respNorm):end))-10 5])

xlabel(['Frequency (' units ')'])
ylabel('Power')
title(['CIC Response for Input Rate -' num2str(rate) ' ' units]) 