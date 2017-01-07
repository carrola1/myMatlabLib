%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_read_array.m
%
% Description: This function reads the mutliple specified path/files and returns
%   a multi-dimensional array. The format of the data can be specified.
%
% Inputs:
%   file_name: Full path file name of the data to be read
%   num_files: Number of files to be read
%   format: Format of the data to be read
%
% Outputs:
%   data: Data read from file
%
% Dependencies:
%   None
%===================================================================================================
function [array_data] = data_read_array(file_name, num_files, format)

  for file_index = 1:num_files
    full_file_name = sprintf('%s%s%s%s', file_name, '_', ...
      num2str(file_index-1), '.txt');
    fp = fopen(full_file_name,'r');
    if (format == 'int')
      data = fscanf(fp, '%g');
    elseif (format == 'real')
      data = fscanf(fp, '%f');
    else
      data = fscanf(fp, '%x');
    end
    fclose(fp);
    array_data(:,file_index) = data;
  end
end
