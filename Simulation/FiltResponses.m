function FiltResponses

fs = 16e6;
numSamp    = 50000;
movAvgLen  = 16;
intDumpLen = 16;

%% Create chirp signal
ts = 1/fs;
t = 0:ts:ts*(numSamp-1);
sig = ones(1,length(t))*.5;
for ii = 0:fs/10000:fs/2
  sig = sig + sin(2*pi*ii*t);
end

sig = sig/length(0:.1:fs/2);


%% Moving Average
movAvg = zeros(1,length(sig)-movAvgLen);
for jj = 1:length(sig)-movAvgLen
    movAvg(jj) = sum(sig(jj:jj+movAvgLen-1))/movAvgLen;
end
[freq,amp] = myFft(movAvg,fs,40,'MHz',0);
amp = amp - max(amp);
plot(freq,amp)
ylim([min(amp)-5 max(amp)+5])
hold on

%% Integrate Dump
intCnt     = 1;
intDump    = zeros(1,length(sig));
intDump(1) = sig(1);
int        = sig(1);
for ii = 2:length(sig)
  if intCnt < intDumpLen
    intCnt      = intCnt + 1;
    int         = int + sig(ii);
    intDump(ii) = int/intDumpLen;
  else
    int         = sig(ii);
    intDump(ii) = sig(ii);
    intCnt      = 1;
  end
end
[freq,amp] = myFft(intDump,fs,40,'MHz',0);
amp = amp - max(amp);
plot(freq,amp,'r')

%% Halfband Filter
sigHb = sig*255;
hb1   = zeros(1,length(sig));
hb2   = zeros(1,length(sig));
for ii = 1:length(sig)
  [hb1(ii),~] = half_band_filter1(sigHb(ii), 10, 0, ii==1);
  [hb2(ii),~] = half_band_filter2(hb1(ii)/sqrt(2), 10, 0, ii==1);
end
[freq,amp] = myFft(hb2,fs,40,'MHz',0);
amp = amp - max(amp);
plot(freq,amp,'g')

legend('MovAvg','IntDump','HalfBand')
plot([1.5 1.5],[-65 10],'--k')
hold off

end

%% Halfband Fiter Function
function [filter_data, valid_filt] = half_band_filter2(data, data_width, decim, init) %#codegen

 % Persistent variable declarations
  persistent shift_reg;
  persistent scaled_difference;
  persistent summation;
  persistent decim_cnt

  % Persistent variable initializations
  if (init==1) || isempty(shift_reg)
    shift_reg = zeros(1,3);
    scaled_difference = 0;
    summation = zeros(1,2);
    decim_cnt = 0;
  end

  % Update the subtraction
  difference = data - summation(1);

  % Update the second summation
  summation(2) = real_signed_clamp(shift_reg(3) + summation(1), data_width+1);
  filter_data = real_signed_clamp(summation(2), data_width);

  % Update the first summation
  summation(1) = shift_reg(3) + scaled_difference;

  % Advance the shift register
  shift_reg = [data shift_reg(1:2)];

  % Apply the scaling
  scaled_difference = fix(difference/2);
  
  % Set valid_filt
  if decim==0
      valid_filt = 1;
  else
      decim_cnt = mod(decim_cnt+1,2);
      valid_filt = double(decim_cnt==0);
  end
end

function [filter_data, valid_filt] = half_band_filter1(data, data_width, decim, init) %#codegen

 % Persistent variable declarations
  persistent shift_reg;
  persistent scaled_difference;
  persistent summation;
  persistent decim_cnt

  % Persistent variable initializations
  if (init==1) || isempty(shift_reg)
    shift_reg = zeros(1,3);
    scaled_difference = 0;
    summation = zeros(1,2);
    decim_cnt = 0;
  end

  % Update the subtraction
  difference = data - summation(1);

  % Update the second summation
  summation(2) = real_signed_clamp(shift_reg(3) + summation(1), data_width+1);
  filter_data = real_signed_clamp(summation(2), data_width);

  % Update the first summation
  summation(1) = shift_reg(3) + scaled_difference;

  % Advance the shift register
  shift_reg = [data shift_reg(1:2)];

  % Apply the scaling
  scaled_difference = fix(difference/2);
  
  % Set valid_filt
  if decim==0
      valid_filt = 1;
  else
      decim_cnt = mod(decim_cnt+1,2);
      valid_filt = double(decim_cnt==0);
  end
end

