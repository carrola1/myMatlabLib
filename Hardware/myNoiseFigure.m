function NFTot = myNoiseFigure(G,NF)
% Designer:     Andrew Carroll
%
% Description:  Accepts gain and noise figure stage arrays and calculates
%               total noise figure.
%
% Inputs:       G       : gain array (dB)
%               NF      : noise figure array (dB)
%
% Outputs:      NFTot   : total equivalent noise figure (dB)

GLin     = 10.^(G/10);
NFLin    = 10.^(NF/10);
NFTotLin = NFLin(1);
GLinTot  = GLin(1);
for ii = 2:length(G)
    NFTotLin = NFTotLin + (NFLin(ii) - 1)/GLinTot;
    GLinTot  = GLinTot*GLin(ii);
end

NFTot = 10*log10(NFTotLin);
    