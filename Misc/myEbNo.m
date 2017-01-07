function dataOut = myEbNo(data,fd,fs,EbNo,SigPwr)
% Designer:     Andrew Carroll
%
% Description:  Add noise to input data for specified EbNo. Data
%               can be single sample or array. 
%
% Inputs:       data    : input data set
%               fd      : data rate (Hz)
%               fs      : sampling rate (Hz)
%               EbNo    : desired EbNo in dB
%               SigPwr  : signal power in dB
%
% Outputs       dataOut : data with noise added
%%

SNR      = 10^((EbNo + 10*log10(fd) - 10*log10(fs*.5))/10);  % S/N = Eb/No - (BW/Rate), from Sklar pg. 117
SigPLin  = 10^(SigPwr/10);
n0Var    = SigPLin/(SNR);                                 % S/N = (signal power / noise variance), from Sklar pg. 122

dataOut  = data + sqrt(n0Var)*randn(1,length(data));

end



%% You can check this code with the following :
% EbNo = 8;
% NumSeq = 50;
% pn  = myGenTdrssFwdLnkSC(65,1,1);
% err = 0;
% for ii = 1:NumSeq
%     pnN = myEbNo(pn,3e6,2.5e6,EbNo,.5);
%     err = err + length(pnN)-sum((sign(pnN).*pn+1)./2);
% end
% 
% ber = err/(length(pn)*NumSeq)
%
% Compare ber to theoretical curve. It is very close.