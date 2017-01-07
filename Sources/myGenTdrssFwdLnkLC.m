function [LC] = myGenTdrssFwdLnkLC(userCode,upSamp,zeroOne)
% Designer:     Andrew Carroll
%
% Description:  Generate TDRSS forward link long code (forward from TDRSS perspective)
%
% Inputs:       userCode  : Select User Code 1-85
%               upsamp    : # of pts per chip
%               zeroOne   : 0 = min bit 0, 1 = min bit -1
%
% Outputs       LC        : Long code out

%%

% TDRSS Forward Link Range Channel Feedback Taps
% User Codes 1 - 85 (From STDN No. 1)
FbTaps_Arr = {  '100001001000000010'; '100001001000001011'; '100001001000010110'; '100001001000101100';... 
                '100001001000110010'; '100001001001001010'; '100001001001100100'; '100001001010010001';... 
                '100001001010011000'; '100001001011001000'; '100001001100010010'; '100001001100100001';... 
                '100001001100100100'; '100001001101001000'; '100001001110000010'; '100001010000000111';... 
                '100001010000001011'; '100001010000011001'; '100001010000011010'; '100001010001100010';... 
                '100001010100100010'; '100001010100110000'; '100001011000001001'; '100001011000010001';... 
                '100001011000011000'; '100001100000110010'; '100001100000111000'; '100001100001000110';... 
                '100001100001100001'; '100001100001100100'; '100001100001101000'; '100001100001110000';... 
                '100001100010000011'; '100001110000000101'; '100001110000010100'; '100001110000100010';... 
                '100001110100001000'; '100010000000010001'; '100010000000010100'; '100010000000100111';... 
                '100010000001000010'; '100010000001010011'; '100010000001111000'; '100010000010011001';... 
                '100010000010011010'; '100010000010110010'; '100010000011010010'; '100010000011101000';... 
                '100010000100000100'; '100010000100001110'; '100010000101000011'; '100010000101001010';... 
                '100010000110001001'; '100010000110010010'; '100010000110010100'; '100010000110100010';... 
                '101000000010010000'; '111010000010010000'; '101101000010010000'; '100110100010010000';... 
                '101001100010010000'; '101010010010010000'; '100100110010010000'; '110001001010010000';... 
                '100011001010010000'; '100010011010010000'; '101001000110010000'; '110000100110010000';... 
                '100100100110010000'; '100010010110010000'; '101000001110010000'; '111100000001010000';... 
                '111010000001010000'; '110011000001010000'; '101011000001010000'; '101000110001010000';... 
                '101000100101010000'; '100001100101010000'; '110010000011010000'; '110001000011010000';... 
                '100011000011010000'; '101001100000110000'; '100011100000110000'; '101100010000110000';... 
                '110000110000110000'};
            
FbTapsBin   = fliplr(FbTaps_Arr(userCode));
FbTapsDec   = bin2dec(FbTapsBin);

LcLength = 261888;  % 256*(2^10-1) for truncated long code

% This is the reference short code
LcRef = zeros(1,LcLength);
PnReg = 2^18-1;     % Initialize to all 1's

for ii = (1:LcLength)
    
    PnRegFb = 0;
    for jj = 1:18
      if bitget(FbTapsDec,jj) == 1
        PnRegFb = PnRegFb + bitget(PnReg,jj);
      end
    end
    
    LcOut = bitget(PnReg,18);
    
    % Left Shift & shift xor into lsb
    PnReg = bitshift(PnReg,1,18) + ~~mod(PnRegFb,2); %add 1 if feedback is odd
    
    % Set logic high, logic low levels
    if zeroOne == 0
        LcRef(ii) = LcOut;
    else
        if (LcOut == 0)
            LcRef(ii) = -1;
        else
            LcRef(ii) = 1;
        end
    end
end

LC = rectpulse(LcRef,upSamp);

end

