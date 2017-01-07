function myFindResistor(resValue,tolerance)
% Designer:     Andrew Carroll
%
% Description:  Outputs closest M55342 resistor value to input as well as
%               closest pair in series and parallel.
%
% Inputs:       resValue  : desired resistor value
%               tolerance : desired tolerance in % (1, .1)
%               
% Outputs:      Prints closest single, series, and parallel match to 
%               Command Window.

%%
if tolerance == 1
    load Resistors_55342_1Percent.dat;
    resistors = Resistors_55342_1Percent;
else
    load Resistors_55342_p1Percent.dat;
    resistors = Resistors_55342_p1Percent;
end

if resValue < 10
    fprintf('\nError : Resistor value must be > 10 ohms\n\n')
    return
elseif resValue > 100e6
    fprintf('\nError : Resistor value must be < 100M ohms\n\n')
    return
end

resistorsBig = [resistors'/100 resistors'/10 resistors' resistors'.*10 resistors'.*100 resistors'.*1000]';

% Find multiplier
multiplier = 1;
for ii = 1:6
    if resValue < 100
        break
    else
        resValue   = resValue/10;
        multiplier = multiplier + 1;
    end
end

closestMatch = 0;
diff         = 200;

% Single resistor
for ii = 1:length(resistors)
    if abs(resistors(ii) - resValue) < diff
        closestMatch = resistors(ii);
        diff         = abs(resistors(ii) - resValue);
    end
end
singleResistor = closestMatch;

% 2 Series resistors
diff = 1e6;
for ii = 1:length(resistors)
    for jj = 1:length(resistorsBig)
        if abs(resistors(ii) + resistorsBig(jj) - resValue) < diff
            closestMatch  = resistors(ii);
            closestMatch2 = resistorsBig(jj);
            diff          = abs(resistors(ii)+resistorsBig(jj)-resValue);
        end
    end
end
seriesResistor1 = closestMatch;
seriesResistor2 = closestMatch2;

% 2 Parallel resistors
diff = 1e6;
for ii = 1:length(resistors)
    for jj = 1:length(resistorsBig)
        if abs(resistors(ii)*resistorsBig(jj)/(resistors(ii) + resistorsBig(jj)) - resValue) < diff
            closestMatch  = resistors(ii);
            closestMatch2 = resistorsBig(jj);
            diff          = abs(resistors(ii)*resistorsBig(jj)/(resistors(ii) + resistorsBig(jj))-resValue);
        end
    end
end
parallelResistor1 = closestMatch;
parallelResistor2 = closestMatch2;


singleResistor    = singleResistor*10^(multiplier-1);
seriesResistor1   = seriesResistor1*10^(multiplier-1);
seriesResistor2   = seriesResistor2*10^(multiplier-1);
seriesTotal       = seriesResistor1 + seriesResistor2;
parallelResistor1 = parallelResistor1*10^(multiplier-1);
parallelResistor2 = parallelResistor2*10^(multiplier-1);
parallelTotal     = parallelResistor1*parallelResistor2/(parallelResistor1 + parallelResistor2);

fprintf('\nClosest Single Match is : %g ohms\n\n',singleResistor)
fprintf('\nClosest Series Match is : %g & %g = %g ohms\n\n',seriesResistor1,seriesResistor2,seriesTotal)
fprintf('\nClosest Parallel Match is : %g & %g = %.4g ohms\n\n',parallelResistor1,parallelResistor2,parallelTotal)


end