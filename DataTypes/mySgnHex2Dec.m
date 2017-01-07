function [sgnNum] = mySgnHex2Dec(hexData,wordLength)
% Designer:     Andrew Carroll
%
% Description:  Convert signed hex text input to signed decimal.
%
% Inputs:       hexData    : data to convert
%               wordLength : binary word length (multiple of 4)
%
% Outputs       sgnNum     : signed decimal output

%%

unsgnNum = hex2dec(hexData);
sgnNum   = myUnsgn2Sgn(unsgnNum,wordLength);

end