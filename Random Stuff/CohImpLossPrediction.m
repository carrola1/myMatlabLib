

PRec = -125;
NoRec   = -174 + 1.6 + .6;

CNo  = PRec - NoRec - 10*log10(240/221);

PTransAtten = 31:43;    % Attenuator setting
PTrans10Atten = -23.86; % TX level at attenuator = 10
PTransRange   = PTrans10Atten - (PTransAtten - 10);

ii = 0;
EbNo = zeros(1,length(PTransAtten));
for PTrans = max(PTransRange):-1:min(PTransRange)
  ii = ii + 1;
  NoTrans   = PTrans - CNo;
  No        = 10*log10((10^(-97.23/10) + 10^((NoTrans-10*log10(2.3/.1))/10)));
  EbNo(ii)  = PTrans - 10*log10(2300) - No;
end

plot(PTransRange,EbNo)