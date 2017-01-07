function myTestRound(data,ExpMean)
% Designer:     Andrew Carroll
%
% Description:  Count # of data points above and below the expected mean
%               (data offset). Significant difference between outputs over
%               a # of sets of data could indicate rounding problem.
%
% Inputs:       data      : input data
%               ExpMean   : expected mean of data
%
% Outputs       NumPos    : # of data pts above ExpMean
%               NumNeg    : # of data pts below ExpMean
%               Avg       : calculated mean of data

%%
NumPos = 0;
NumNeg = 0;
for ii = 1:length(data)
    if data(ii) > ExpMean
        NumPos = NumPos + 1;
    elseif data(ii) < ExpMean
        NumNeg = NumNeg + 1;
    end
end

Avg = mean(data);

fprintf('\nNumPos = %i\n',NumPos)
fprintf('NumNeg = %i\n',NumNeg)
fprintf('Avg    = %d\n\n',Avg)

end