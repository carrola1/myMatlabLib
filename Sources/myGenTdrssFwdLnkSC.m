function [SC] = myGenTdrssFwdLnkSC(userCode,upSamp,zeroOne)
% Designer:     Andrew Carroll
%
% Description:  Generate TDRSS forward link short code (forward from TDRSS perspective)
%
% Inputs:       userCode  : Select User Code 1-85
%               upsamp    : # of pts per chip
%               zeroOne   : 0 = min bit 0, 1 = min bit -1
%
% Outputs       SC        : Short code out

%%

% TDRSS Forward Link Command Channel Initial Conditions RegisterA
% User Codes 1 - 85 (From STDN No. 1)
IcRegA_Arr = {  '1010011'; '0110011'; '1100000'; '0010000'; '1010000'; ...
                '0110000'; '1110000'; '0001000'; '1001000'; '0101000'; ...
                '1001011'; '0011000'; '0101011'; '0011011'; '1111000'; ...
                '1011011'; '0111011'; '0100100'; '1111011'; '0000111'; ...
                '1010100'; '1000111'; '0100111'; '0001100'; '1001100'; ...
                '0101100'; '0010111'; '0011100'; '1011100'; '0111100'; ...
                '0110111'; '0000010'; '1000010'; '0100010'; '1100010'; ...
                '1110111'; '1010010'; '0001111'; '1110010'; '0001010'; ...
                '1001010'; '0101111'; '1101010'; '0011010'; '1101111'; ...
                '0011111'; '1011111'; '1111111'; '1000110'; '0110101'; ...
                '1110101'; '0010110'; '0001101'; '0110110'; '1101101'; ...
                '0001110'; '0011101'; '0101110'; '1101110'; '1011101'; ...
                '1011110'; '0111110'; '1111110'; '0000001'; '1000001'; ...
                '1111101'; '1100001'; '0010001'; '0000011'; '0110001'; ...
                '1110001'; '0001001'; '1000011'; '0100011'; '1101001'; ...
                '0011001'; '1011001'; '0111001'; '1111001'; '0000101'; ...
                '1000101'; '1100011'; '1100101'; '0010011'; '1010101'};
            
            
IcRegA_BinExpanded = sprintf(['00' char(IcRegA_Arr(userCode)) '0']);
IcRegA_Bin = fliplr(IcRegA_BinExpanded);
IcRegA_Dec = bin2dec(IcRegA_Bin);

IcRegB_Bin = '1001001000';          % Always the same
IcRegB_Bin = fliplr(IcRegB_Bin);
IcRegB_Dec = bin2dec(IcRegB_Bin);

ScLength = 1023;

% This is the reference short code
ScRef = zeros(1,ScLength);
RegA = IcRegA_Dec;
RegB = IcRegB_Dec;
for ii = (1:ScLength)
    
    RegAFb=bitget(RegA,2)+bitget(RegA,3)+bitget(RegA,6)+bitget(RegA,8)+bitget(RegA,9)+bitget(RegA,10);
    RegBFb=bitget(RegB,3)+bitget(RegB,10);  

    ScOut = bitxor(bitget(RegA,10),bitget(RegB,10));
    
    % Left Shift & shift xor into lsb
    RegA = bitshift(RegA,1) + ~~mod(RegAFb,2); %add 1 if feedback is odd
    if RegA > 2^10-1
        RegA = RegA - 2^10;
    end
    RegB = bitshift(RegB,1) + ~~mod(RegBFb,2); %add 1 if feedback is odd
    if RegB > 2^10-1
        RegB = RegB - 2^10;
    end
    
    % Set logic high, logic low levels
    if zeroOne == 0
        ScRef(ii) = ScOut;
    else
        if (ScOut == 0)
            ScRef(ii) = -1;
        else
            ScRef(ii) = 1;
        end
    end
end

SC = rectpulse(ScRef,upSamp);

end


