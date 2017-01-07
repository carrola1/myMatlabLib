function [freq, dataOut] = myFftC(data,fs,numAvg,units,plotOn)
% Designer:     Andrew Carroll
%
% Description:  Calculates and plots fft of complex input data set in dB.   
%               Does not zero pad. Dives input array up into numAvg   
%               sections and averages fft of each. Uses hann window.
%
% Inputs:       data    : input data set
%               fs      : sampling rate
%               numAvg  : number of spectrums to average (power of 2)
%               units   : string input for desired freq units on plot
%                         ('GHz','MHz','kHz','Hz')
%               plotOn  : 1 = output plot, else no plot
%
% Outputs       freq    : output freq data in specified units
%               dataOut : output fft data

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

% Protect against array of wrong dimension
CheckSize = size(data);
if CheckSize(1) > 1
    data = data';
end

L      = length(data);                  % Length of signal
pow2   = floor(log2(L)) - floor(log2(numAvg));
if pow2 < 1
    fprintf('\nError : Too many averages!\n\n')
    return
end
NFFT   = 2^pow2;
YSum   = zeros(1,NFFT);                 % sum ffts
%window = hann(NFFT);
window = ones(1,NFFT)';

for ii = 1:2^floor(log2(numAvg))
    dataWin = data((ii-1)*NFFT+1:ii*NFFT).*window';
    Y       = abs(fft(dataWin,NFFT)./NFFT);
    YSum    = YSum + Y.^2;
end
YAvg = YSum./2^floor(log2(numAvg));

% Plot double-sided amplitude spectrum.
freq    = fs/2*linspace(-1,1,NFFT+1)./range;
freq    = freq(2:end);
dataOut = 10*log10(YAvg(1:NFFT));
dataOut = fftshift(dataOut);
dataOut = flipdim(dataOut,2);
if plotOn == 1
    figure
    plot(freq,dataOut) 
    title('Frequency Spectrum')
    xlabel(['Frequency (' units ')'])
    ylabel('Amplitude (dB)')
end

end

