function myDump2Excel(data,fileName,startColumn,startRow,sheet,rowColumnMatrix)
% Designer:     Andrew Carroll
%
% Description:  Dump data to excel file
%
% Inputs:       data            : data to dump (can be array or matrix)
%               fileName        : excel file ('example.xlsx')
%               startColumn     : column to start data at ('A')
%               startRow        : row to start data at
%               rowColumnMatrix : 0 = dump array into a row
%                                 1 = dump array into a column
%                                 2 = dump matrix

%%
getSizeData = size(data);

if rowColumnMatrix == 1
    if getSizeData(2) > 1
        data = data';
    end
    startAddr = sprintf([startColumn '%d'],startRow); 
    endAddr   = sprintf([startColumn '%d'],startRow + length(data)-1);
elseif rowColumnMatrix == 0
    if getSizeData(1) > 1
        data = data';
    end
    startAddr   = sprintf([startColumn '%d'],startRow); 
    endColumn   = myAlphabetIncr(startColumn,length(data)-1);
    endAddr     = sprintf([endColumn '%d'],startRow);
else
    endRow      = startRow+getSizeData(1)-1;
    endColumn   = myAlphabetIncr(startColumn,getSizeData(2)-1);
    startAddr   = sprintf([startColumn '%d'],startRow);
    endAddr     = sprintf([endColumn '%d'],endRow);
end

range = sprintf([startAddr ':' endAddr]);

xlswrite(fileName,data,sheet,range);

end