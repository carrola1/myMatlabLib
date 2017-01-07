function [berData] = myApplyBer(dataIn,BER,oneOrZero)
% Designer:     Andrew Carroll
%
% Description:  Apply errors to digital input vector.
%
% Inputs:       dataIn    : input data
%               BER       : desired BER
%               oneOrZero : low state is -1 or 0
%
% Outputs       berData   : data out

%%
berData = zeros(1,length(dataIn));
thresh  = myInvNormCDF(BER);

if oneOrZero == 0
  for ii = 1:length(berData)
    if randn(1,1) > thresh
      berData(ii) = not(dataIn(ii));
    else
      berData(ii) = dataIn(ii);
    end
  end
else
  for ii = 1:length(berData)
    if randn(1,1) > thresh
      berData(ii) = dataIn(ii)*-1;
    else
      berData(ii) = dataIn(ii);
    end
  end
end
    
    
end