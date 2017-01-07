function [powerOut] = myDbm2Watts(powerIn)
% Designer:     Andrew Carroll
%
% Description:  Convert dBm value to Watts.
%
% Inputs:       powerIn    : power in dBm
%
% Outputs       sgnNum     : signed decimal output

%%

powerOut = 10^(powerIn/10)/1000;

end