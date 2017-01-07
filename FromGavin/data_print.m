%===============================================================================
% L-3 Cincinnati Electronics Proprietary
%===============================================================================
% File Name: data_print.m
%
% Description: This function prints a data array to a file. The file name and
%   format are user specified.
%
% Inputs:
%   file_name: File name of the data to be read
%   format: Format of the data to be printed
%   data: Data to be printed to file
%
% Outputs:
%   None
%
% Dependencies:
%   None
%===============================================================================
function data_print(file_name, format, data)

  full_file_name = sprintf('%s%s', file_name, '.txt');
  fp = fopen(full_file_name,'wt');
  if (format == 'int')
    fprintf(fp,'%d\n', data);
  elseif (format == 'real')
    fprintf(fp,'%10.5f\n', data);
  else
    fprintf(fp,'%x\n', data);
  end
  fclose(fp);
end
