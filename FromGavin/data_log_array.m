%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_log_array.m
%
% Description: This function logs a set of data arrays to files. The file name
%   and format are user specified.
%
% Inputs:
%   dir_path: Full path name of the data file
%   file_name: File name of the data to be logged
%   format: Format of the data to be read
%   data: Data to be logged to file
%
% Outputs:
%   None
%
% Dependencies:
%   data_print_array
%===================================================================================================
function data_log_array(dir_path, file_name, format, data)

  log_file = sprintf('%s%s', dir_path, file_name);
  data_print_array(log_file, format, data);
end
