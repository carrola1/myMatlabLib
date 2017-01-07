%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_fetch.m
%
% Description: This function retrieves a specified number of files and returns
%   a multi-dimensional data array.
%
% Inputs:
%   dir_path: Full path name of the data file
%   file_name: File name of the data to be read
%   num_files: Number of files to be read
%   format: Format of the data to be read
%
% Outputs:
%   file_data: Data read from file
%
% Dependencies:
%   data_read_array
%===================================================================================================
function [file_data] = data_fetch(dir_path, file_name, num_files, format)

  fetch_file = sprintf('%s%s', dir_path, file_name);
  [file_data] = data_read_array(fetch_file, num_files, format);

end
