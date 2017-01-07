function myDump2Text(data,txtFile)
% Designer:     Andrew Carroll
%
% Description:  Dump data to a text file
%
% Inputs:       data      : data array to dump
%               txtFile   : file to dump to (string)

%%

fileID = fopen(txtFile,'w');

for ii = 1:length(data)
    fprintf(fileID,'%d\n',data(ii));
end

fclose(fileID);

end