

fc       = 2e6;
fs       = 10e6;
NumSamps = 100000;
sigmaN   = 1e-4;
UpSamp   = 32;
fMod     = 1e5;

ts       = 1/fs;
t        = 0:ts:ts*(NumSamps-1);
tMod     = 1/fs*.1*sin(2*pi*fMod*t);
tJitter  = t + tMod;

sig      = sin(2*pi*fc*tJitter);


DacOut   = rectpulse(sig,UpSamp);

[freq,amp] = myFft(DacOut,fs*UpSamp,1,'MHz',1);