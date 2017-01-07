function [fOut, pwrOut] = myPlotSigPwr(data,fs)
% Designer:     Andrew Carroll
%
% Description:  Plot the mean square power of a signal. Also print the
%               average power of the signal.
%
% Inputs:       data    : input data set
%               fs      : sampling rate (Hz)
%
% Outputs       plot    

%%

X   = fft(data);
X   = X(1:floor(length(X)/2)+1); %one-sided DFT

P          = (abs(X)/length(data)).^2;
P(2:end-1) = 2*P(2:end-1);

Hmss=dspdata.msspectrum(P,'Fs',fs,'spectrumtype','onesided');

plot(Hmss)

h      = spectrum.periodogram('hamming');
sigPSD = psd(h,data,'Fs',fs);

avgPwr = avgpower(sigPSD);

fprintf('\nAverage Power = %d W, %d dB\n\n', avgPwr,10*log10(avgPwr))

fOut = Hmss.Frequencies;
pwrOut = 10*log10(Hmss.Data);

end