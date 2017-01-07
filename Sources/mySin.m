function [SinOut] = mySin(fSin,fs,numPeriods,phase)
% Designer:     Andrew Carroll
%
% Description:  Generate sine wave at sampling rate fs.
%
% Inputs:       fSin         : frequency of sine wave (Hz)
%               fs           : sample rate (Hz)
%               numPeriods   : # of sine wave periods to generate (starts
%                              with 0, ends with 0).
%               phase        : start phase (rad)
%
% Outputs       SinOut       : output sine wave

%%

numPoints = round(fs/(fSin/numPeriods));

t = 0:1/fs:1/fs*numPoints;

SinOut = sin(2*pi*fSin*t + phase);

end