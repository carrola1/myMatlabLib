function endAddr = myAlphabetIncr(startLetter,numIncr)
% Designer:     Andrew Carroll
%
% Description:  Takes a starting column letter (referring to excel) and 
%               increments that letter by numIncr times. Works up to 
%               ZZZ.
%
% Inputs:       startLetter    : starting column ('A')
%               numIncr        : # of letters to increment
%
% Outputs       endAddr        : string containing end column ('AZB')

%%
ASCII_1    = double(startLetter) - 64;
ASCII_2    = 1;
ASCII_3    = 1;
endLetter  = ASCII_1 + numIncr - 1;

if endLetter <= 25
    endAddr = char(endLetter+65);
elseif endLetter <= 675
    for ii = 1:endLetter
        ASCII_1 = ASCII_1 + 1;
        if ASCII_1 == 27
            ASCII_1 = 1;
            ASCII_2  = ASCII_2 + 1;
        end
    end
    endAddr = [char(ASCII_2+64) char(ASCII_1+64)];
else
    for ii = 1:endLetter
        ASCII_1 = ASCII_1 + 1;
        if ASCII_1 == 27
            ASCII_1 = 1;
            ASCII_2  = ASCII_2 + 1;
            if ASCII_2 == 27
                ASCII_2 = 1;
                ASCII_3 = ASCII_3 + 1;
            end
        end
        endAddr = [char(ASCII_3+63) char(ASCII_2+64) char(ASCII_1+64)];
    end
end

end
