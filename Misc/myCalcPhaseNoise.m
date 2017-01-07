function [jitterTot] = myCalcPhaseNoise(carFreq,freqOffset,phaseNoise)
% Designer:     Andrew Carroll
%
% Description:  Calculate phase noise and jitter from a carrier freq
%               and phase noise data from an XO datasheet.
%
% Inputs:       carFreq     : carrier frequency in Hz
%               freqOffset  : array of offset frequencies from carrier (Hz)
%               phaseNoise  : array of phase noise values corresponding to
%                             freqOffset array in dBc
% Outputs       jitterTot   : total jitter in ps RMS
%               fprintf     : phase noise and jitter over each interval

%%
L = length(freqOffset);

powW = 10.^(phaseNoise/10);

powTot = ones(1,L-1);
radRMS = ones(1,L-1);
degRMS = ones(1,L-1);
jitter = ones(1,L-1);
for ii = 1:L-1
    powTot(ii) = (powW(ii+1) + powW(ii))/2*(freqOffset(ii+1)-freqOffset(ii));     %trapezoidal integration
    radRMS(ii) = sqrt(2*powTot(ii));
    degRMS(ii) = radRMS(ii).*180/pi;
    jitter(ii) = radRMS(ii)./(2*pi*carFreq);
end

jitterTot = sqrt(sum(jitter.^2))*1e12;           % jitter adds as root sum of squares 

fprintf('\nPhase Noise :\n')

for jj = 1:L-1
    if freqOffset(jj) <100
        fprintf('   %i to %i Hz\t\t: \t%.2g rad RMS\n', freqOffset(jj),freqOffset(jj+1),radRMS(jj))
    else
        fprintf('   %i to %i Hz\t: \t%.2g rad RMS\n', freqOffset(jj),freqOffset(jj+1),radRMS(jj))
    end
    fprintf('                 \t\t%.2g deg RMS\n',degRMS(jj))
    fprintf('                 \t\t%.3g ps\n\n',jitter(jj)*1e12)
end

fprintf('   Total RMS Jitter = %.3g ps\n\n',jitterTot)

end