fTarget = [52.5 14 7];

N  = [1 2 3 4 5 6 8 10 12];
K  = [1 2 4];
R  = [1 2];
M  = [1 2];
XO = 105;

PerDiffBest = 1000;
for xx = 1:length(XO)
  for nn = 1:length(N)
    for kk = 1:length(K)
      for rr = 1:length(R)
        for mm = 1:length(M)

          % Feedback connected to 1Qn or 2Qn
          f11      = XO(xx)*N(nn)/R(rr);
          f21      = XO(xx)*N(nn)/R(rr)*1/K(kk);
          f31      = XO(xx)*N(nn)/R(rr)*1/M(mm);
          f        = sort([f11 f21 f31],'descend');
          PerDiff1 = sum(abs(f-fTarget)./fTarget);
          
          % Feedback connected to 3Qn
          f12      = XO(xx)*N(nn)/R(rr)*K(kk);
          f22      = XO(xx)*N(nn)/R(rr);
          f32      = XO(xx)*N(nn)/K(kk)/M(mm);
          f        = sort([f12 f22 f32],'descend');
          PerDiff2 = sum(abs(f-fTarget)./fTarget);
          
          % Feedback connected to 4Qn
          f13      = XO(xx)*N(nn)/R(rr)*M(mm);
          f23      = XO(xx)*N(nn)/R(rr)*M(mm)/K(kk);
          f33      = XO(xx)*N(nn)/R(rr);
          f        = sort([f13 f23 f33],'descend');
          PerDiff3 = sum(abs(f-fTarget)./fTarget);
          [PerDiffMin,index]  = min([PerDiff1 PerDiff2 PerDiff3]);
          
          if PerDiffMin < PerDiffBest 
            PerDiffBest = PerDiffMin;
            FbBest      = index;
            NBest       = N(nn);
            RBest       = R(rr);
            KBest       = K(kk);
            MBest       = M(mm);
            XoBest      = XO(xx);
            if index == 1
              f1Best      = f11;
              f2Best      = f21;
              f3Best      = f31;
            elseif index == 2
              f1Best      = f12;
              f2Best      = f22;
              f3Best      = f32;
            elseif index == 3
              f1Best      = f13;
              f2Best      = f23;
              f3Best      = f33;
            end
          end
          
        end
      end
    end
  end
end

XoBest
FbBest
NBest
KBest
RBest
MBest
f1Best
f2Best
f3Best

