function myCalcDiffTranslation(Va,Vb,Z,Vcc,Rin,Vas,VbsMin)
% Designer:     Andrew Carroll
%
% Description:  Calculates 3-resistor network for adjusting the offset
%               (common mode) voltage from one differential logic family 
%               to another. 
%
% Inputs:       Va      : Source offset voltage.
%               Vb      : Desired sink offset voltage.
%               Z       : Desired termination impedance.
%               Vcc     : Pull-up voltage.
%               Rin     : Input resistance of sink.
%               Vas     : Source differential swing.
%               VbsMin  : Minimum differential swing required at sink.
%               
% Circuit:      
%                                 Vcc/GND
%                                   _
%                                   |  
%                                   \
%                ________           / R1
%               |        |   Va     \
%               | Source |___|______| 
%               |________|          |
%                                   \
%                                   / R2           _______
%                                   \       Vb    |       |
%                                   |_______|_____| Sink  |  
%                                   \             |_______|       
%                                   / R3
%                                   \
%                                   |
%                                   -
%                                 Vcc/GND
%
%     * Note : For step up, Vcc goes on R3. For step down, Vcc goes on R1.
%  

%%

R1Test = 10:2:500;
R2Test = 10:2:500;
R3Test = 10:2:500;
PerMatchBest = 10000;

for ii = 1:length(R1Test)
    for jj = 1:length(R2Test)
        for kk = 1:length(R3Test)
            R1 = R1Test(ii);
            R2 = R2Test(jj);
            R3 = R3Test(kk)*Rin/(R3Test(kk)+Rin);
            ZTest = R1*(R2+R3)/(R1+R2+R3);
            ZDiff = abs(Z-ZTest)/Z*100;
            if Va > Vb      
                VaTest = ((R2+R3)/(R1+R2+R3))*Vcc;
                VbTest = R3/(R1+R2+R3)*Vcc;
            else
                VaTest = (1-((R2+R3)/(R1+R2+R3)))*Vcc;
                VbTest = (1-(R3/(R1+R2+R3)))*Vcc;
            end
            
            GainTest = R3/(R2+R3);
            Vbs      = Vas*GainTest;
                
            VaDiff = abs(Va-VaTest)/Va*100;
            VbDiff = abs(Vb-VbTest)/Vb*100;
            PerMatch = ZDiff+VaDiff+VbDiff;
            
            if Vbs > VbsMin
                if PerMatch < PerMatchBest
                    PerMatchBest = PerMatch;
                    VaBest = VaTest;
                    VbBest = VbTest;
                    ZBest  = ZTest;
                    R1Best = R1;
                    R2Best = R2;
                    R3Best = R3Test(kk);
                    GainBest = GainTest;
                    VbsBest  = Vbs;
                end
            end
                
        end
    end
end

R1Best
R2Best
R3Best
VaBest
VbBest
ZBest
VbsBest

end
