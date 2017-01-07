function sigOut = myGenSigPlusNoise(Fs,Fc,Fd,NBW,NumData,SNR,Mod)
% Designer:     Andrew Carroll
%
% Description:  Generates BPSK/QPSK signal with amplitude of +/- 1 and
%               adds noise for desired SNR. Gives flat noise floor over
%               sampling BW. External filtering to NBW will give correct
%               specified SNR.
%
% Inputs:       Fs      : sampling frequency (Hz)
%               Fc      : carrier frequency (Hz)
%               Fd      : symbol rate (Hz)
%               NumData : number of symbols to generate
%               NBW     : noise bandwidth (Hz)
%               SNR     : SNR in dB
%               Mod     : 'BPSK' or 'QPSK'
%
% Outputs:      sigOut  : output

t = 0:1/Fs:1/Fs*(Fs/Fd*NumData-1);

dataI = myGenRndData(NumData,Fs/Fd,1);
dataQ = myGenRndData(NumData,Fs/Fd,1);

if strcmpi(Mod,'BPSK')
    sig = sin(2*pi*Fc*t).*dataI;
else
    sig = cos(2*pi*Fc*t).*dataI + sin(2*pi*Fc*t).*dataQ;
    sig = sig * (sqrt(2)/2);
end

sigPwr   = 10;   % .7071 V RMS = 10 dBm
noisePwr = sigPwr - SNR - 10*log10(Fs/(Fs/2)) + 10*log10((Fs/2)/NBW);  % Noise should be spread over sampling BW
noise    = wgn(1,length(sig),noisePwr,50,'dBm');

sigOut = sig + noise;

