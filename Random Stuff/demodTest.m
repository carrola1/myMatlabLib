

phaseOffset = 3*pi/2;

carFreq = 1e6;
symRate = 100e3;
fs      = carFreq*10;
numData = 100;

N     = 50;
Fpass = .1;
Fstop = .2;
h = fdesign.lowpass('n,fp,fst', N, Fpass, Fstop);
Hd = design(h,'equiripple','StopbandShape','flat');
taps = Hd.Numerator(:);

%% Modulate
tstamp = 1/fs;
t      = 0:tstamp:1/symRate*numData-tstamp;

carI   = sin(2*pi*carFreq*t + phaseOffset);
carQ   = cos(2*pi*carFreq*t + phaseOffset);

dataI  = myGenRndData(numData,round(fs/symRate),1);
dataQ  = myGenRndData(numData,round(fs/symRate),1);

dataQ = [zeros(1,round((1/symRate)/tstamp/2)) dataQ(1:end - round((1/symRate)/tstamp/2))];

modOut = carI.*dataI + carQ.*dataQ;

% Normalize output
modOut  = modOut/max(modOut);
dataOut = complex(dataI,dataQ);

%% Demod
refI        = cos(2*pi*carFreq*t);
refQ        = sin(2*pi*carFreq*t);

demodI      = refI.*modOut;
demodQ      = refQ.*modOut;

demodIFilt  = filter(taps,1,demodI);
demodQFilt  = filter(taps,1,demodQ);


%% Plot
figure(1)
subplot(4,1,1), plot(demodIFilt,'r')
hold on
plot([zeros(1,25) real(dataOut)*.5],'b')
hold off
ylim([-.6 .6])
xlim([100 3000])
title('I Data, I Demod')

subplot(4,1,2), plot(demodQFilt,'r')
hold on
plot([zeros(1,25) real(dataOut)*.5],'b')
hold off
ylim([-.6 .6])
xlim([100 3000])
title('I Data, Q Demod')

subplot(4,1,3), plot(demodIFilt,'r')
hold on
plot([zeros(1,25) imag(dataOut)*.5],'b')
hold off
ylim([-.6 .6])
xlim([100 3000])
title('Q Data, I Demod')

subplot(4,1,4), plot(demodQFilt,'r')
hold on
plot([zeros(1,25) imag(dataOut)*.5],'b')
hold off
ylim([-.6 .6])
xlim([100 3000])
title('Q Data, Q Demod')

figure(2)
plot([zeros(1,25) real(dataOut)*.5]+1.2,'c')
hold on
plot([zeros(1,25) imag(dataOut)*.5],'g')
legend('I','Q')
xlim([0 1000])
ylim([-.6 2])
hold off


