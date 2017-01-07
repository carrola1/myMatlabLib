
function myDdsSpurCalc(A,P,fout,fsamp)
% Designer:     Andrew Carroll
%
% Description:  Calculate spurs in a DDS system caused from phase
%               truncation
%
% Inputs:       A       : Phase accumulator size (A bits)
%               P       : Phase word size (P bits), # of bits after
%                         truncation used to calculate output waveform.
%               fout    : DDS output frequency (Hz)
%               fsamp   : sampling frequency (Hz)

T = round(2^A*(fsamp/fout));

maxSpurLevel = -6.02*P;

GRR = 2^A / gcd(T,2^A);     % Grand Repetition Rate (# of clock cycles for
                            % the accumulator to return to starting value).

B = A-P;                            
                            
ETW = mod(T,2^B);

capacity = 2^B;

if ETW > capacity/2
    ETW = capacity - ETW;
end

OvflPer = capacity/ETW;

NumOvfl = GRR/OvflPer;

sawFreq = 1/(1/fsamp*GRR/NumOvfl)

end

