function PlotSfcgNtia(SymRate,FileToRead)
% Designer:     Andrew Carroll
%
% Description:  Accepts ASCII file data from Rhode&Schwarz FSUP Signal 
%               Analyzer. Plots spectrum with SFCG and NTIA mask overlays.
%
% Inputs:       SymRate      : Symbol rate in Hz
%               FileToRead   : Name of data file in format 'name.dat'
%
% Outputs:      Plot
%
% Note:         For good plots, set SpecAn to following settings:
%                   - Span = (carrier - DataRate*10) : (carrier + DataRate*10)
%                   - ResBW = DataRate/100
%                   - VidBW = DataRate/200
%                   - Set trace to average about 20 sweeps
%                   - Set sweep points to maximum

%% Import File "FileToRead" and Format
DELIMITER = ';';
HEADERLINES = 29;

DataStruct = importdata(FileToRead, DELIMITER, HEADERLINES);
DataMatrix = DataStruct.data;
freq = DataMatrix(:,1);
amp  = DataMatrix(:,2);

%% Find carrier and adjust amplitude in reference

% Rough estimate of location and power of carrier
[refDb,refDbIndex] = max(amp);                      

% Sweep +/- 100 pts and find best correlation btwn (+) and (-) sides of 
% spectrum (i.e. find line of symmetry). Only look 8 sidelobes out.
bestCorr = 1e20;
for ii = refDbIndex-1000:refDbIndex+1000
    PosSide = amp(ii:ii+round((SymRate)/(freq(2)-freq(1))*7));
    NegSide = amp(ii:-1:ii-length(PosSide)+1);
    corr = sum(abs(PosSide-NegSide));
    if corr < bestCorr
        bestCorr   = corr;
        refDbIndex = ii;
    end
end

% Adjust amplitude in reference to carrier
refDb    = mean(amp((refDbIndex - 300):(refDbIndex+300)));
ampAdj   = amp + abs(refDb);                                                % Adjust for 0dBm reference

% Filter and interpolate data to better see peak value (carrier)
windowSize         = 30;
ampFilt            = filter(ones(1,windowSize)/windowSize,1,ampAdj);          
ampFilt            = interpft(ampFilt,length(ampAdj));
ampAdj             = ampFilt(windowSize:end);
freq               = freq(1:end-windowSize+1);


%% Adjust frequency for offset from carrier
freq      = freq - freq(refDbIndex);
freq      = freq/SymRate;

amp       = ampAdj;


%% Plot Spectrum
figure
plot(freq,amp,'k')
hold on

% SFCG
plot([-10 -8 -3 -.5 0 0 .5 3 8 10], [-60 -60 -30 0 0 0 0 -30 -60 -60],'r')

% NTIA
fNTIA = 1:.1:20;
NTIA = -8 + log10(fNTIA)*-40;                               % NTIA curve = -40dB/decade
plot([-fNTIA(end:-1:1) -1 -1 0 0 1 1 fNTIA], [NTIA(end:-1:1) -8 0 0 0 0 -8 NTIA],'b')

axis([-10 10 -80 10]);

% Plot Parameters
titleRate = sprintf(['kHz Symbol Rate']);
title(['Output Spectrum - ',num2str(SymRate/1e3), titleRate])
xlabel(['Frequency-off-carrier to Symbol Rate Ratio (F/Rs)'])
ylabel('Power (dBsd)')
legend('Spectrum Data', 'SFCG Mask (<2MSPS)', 'NTIA Mask (K=1)')
hold off

end