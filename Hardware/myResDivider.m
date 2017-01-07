function myResDivider(vIn,vOut,tolerance)
% Designer:     Andrew Carroll
%
% Description:  Finds best pair of resistors for voltage divider. Uses
%               standard M55342 resistor values.
%
% Inputs:       vIn       : Input voltage to resistor divider
%               vOut      : desired output voltage
%               tolerance : tolerance in % (1 or .1)

%%
if tolerance == 1
    load Resistors_55342_1Percent.dat;
    resistors = Resistors_55342_1Percent;
else
    load Resistors_55342_p1Percent.dat;
    resistors = Resistors_55342_p1Percent;
end

resistorsBig = [resistors' resistors'.*10 resistors'.*100 resistors'.*1000]';

ratio       = vOut/vIn;
matchR1     = zeros(1,3);
matchR2     = zeros(1,3);
bestMatch   = 1e6.*ones(1,3);
bestDiff    = 1e6.*ones(1,3);

if ratio <= .5
    for ii = 1:length(resistors)                % set R2
        for jj = length(resistorsBig):-1:ii     % search R1
            newRatio = resistors(ii)/(resistorsBig(jj)+resistors(ii));
            diff     = abs(newRatio - ratio);
            if diff < bestDiff(1)
                bestMatch(3) = bestMatch(2);
                bestMatch(2) = bestMatch(1);
                bestMatch(1) = newRatio;
                bestDiff(1)   = diff;
                matchR1(1)   = resistorsBig(jj);
                matchR2(1)   = resistors(ii);
            elseif diff < bestDiff(2)
                bestMatch(3) = bestMatch(2);
                bestMatch(2) = newRatio;
                bestDiff(2)  = diff;
                matchR1(2)   = resistorsBig(jj);
                matchR2(2)   = resistors(ii);
            elseif diff < bestDiff(3)
                bestMatch(3) = newRatio;
                bestDiff(3)  = diff;
                matchR1(3)   = resistorsBig(jj);
                matchR2(3)   = resistors(ii);
            end
        end
    end
else
    for ii = 1:length(resistorsBig)             % set R2
        for jj = 1:length(resistors)            % search R1
            newRatio = resistorsBig(ii)/(resistors(jj)+resistorsBig(ii));
            diff     = abs(newRatio - ratio);
            if diff < bestDiff(1)
                bestMatch(3) = bestMatch(2);
                bestMatch(2) = bestMatch(1);
                bestMatch(1) = newRatio;
                bestDiff(1)   = diff;
                matchR1(1)   = resistors(jj);
                matchR2(1)   = resistorsBig(ii);
            elseif diff < bestDiff(2)
                bestMatch(3) = bestMatch(2);
                bestMatch(2) = newRatio;
                bestDiff(2)  = diff;
                matchR1(2)   = resistors(jj);
                matchR2(2)   = resistorsBig(ii);
            elseif diff < bestDiff(3)
                bestMatch(3) = newRatio;
                bestDiff(3)  = diff;
                matchR1(3)   = resistors(jj);
                matchR2(3)   = resistorsBig(ii);
            end
        end
    end
    
end

perError = ones(1,3);
vOutExp  = ones(1,3);
for kk = 1:3
    perError(kk) = (abs(vIn*bestMatch(kk) - vIn*ratio)/(vIn*ratio))*100;
    vOutExp(kk)  = vIn*bestMatch(kk);
end

fprintf('\nR1 = %g ; R2 = %g\n',matchR1(1),matchR2(1))
fprintf('VOut = %.4g\n',vOutExp(1));
fprintf('%%Error = %2.2g%%\n\n',perError(1));

fprintf('\nR1 = %g ; R2 = %g\n',matchR1(2),matchR2(2))
fprintf('VOut = %.4g\n',vOutExp(2));
fprintf('%%Error = %2.2g%%\n\n',perError(2));
                
fprintf('\nR1 = %g ; R2 = %g\n',matchR1(3),matchR2(3))
fprintf('VOut = %.4g\n',vOutExp(3));
fprintf('%%Error = %2.2g%%\n\n',perError(3));        


end