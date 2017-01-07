function [freq, dataOut] = myFft0toFs(data,fs,numAvg,units,plotOn)
% Designer:     Andrew Carroll
%
% Description:  Calculates and plots fft of input data set in dB. Does not  
%               zero pad. Dives input array up into numAvg sections and  
%               averages fft of each. Uses hamming window.
%
% Inputs:       data    : input data set (length > 2^pow2)
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
window = hamming(length(NFFT));

for ii = 1:2^floor(log2(numAvg))
    dataWin = data((ii-1)*NFFT+1:ii*NFFT).*window;
    Y       = abs(fft(dataWin,NFFT))./NFFT;
    YSum    = YSum + Y;
end
YAvg = YSum./2^floor(log2(numAvg));

% Plot single-sided amplitude spectrum.
freq    = fs*linspace(0,1,NFFT)./range;
dataOut = 20*log10(2*YAvg(1:NFFT));
if plotOn == 1
    figure
    plot(freq,dataOut) 
    title('Frequency Spectrum')
    xlabel(['Frequency (' units ')'])
    ylabel('Amplitude (dB)')
end

end

