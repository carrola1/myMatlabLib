function P = myNormCDF(stdDev,singleOrDouble)
% Designer:     Andrew Carroll
%
% Description:  Estimate cumulative distribution function from standard deviation.
%
% Inputs:       stdDev          : standard deviation
%               singleOrDouble  : single sided or double sided probability
%
% Outputs       P               : probability

%%

x = randn(5e6,1);

cnt = 0;
for ii = 1:length(x)
  if singleOrDouble == 0
    if x(ii) < stdDev
      cnt = cnt + 1;
    end
  else
    if (x(ii) < stdDev) && (x(ii) > -stdDev)
      cnt = cnt + 1;
    end
  end
end

P = cnt/length(x);

end