function [sinOut] = myDdsSim(numPts,fs,fNCO,numBitsNCO,cordicStages,numBitsXY,numBitsAngle,fsPerJitterRMS)
% Designer:     Andrew Carroll
%
% Description:  Simulates generic Direct Digital Synthesis system. Clocks
%               an NCO with specified number of bits and uses this phase
%               word to calculate a sine value using a Coric algorithm,
%               also with specified # of bits. Outputs a representative 
%               frequency response from an ideal D/A converter.
%
% Dependecies:  myCordicRotate.m
%
% Inputs:       numPts         : # of points to simulate
%               fs             : sampling frequency in MHz
%               fNCO           : desired output frequency in MHz
%               numBitsNCO     : # of bits to use for NCO
%               cordicStages   : # of Cordic stages to use
%               numBitsXY      : # of bits to use for x and y registers of
%                                Cordic algorithm.
%               numBitsAngle   : # of bits to use for atan lookup table in
%                                Cordic algorithm.
%               fsPerJitterRMS : % RMS jitter on system clock
%               
%
% Outputs:      sin            : output calculated sine wave
%               fft plot of output

% Note:         Jitter is added to the output by adding noise to the phase
%               word. This is simpler than trying to add sampling noise
%               to the output of the DAC. It is equivalent, however, 
%               because clock jitter essentially causes you to create
%               points on a sine wave at the wrong instance in time (phase)

%% Simulate DDS

NcoMax     = 2^numBitsNCO-1;
NcoWord    = round(fNCO/fs*NcoMax);

storeNco   = ones(1,numPts);

NCO = 0;
% Add noise due to jitter
PercentJitterOut = fsPerJitterRMS/100*fNCO/fs;
JitterRadians    = PercentJitterOut*2*pi;
JitterNoise      = JitterRadians.*randn(1,numPts)*NcoMax;
for ii = 1:numPts
    NCO = NCO + NcoWord + JitterNoise(ii);
    if NCO > NcoMax
        NCO = NCO - NcoMax - 1;
    end
    NcoRad    = NCO/NcoMax*2*pi;       % convert to radians
    storeNco(ii) = NcoRad;
end

[cosOut,sinOut] = myCordicRotate(storeNco,cordicStages,numBitsXY,numBitsAngle);

%% Run Diagnostics

freqAccuracy = fs*1e6/(2^numBitsNCO - 1);
freqOut      = NcoWord/(2^numBitsNCO - 1)*fs;

fprintf('\nFreq Accuracy = %d Hz\n',freqAccuracy)
fprintf('\nFreq Output   = %d MHz\n\n',freqOut)

% Upsample by 8 so we can see full spectrum up to (fs*4)
fUpsamp   = fs*8*1e6;
DacOutput = rectpulse(sinOut,8);

[freq,amp] = myFft(DacOutput,fUpsamp,floor(log2(numPts)),'MHz',0);
ampAdj = myAdjDbc(amp,0,1);
figure
plot(freq,ampAdj) 
title('Frequency Spectrum')
xlabel('Frequency (MHz)')
ylabel('Amplitude (dBc)')
axis([0 max(freq) min(ampAdj) max(ampAdj)+5])


end

