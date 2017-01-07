adc_rate = 25e6;
sym_rate = 100e3;
N = 1000;

ebn0 = 20;
ebn0_linear = 10^(ebn0/10);
SNR = ebn0-10*log10(adc_rate/sym_rate)

%% Signal
data = myGenRndData(N,250,1);


%% Noise
n0_Ts = 1/(ebn0_linear * (sym_rate/adc_rate));  % Eb/No = (S/N)*(fs/fd)  (Skylar, pg. 117)

% Apply noise
sigma_noise = sqrt(n0_Ts/2);        % variance = No/2 (Skylar, pg. 117)

noise = sigma_noise * randn(1,N*250);

sig = data + noise;

SNRCalc = 10*log10(1/(std(noise)^2*2))    % Noise power = sigma^2 * 2