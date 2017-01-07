

noAtten   = -20;            % power with 0 dB attenuation
range     = -120:1.0:-50;   % power range to sweep over (dBm)
pauseTime = 5;              % dwell time in (s)

atten = range - noAtten;

fprintf('\n')
for ii = 1:length(atten)
  fprintf('SAR1 %d\n',abs(atten(ii)))
  fprintf('PAUSE%iS\n',pauseTime)
end