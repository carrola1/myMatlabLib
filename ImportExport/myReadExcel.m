function data = myReadExcel(fileName)
% Designer:     Andrew Carroll
%
% Description:  Read data from excel. Opens Excel document specified and
%               allows user to highlight target cells.
%
% Inputs:       fileName    : excel file ('example.xlsx')
%
% Outputs:      data        : imported data

%%
data = xlsread(fileName,-1);

end