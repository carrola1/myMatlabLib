%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_read.m
%
% Description: This function reads the specified path/file and returns a data
%   array. The format of the data can be specified.
%
% Inputs:
%   file_name: Full path file name of the data to be read
%   format: Format of the data to be read
%
% Outputs:
%   data: Data read from file
%
% Dependencies:
%   None
%===================================================================================================
function [data] = data_read(file_name, format)

  full_file_name = sprintf('%s%s', file_name, '.txt');
  fp = fopen(full_file_name,'r');
  if (format == 'int')
    data = fscanf(fp, '%g');
  elseif (format == 'real')
    data = fscanf(fp, '%f');
  else
    data = fscanf(fp, '%x');
  end
  fclose(fp);
end
