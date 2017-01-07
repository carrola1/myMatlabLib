function [ber, numBits] = myBERTool(EbNo, maxNumErrs, maxNumBits)
% Designer:     Andrew Carroll
%
% Description:  Plots BER curve for random filtered BPSK signal. Creates
%               random bit stream, oversamples bits, filters, modulates,
%               adds white gaussian noise, demodulates, and calculates BER.
%
% Instructions: Design filter by typing "FDATool" in MATLAB command window.
%               Export b coefficients to workspace (use odd order filter). 
%               Copy coefficients into b below under "Set Parameters." If 
%               no filter is desired set b to 1.
%
%               Set xFd = (sample rate / symbol rate) below under "Set
%               Parameters"
%
%               Open BERTool by typing "BERTool" in command window. Go to
%               MonteCarlo tab. Set BER variable name to BER. Change 
%               Simulation model to "myBERTool.m". Set desired Eb/No range
%               and press run.

% Import Java class for BERTool.
import com.mathworks.toolbox.comm.BERTool;

%% Transmit Filter Coefficients (Fs = 24, N = 20, Fc = 2.2, R = 0.8)
Fs   = 24;  % Sampling Frequency

N    = 50;         % Order
Fc   = 2.5;        % Cutoff Frequency
TM   = 'Rolloff';  % Transition Mode
R    = 0.4;        % Rolloff
DT   = 'sqrt';     % Design Type
Beta = 1;          % Window Parameter

% Create the window vector for the design algorithm.
win = kaiser(N+1, Beta);

% Calculate the coefficients using the FIR1 function.
b  = firrcos(N, Fc/(Fs/2), R, 2, TM, DT, [], win);
Hd = dsp.FIRFilter( ...
  'Numerator', b);

% Fs = 24;  % Sampling Frequency
% 
% N     = 50;   % Order
% Fpass = 2;    % Passband Frequency
% Fstop = 3.9;  % Stopband Frequency
% Wpass = 1;    % Passband Weight
% Wstop = 8;    % Stopband Weight
% dens  = 20;   % Density Factor
% 
% % Calculate the coefficients using the FIRPM function.
% b  = firpm(N, [0 Fpass Fstop Fs/2]/(Fs/2), [1 1 0 0], [Wpass Wstop], ...
%   {dens});
% Hd = dsp.FIRFilter( ...
%   'Numerator', b);

HdTx = 1;

%% Receive Filter Coefficients
Fs = 24;  % Sampling Frequency

N     = 50;   % Order
Fpass = 6;    % Passband Frequency
Fstop = 9;   % Stopband Frequency
Wpass = .1;    % Passband Weight
Wstop = 50;   % Stopband Weight
dens  = 20;   % Density Factor

% Calculate the coefficients using the FIRPM function.
b  = firpm(N, [0 Fpass Fstop Fs/2]/(Fs/2), [1 1 0 0], [Wpass Wstop], ...
  {dens});
Hd = dsp.FIRFilter( ...
  'Numerator', b);

HdRx = 1;

%% Initialize variables related to exit criteria.
totErr = 0;  % Number of errors observed
numBits = 0; % Number of bits processed

%% --- Set up parameters. ---
siglen   = 10000;                     % Number of bits in each trial
xFd      = 8;                         % Upsampling factor
xInterp  = 10;                        % Interpolation factor (improve delay matching)

snr      = EbNo - 10*log10(.5*xFd);   % SNR = EbNo - 10*log(.5*Tsym/Tsamp)
ntrials  = 0;                         % Number of passes through the loop

%% Simulate until number of errors exceeds maxNumErrs
% or number of bits processed exceeds maxNumBits.
while((totErr < maxNumErrs) && (numBits < maxNumBits))

   % Check if the user clicked the Stop button of BERTool.
   if (BERTool.getSimulationStop)
      break;
   end

   % Run once with no noise to find delay of filters
   if ntrials == 0
     msg         = myGenRndData(siglen,1,1);                 % Generate message sequence.
     msgUpSamp   = rectpulse(msg,xFd);
     msgFilt     = filter(HdTx,1,msgUpSamp);                 % TX FIR Filter
     rxFilt      = filter(HdRx,1,msgFilt);                   % RX FIR Filter    
   
     rxInterp    = interp(rxFilt,xInterp);
     rxInterpRef = rectpulse(msgUpSamp,xInterp);
   
     dly         = finddelay(rxInterpRef,rxInterp);
     if dly < 0                                              % This is if the filters are off (=1)
       finalBit  = rem(length(rxInterp(1:end))-dly,xFd*xInterp);
     else
       finalBit  = rem(length(rxInterp(dly+1:end)),xFd*xInterp);
     end
   end
   
   % Generate Transmit Data
   msg        = myGenRndData(siglen,1,1);         % Generate random message sequence.
   %msg        = myGenSqWave(siglen,1,1);         % Sq Wave for test
   msgUpSamp  = rectpulse(msg,xFd);               % Upsample
   msgFilt    = filter(HdTx,1,msgUpSamp);         % TX FIR Filter
   
   chlsig     = awgn(msgFilt, snr, 'measured');   % Add noise
   
   rxFilt     = filter(HdRx,1,chlsig);            % RX FIR Filter
   
   % Interpolate and adjust for delay
   if dly < 0
      rxInterp    = interp(rxFilt,xInterp);
      rxInterp    = [rxInterp(1)*ones(1,-dly) rxInterp(1:end)];
      rxInterp    = rxInterp(1:end-finalBit);
   else
      rxInterp    = interp(rxFilt,xInterp);
      rxInterp    = rxInterp(dly+1:end-finalBit);
   end
   
   % Bit Sync
   decodmsg = intdump(rxInterp,xFd*xInterp);      % Integrate and dump
   decodmsg = sign(decodmsg);                     % Demodulate
   
   newerrs = sum(abs(msg(1:end-(length(msg)-length(decodmsg))) - decodmsg))/2; % Errors in this trial
   ntrials = ntrials + 1; % Update trial index
   
   % Update the total number of errors.
   totErr = totErr + newerrs;

   % Update the total number of bits processed.
   numBits = ntrials * siglen;

end % End of loop

% Compute the BER.
ber = totErr/numBits;