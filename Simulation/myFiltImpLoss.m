function [impLoss] = myFiltImpLoss(Hd,fs,fd)
% Designer:     Andrew Carroll
%
% Description:  Find implementation loss of filter object. Only integrates energy out
%               to fs/2.
%
% Inputs:       Hd        : filter object (generated from Filter Builder or FDA)
%               fs        : sample rate (Hz)
%               fd        : data rate (Hz)
%
% Outputs       imploss   : implementation loss of filter in dB

%% Find Energy Under Sinc Function
[freq,sinc] = mySinc(fd,'Hz');

for ii = 1:length(freq)
  if freq(ii) > fs/2
    compFreqIndex = ii-1;
    break
  end
end

sinc       = sinc(1:compFreqIndex);
sincLin    = 10.^(sinc/10);
sincFreq   = freq(1:compFreqIndex);

sincEnergy = trapz(sincFreq,sincLin);

%% Find Energy Under Filtered Response
[H,F] = freqz(Hd,length(sincFreq),fs);

testFiltMag = 20*log10(abs(H)) + 20*log10(sincLin)';
testFiltLin = 10.^(testFiltMag/20);

filteredEnergy = trapz(F,testFiltLin);


%% Compare
impLoss = 20*log10(filteredEnergy/sincEnergy);

end