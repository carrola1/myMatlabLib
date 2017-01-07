function [decVal] = myBin2Dec(binStr,twos,wordLength,decLength,arrOrText)
% Designer:     Andrew Carroll
%
% Description:  Convert binary string input to decimal. If you want to
%               enter an array of values, put in the format: 
%               ['binStr1' ; 'binStr2' ; ...]
%
%               If you want to enter a matrix, make each row a binary
%               value of 1's and 0's.
%
% Inputs:       binStr     : binary string to convert
%               twos       : 0 = unsigned, 1 = 2's comp
%               wordLength : binary word length
%               decLength  : number of fixed pt decimal places
%               arrOrText  : specify if an array or string is being input
%
% Outputs       decVal     : binary word as string

%%
if arrOrText == 0
    numValues = size(binStr);
    binStr    = num2str(binStr);
    binStrNew = regexprep(binStr(1,:),'[^\w'']','');
    for ii = 2:numValues(1)
        binStrNew = [binStrNew;regexprep(binStr(ii,:),'[^\w'']','')];
    end
    binStr = binStrNew;
end

unsgnd  = bin2dec(binStr);
sgnd    = zeros(1,length(unsgnd));

for ii = 1:length(unsgnd)
    if twos == 1
        if unsgnd(ii) > 2^(wordLength-1)-1
            sgnd(ii) = unsgnd(ii) - 2^wordLength;
        else
            sgnd(ii) = unsgnd(ii);
        end
    else
        sgnd(ii) = unsgnd(ii);
    end
    
    if decLength ~= 0
        sgnd(ii) = sgnd(ii)/2^decLength;
    end
end
    

decVal = sgnd;

end