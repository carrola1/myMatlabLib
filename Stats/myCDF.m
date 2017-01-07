function P = myCDF(stdDev)
% Designer:     Andrew Carroll
%
% Description:  Estimate cumulative distribution function from standard deviation.
%
% Inputs:       stdDev    : standard deviation
%
% Outputs       P         : probability

%%

x = randn(10e6,1);

for ii = 1:length(x)
  if x(ii) < stdDev
    cnt = cnt + 1;
  end
end

P = cnt/length(x);

end