function [resampX,resampY] = myResample(oldXVals,oldYVals,newXVals)
% Designer:     Andrew Carroll
%
% Description:  Resample input to new x values.
%
% Inputs:       oldXVals  : original x-axis values
%               oldYVals  : original y-axis values
%               newXVals  : desired x-axis values
%
% Outputs       resampX   : resampled x values
%               resampY   : resampled y values

%%
resampY = spline(oldXVals,oldYVals,newXVals);
resampX = newXVals;

end