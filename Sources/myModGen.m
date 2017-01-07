function [t, DataOut, ModOut] = myModGen(carFreq,fs,symRate,numData,BpskQpsk,StaggerQEnb)
% Designer:     Andrew Carroll
%
% Description:  Modulates a carrier with random data. Uses cosine wave with
%               phase = 0 for in-phase reference (I channel).
%
% Inputs:       carFreq     : frequency of carrier (Hz)
%               fs          : sample rate (Hz)
%               symRate     : single channel data rate (Hz)
%               numData     : # of random symbols to generate
%               BpskQpsk    : 'BPSK' or 0 -> generate BPSK signal
%                              else       -> generate QPSK signal
%               StaggerQEnb : 1 = Stagger Q by half a symbol
%
% Outputs       t       : t (seconds)
%               ModOut  : modulated signal

%%

tstamp = 1/fs;
t      = 0:tstamp:1/symRate*numData-tstamp;

carI   = cos(2*pi*carFreq*t);
carQ   = sin(2*pi*carFreq*t);

dataI  = myGenRndData(numData,round(fs/symRate),1);
dataQ  = myGenRndData(numData,round(fs/symRate),1);

if StaggerQEnb == 1
    dataQ = [zeros(1,round((1/symRate)/tstamp/2)) dataQ(1:end - round((1/symRate)/tstamp/2))];
end

if strcmp(BpskQpsk,'BPSK') | strcmp(BpskQpsk,'Bpsk') | strcmp(BpskQpsk,'bpsk') | BpskQpsk == 0
    ModOut = carI.*dataI;
else
    ModOut = carI.*dataI + carQ.*dataQ;
end

% Normalize output
ModOut  = ModOut/max(ModOut);
DataOut = complex(dataI,dataQ);

end