function [data] = myGenSqWave(n,upsamp,oneOrzero)
% Designer:     Andrew Carroll
%
% Description:  Generate square wave with upsampling.
%
% Inputs:       n         : # of random bits desired
%               upsamp    : # of pts per bit
%               oneOrzero : 1 = min bit -1, 0 = min bit 0
%
% Outputs       data      : data out

%%
d   = ones(1,n);
alt = 1;
for ii = 1:n
    if alt == 1
        d(ii) = 0;
    end
    alt = not(alt);
end
if oneOrzero == 1
    for ii = 1:length(d)
        if d(ii) == 0
            d(ii) = -1;
        end
    end
end

data = rectpulse(d,upsamp);

end

