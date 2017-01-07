function myResPar(ResArr)
% Designer:     Andrew Carroll
%
% Description:  Calculate equivalent parallel resistance from array of
%               resistor values.
%
% Inputs:       ResArr    : Array of resistor values

%%

ParRes = 1/sum(1./ResArr);
    
fprintf('\n%2.2g ohms\n\n',ParRes);        


end