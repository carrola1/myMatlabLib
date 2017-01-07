function myCalcPropDly(VelOfProp)
% Designer:     Andrew Carroll
%
% Description:  Calculates propagation delay of a cable based on its
%               velocity of propagation (Vp).
%
% Inputs:       VelOfProp  : velocity of propagation as % of speed of 
%                            light in a vacuum.  
%
% Outputs       Prints propagation delay in ns/ft.
%
% Note : Vp = 100/sqrt(eps), where eps = eps_0*eps_r
%           eps_0 = dielectric constant of free space = 1
%           eps_r = relative dielectric constant

%%

propDly = 1.016*(100/VelOfProp);

fprintf('\nPropagation Delay = %.4g ns/ft\n\n',propDly)


end