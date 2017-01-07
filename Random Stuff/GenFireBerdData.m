dataLength = 512;
pn  = myPnGen(9,[9 5 1],1);
asm = [0 0 1 1 0 1 0 1 0 0 1 0 1 1 1 0 1 1 1 1 1 0 0 0 0 1 0 1 0 0 1 1];
pn  = [asm pn];
pn  = pn(1:dataLength);


% For FireBERD
fprintf('\n')
for ii = 1:8:length(pn)
  dec1 = myBin2Dec(pn(ii+7:-1:ii+4),0,4,0,0);
  dec2 = myBin2Dec(pn(ii+3:-1:ii),0,4,0,0);
  hex1 = dec2hex(dec1);
  hex2 = dec2hex(dec2);
  fprintf(hex1)
  fprintf(hex2)
end
fprintf('\n')

% For Binary File
fprintf('\n')
for ii = 1:8:length(pn)
  dec  = myBin2Dec(pn(ii:ii+7),0,8,0,0);
  hex  = dec2hex(dec,2);
  fprintf(hex)
end
fprintf('\n')