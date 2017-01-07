function myPrintStats(data,bins)
% Designer:     Andrew Carroll
%
% Description:  Print statistics of input data and plot histogram.
%
% Inputs:       data  : input data set (length > 2^pow2)
%               bins  : # of bins to use for histogram
%
% Outputs       histogram

%%
numPts  = length(data);
avg     = mean(data);
sigma   = std(data);
maxdata = max(data);
mindata = min(data);

fprintf('\nNumPts = %d\n',numPts)
fprintf('Mean   = %d\n',avg)
fprintf('StdDev = %d\n',sigma)
fprintf('Max    = %d\n',maxdata)
fprintf('Min    = %d\n',mindata)

hist(data,bins)

end