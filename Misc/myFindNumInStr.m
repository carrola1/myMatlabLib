function Data = myFindNumInStr(String, Key, Offset)
% Designer:     Andrew Carroll
%
% Description:  Extracts data from a string or cell array of strings.
%
% Inputs:       String  : single string or cell array of strings to search
%               Key     : keyword which precedes data
%               Offset  : number of characters between keyword and start of data
%
% Outputs       Data    : extracted data
%         
%
% Examples      String = 'Delay = 3.05, Jitter = 66.2';  
%               myFindNumInStr(String, 'Jitter', 3)
%
%               String = {'Delay = 3.05, Jitter = 66.2' ; 'Delay = 1.25, Jitter = 21.567'};
%               myFindNumInStr(String, 'Jitter', 3)

if iscell(String)
    Str    = cell2mat(String(1));
    NumStr = length(String);
else
    Str    = String;
    NumStr = 1;
end
Index  = strfind(Str, Key)+length(Key)+Offset;

Values = zeros(NumStr,1);
for ii = 1:NumStr
    if iscell(String)
        Str = cell2mat(String(ii));
    else
        Str = String;
    end
    Values(ii) = str2double(Str(Index));
    for jj = Index+1:length(Str)
        if isnan(str2double(Str(Index:jj)))
            break
        else
            Values(ii) = str2double(Str(Index:jj));
        end
    end
end

Data = Values;