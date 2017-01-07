
% Inputs
numClks       = 10000;
divClk0Ratio  = 8;
divClk1Ratio  = 7;
refClkFreq    = 100e6;

refClkPer     = 1/refClkFreq;
refClkPerDiv2 = refClkPer/2; 

t = [0:refClkPerDiv2:refClkPerDiv2*(numClks*2-1)];

refClk = zeros(1,numClks*2);
for ii = 2:length(t)
    refClk(ii)   = not(refClk(ii-1));
end


divClk0  = zeros(1,numClks*2);
divClk1  = zeros(1,numClks*2);
count0   = 0;
count1   = 0;
for jj = 2:length(refClk)
    if refClk(jj) == 1
        count0 = count0 + 1;
        count1 = count1 + 1;
        if count0 > divClk0Ratio/2 - 1
            divClk0(jj) = not(divClk0(jj-1));
            count0      = 0;
        else
            divClk0(jj) = divClk0(jj-1);
        end
        if count1 > divClk1Ratio/2 - 1
            divClk1(jj) = not(divClk1(jj-1));
            count1      = 0;
        else
            divClk1(jj) = divClk1(jj-1);
        end
    else
        divClk0(jj) = divClk0(jj-1);
        divClk1(jj) = divClk1(jj-1);
    end
end

tTrigger = zeros(1,length(divClk0));
countTrigger = 0;
for kk = 2:length(divClk0)
    if divClk0(kk) == 1
        if divClk0(kk-1) ~= 1
            if countTrigger == 5
                tTrigger       = -refClkPer*2.5*divClk0Ratio:refClkPerDiv2:refClkPer*2.5*divClk0Ratio;
                divClk0Trigger = divClk0(kk-divClk0Ratio*2*2.5:kk+divClk0Ratio*2*2.5);
                break
            else
                countTrigger = countTrigger + 1;
            end
        end
    end
end

tTrigger        = rectpulse(tTrigger,2);
tTrigger        = tTrigger(1:length(tTrigger)-1) + refClkPerDiv2;
divClk0Trigger  = rectpulse(divClk0Trigger,2);
divClk0Trigger  = divClk0Trigger(2:length(divClk0Trigger));


%%% Everything good above this point



refClkTrigger   = rectpulse(refClk,2);
tTrigger        = rectpulse(tTrigger,2);
divClk0Trigger  = rectpulse(divClk0,2);
divClk1Trigger  = rectpulse(divClk1,2);

refClkTrigger   = refClkTrigger(2:length(refClkTrigger));
tTrigger        = tTrigger(1:length(tTrigger)-1);
divClk0Trigger  = divClk0Trigger(2:length(divClk0Trigger));
divClk1Trigger  = divClk1Trigger(2:length(divClk1Trigger));


refClk   = rectpulse(refClk,2);
t        = rectpulse(t,2);
divClk0  = rectpulse(divClk0,2);
divClk1  = rectpulse(divClk1,2);

refClk   = refClk(2:length(refClk));
t        = t(1:length(t)-1);
divClk0  = divClk0(2:length(divClk0));
divClk1  = divClk1(2:length(divClk1));






plot(t(1:100),refClk(1:100))
hold on
plot(t(1:100),divClk0(1:100),'r')
axis([0 t(100) -.05 1.05])
hold off

        

