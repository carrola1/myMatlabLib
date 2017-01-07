function myCompAging(TimeData,TimeNew,TempData,TempNew,ToleranceData,component)
% Designer:     Andrew Carroll
%
% Description:  Uses Arrhenius equation to adjust aging data at a specified
%               temperature and length of time to a new temperature and
%               length of time. Function works for M resistors and
%               CDR/CWR capacitors.
%
% Inputs:       TimeData      : Amount of time used for aging data (hours)
%               TimeNew       : Amount of time to adjust to (hours)
%               TempData      : Temp that data was taken for (deg C)
%               TempNew       : Temp to adjust to (deg C)
%               ToleranceData : Tolerance data after aging (%)
%               component     : 'R' = resistor, 'CDR' = CDR capacitor, 
%                               'CWR' = CWR capacitor
%
% Outputs       Prints new tolerance in %

%%

% Activation energies for different components
% FromAEi Systems WCCA Workshop 2009
if strcmp(component,'R')
    Ea  = 1.35;
elseif strcmp(component,'CDR')
    Ea  = 1.67;
elseif strcmp(component,'CWR')
    Ea  = .43;
end

% Convert temp to Kelvin
tempData = TempData + 273;
tempNew  = TempNew  + 273;

% Convert time to years
timeData = TimeData/24/365;
timeNew  = TimeNew/24/365;

tolData  = ToleranceData/100;

k = 8.6173423e-5;                  % Boltzmann's constant (eV/K)

Multiplier = (timeNew/timeData)*2.718281828459045^(Ea/k*((1/tempData)-(1/tempNew)));               
                
newTol     = tolData*Multiplier*100;

fprintf('\nNew Tolerance = %.4g%%\n\n',newTol)


end