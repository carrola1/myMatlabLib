function [binVal] = myDec2Bin(decNum,twos,wordLength,decLength,arrOrText)
% Designer:     Andrew Carroll
%
% Description:  Convert decimal input to binary. Can also input arrays.
%
% Inputs:       decNum     : decimal # to convert
%               twos       : 0 = unsigned, 1 = 2's comp
%               wordLength : binary word length
%               decLength  : number of fixed pt decimal places
%               arrOrText  : output as a matrix of 1's and 0's  (only 
%                            works for bit widths <= 16) or print out a 
%                            column of strings.
%
% Outputs       binVal     : binary word (if array was input and arrOrText
%                            = 1 then binVal = string of last input).

%%
fixedPt = fi(decNum,twos,wordLength,decLength);

if arrOrText == 0
    binVal = zeros(wordLength,length(fixedPt))';
    for ii = 1:length(fixedPt)
        temp      = str2num(bin(fixedPt(ii)));
        numDigits = numel(num2str(temp));
        binVal(ii,wordLength+1-numDigits:wordLength)  = sscanf(sprintf('%lu',temp),'%1d')';
    end
else
    for ii = 1:length(fixedPt)
        fprintf(bin(fixedPt(ii)));
        fprintf('\n');
    end
    binVal = bin(fixedPt(end));
end

end