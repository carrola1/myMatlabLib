function [sgnNum] = myUnsgn2Sgn(unsgnNum,wordLength)
% Designer:     Andrew Carroll
%
% Description:  Re-interpret an unsigned decimal input as a signed decimal
%               #.
%
% Inputs:       unsgnNum   : decimal # to convert
%               wordLength : binary word length
%
% Outputs       sgnNum     : signed decimal output

%%

sgnNum = ones(1,length(unsgnNum));

for ii = 1:length(sgnNum)
    if unsgnNum(ii) == 2^wordLength
        sgnNum(ii) = -2^wordLength;
    elseif unsgnNum(ii) > 2^(wordLength-1) - 1
        sgnNum(ii) = unsgnNum(ii) - 2^wordLength;
    else
        sgnNum(ii) = unsgnNum(ii);
    end
end

end