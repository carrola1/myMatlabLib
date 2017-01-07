BER = 0;
for ii = 1:20

    data = tp6(1:(floor(length(tp6)-16)/16)*16);
    txI  = txDStore(:,1);
    txQ  = txDStore(:,2);

    dataPlNoise = awgn(data,3,'measured');

    %% Parameters
    RollOff     = 0.3;
    SymsPerFilt = 8;
    SampPerSym  = 16;

    %% Receive Filter
    N    = 256;                  % Order
    Fs   = SampPerSym;           % sampling frequency
    Fc   = 1.5;                  % Fc as % of symbol rate
    TM   = 'Rolloff';            % Transition Mode
    DT   = 'sqrt';               % Design Type
    Beta = 0.5;                  % Window Parameter

    win = kaiser(N+1, Beta);

    filtCoeffs  = firrcos(N, Fc/(Fs/2), RollOff, 2, TM, DT, [], win);

    Fpass = 1.5;    % Passband Frequency
    Fstop = 2.2;    % Stopband Frequency
    Wpass = 1;    % Passband Weight
    Wstop = 1;    % Stopband Weight
    dens  = 20;   % Density Factor

    %Calculate the coefficients using the FIRPM function.
    filtCoeffs  = firpm(N, [0 Fpass Fstop Fs/2]/(Fs/2), [1 1 0 0], [Wpass Wstop], ...
               {dens});

    %% Receiver

    % Filter receiver data
    rxData  = filter(filtCoeffs,1,dataPlNoise');

    start     = 1;
    errOffset = 0;
    dly       = 12;

    recSymI = sign(real(rxData(start:16:end)));
    recSymQ = sign(imag(rxData(start:16:end)));

    err = sum(abs(recSymI(dly:end) - txI(1:end-dly))) - errOffset;

    BER = BER + err/(sum(abs(recSymI(11:end)))-errOffset);
    
end

BER = BER/20