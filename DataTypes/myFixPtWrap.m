function fiOut = myFixPtWrap(sign,Bits)
% Designer:     Andrew Carroll
%
% Description:  Returns a fixed point variable of width Bits that
%               wraps on overflow and maintains its bit width after
%               addition/subtraction operations. Initial value is 0.
%
% Inputs:       sign       : 0 = unsigned, 1 = signed
%               Bits       : desired bit width

fiOut = fi(0,sign,Bits,0,'overflowmode', 'wrap','SumMode',...
       'SpecifyPrecision','SumWordLength',Bits,'SumFractionLength',0);
   
end