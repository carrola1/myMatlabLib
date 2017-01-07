function myCalcAcCoupling(bitRate_Hz,loadR_ohm,numConsBits,riseTime_ps)
% Designer:     Andrew Carroll
%
% Description:  Calculates best CDR capacitor value for AC coupling based
%               on lowest pattern dependent jitter (series of same bits
%               causes low-frequency droop, which leads to jitter). See
%               Maxim "Choosing AC-Coupling Capacitors" app note for more
%               information.
%
% Inputs:       bitRate     : frequency of data/clock in Hz
%               loadR       : load resistance in ohms
%               numConsBits : max # of consecutive, identical bits
%               riseTime    : 20% to 80% rise time in ps
%               
% Outputs:      Prints good value of CDR ceramic capcitor for coupling

%%

load Capacitors_CDR.dat;
caps = Capacitors_CDR;

N  = length(caps);
Tb = 1/bitRate_Hz;
riseTime = riseTime_ps/1e12;
e  = 2.71828183;

standValue = 7.8*numConsBits*Tb/loadR_ohm*1e12;

% Find closest CDR
diff = 1000000;
for ii = 1:length(caps)
    if abs(caps(ii) - standValue) < diff
        closestMatch = caps(ii);
        diff         = abs(caps(ii) - standValue);
    end
end
standValue = closestMatch;
PDJ_standValue = .5*riseTime*(1 - e^(-Tb*numConsBits/loadR_ohm/(standValue/1e12)))/.6;


% Calc PDJ for all caps
PDJ = zeros(1,N);
for ii = 1:N
    PDJ(ii) = .5*riseTime*(1 - e^(-Tb*numConsBits/loadR_ohm/(caps(ii)/1e12)))/.6;
end

[minPDJ,minIndex] = min(PDJ);

fprintf('\nGood Starting CDR Capacitor is %g pF\n\n',standValue);
fprintf('This gives you PDJ = %g ps\n\n',PDJ_standValue*1e12);


end