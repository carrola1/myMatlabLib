function [Pn] = myPnGen(pow2,fBtaps,numSequences)
% Designer:     Andrew Carroll
%
% Description:  Generates maximal length PN code of length 2^pow2-1.
%
% Inputs:       pow2         : length of PN code (2^pow2-1)
%               fBtaps       : array specifying feedback taps for linear
%                              fb shift register (i.e. for a 2^23-1 PN code fBtaps = [23 18 1], 
%                                                            2^15-1 PN code fBtaps = [15 14 1],
%                                                            2^9 -1 PN code fBtaps = [9 5 1]).
%                              
%               numSequences : # of full sequences to output into Pn array
%
% Outputs       Pn           : output PN code

reg    = ones(1,pow2);
PnTemp = zeros(1,2^pow2-1);
fBSel  = zeros(1,pow2);

for ii = 1:length(fBtaps)
    if fBtaps(ii) ~= 1
        fBSel(fBtaps(ii)) = 1;
    end
end

for ii = 1:2^pow2-1
    PnTemp(ii) = reg(pow2);
    fB         = and(reg,fBSel);
    fBXOR      = mod(sum(fB),2);
    reg        = [fBXOR reg(1:pow2-1)];
end

Pn = PnTemp;
for ii = 1:numSequences
    if ii > 1
        Pn = [Pn PnTemp];
    end
end

end

