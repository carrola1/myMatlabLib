function [rdata] = myGenRndData(n,upsamp,oneOrzero)
% Designer:     Andrew Carroll
%
% Description:  Generate array of random bits with upsampling.
%
% Inputs:       n         : # of random bits desired
%               upsamp    : # of pts per bit
%               oneOrzero : 1 = min bit -1, 0 = min bit 0
%
% Outputs       rdata     : random data out

%%
r = randi([0 1],[1 n]);
if oneOrzero == 1
    for ii = 1:length(r)
        if r(ii) == 0
            r(ii) = -1;
        end
    end
end

rdata = rectpulse(r,upsamp);

end

