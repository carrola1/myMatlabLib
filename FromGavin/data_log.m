%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_log.m
%
% Description: This function logs a data array to a file. The file name and
%   format are user specified.
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
%   data_print
%===================================================================================================
function data_log(dir_path, file_name, format, data)

  log_file = sprintf('%s%s', dir_path, file_name);
  data_print(log_file, format, data);
end
