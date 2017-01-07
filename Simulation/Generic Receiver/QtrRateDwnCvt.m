function [sampOut] = QtrRateDwnCvt(samp,init) %#codegen
% Designer:     Andrew Carroll
% Date:         2/6/2013
% Description:  Multiplies samp by in-phase and quadrature components of a vector rotating  
%               counter-clockwise in the IQ plane such that:
%                   
%                   i_out(n) <= data_in(n) * sgn(cos(n*pi/2))   n = {0, 1, 2, ...}
%                   q_out(n) <= data_in(n) * sgn(sin(n*pi/2))   n = {0, 1, 2, ...}
%                   
%               Since four samples are required to make one rotation the output rate is   
%               fin - 1/4 of the input clock rate.
%                   
%               ie.
%                   i_out <= data_in * {1 0 -1 0} ie. multiplication with cosine at 1/4 strobe rate
%                   q_out <= data_in * {0 1 0 -1} ie. multiplication with sine at 1/4 strobe rate
%
%               Based on VHDL QtrRateDwnCvt from MMS.
%
% Inputs:       samp            : input sample.
%               init            : Initialize function.
%
% Outputs       sampOut         : complex output at fin - 1/4 the input clock rate

%% Initialize Function
persistent state

if (init==1) || isempty(state)
  state = 0;
end

%% Function
iOut = 0;
qOut = 0;
switch state
  case 0
    iOut  = samp;
    qOut  = 0;
    state = 1;
  case 1
    iOut  = 0;
    qOut  = samp;
    state = 2;
  case 2
    iOut  = -samp;
    qOut  = 0;
    state = 3;
  case 3
    iOut  = 0;
    qOut  = -samp;
    state = 0;
end

sampOut = complex(iOut,qOut);

end