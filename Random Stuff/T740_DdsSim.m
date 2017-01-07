%% T-740 DDS Clock Analysis

%% Setup
close all

%% Parameters
fs        = 50e6;     % sampling freq (Hz)
fclk      = 10.13e6;  % generated clock freq (Hz)
numPts    = 1e5;
upsamp    = 50;
jitterRMS = .001*1/50e6;   % Add .1% RMS jitter to system clock

fc     = 15e6;
wcN    = fc/(fs*upsamp/2);
n      = 1;

%% Generate Digital, 10-bit Sine Wave
t      = 0:1/fs:1/fs*(numPts-1);
tJit   = t + jitterRMS*randn(1,length(t));      % Add Jitter
digSig = double(fi(sin(2*pi*fclk*tJit),1,10,9));

%% Sample and Hold
dacOut = rectpulse(digSig,upsamp);

%% Filter and Calc Jitter
jitterPeakStore = zeros(1,6);
dacStore        = zeros(6,length(dacOut));
for n = 0:5
  if n == 0
    [b,a] = butter(1,.4);             % No filter
    dacFilt = filter(b,a,dacOut);
  else
    [b,a] = butter(n,wcN);
    dacFilt = filter(b,a,dacOut);
  end
  dacStore(n+1,:) = dacFilt;

  % Find Jitter
  lowFound   = 0;
  rise1Found = 0;
  perStore   = 0;
  jj         = 1;
  for ii = 1:length(dacFilt)
    if (dacFilt(jj) < 0) && (lowFound == 0) 
      lowFound  = 1;
      jj        = jj + floor((fs*upsamp)/fclk/4);    % jump to next peak to avoid noise (hysteresis)
    elseif (dacFilt(jj) > 0) && (lowFound == 1)
      if rise1Found == 0
        tstampRise1 = jj;
        lowFound    = 0;
        rise1Found  = 1;
        jj          = jj + floor((fs*upsamp)/fclk/4);    % jump to next peak to avoid noise (hysteresis)
      else
        newPer      = jj - tstampRise1;
        perStore    = [perStore newPer];
        rise1Found  = 0;
        lowFound    = 0;
        jj          = jj + floor((fs*upsamp)/fclk/4);    % jump to next peak to avoid noise (hysteresis)
      end
    end
    jj = jj + 1;
    if jj>length(dacFilt)
      break
    end
  end
  perStore = perStore(2:end);
  perStore = perStore*(1/(fs*upsamp));

  jitterPeak           = (max(perStore) - min(perStore))/2;
  jitterPeakStore(n+1) = jitterPeak*1e9;                      % peak jitter in (ns)
    
end
jitterPeakStore
  
%% Plot
[freqDac,ampDac]   = myFft(dacStore(1,:),fs*upsamp,200,'MHz',0);
[freqFilt,ampFilt] = myFft(dacStore(4,:),fs*upsamp,200,'MHz',0);

plot(freqDac,ampDac)
hold on
plot(freqFilt,ampFilt,'r')
xlim([0 150])
ylim([-200 0])
xlabel('Frequency (MHz)')
ylabel('Amplitude (dB)')
title('Freq Response of Reconstruction Filter Output')
legend('No Filter', '3 Pole Filter')
hold off

figure
t = (0:1/(fs*upsamp):1/(fs*upsamp)*(1000-1)) * 1e9;
plot(t,dacStore(1,1:1000))
hold on
plot(t,dacStore(2,1:1000),'g')
plot(t,dacStore(4,1:1000),'r')
xlabel('Time (ns)')
ylabel('Amplitude')
title('Filtered DAC Output')
legend('No Filter', '1 Pole Filter', '3 Pole Filter')
hold off



