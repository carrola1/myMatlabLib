%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: data_print_array.m
%
% Description: This function prints a set of data arrays to files. The file name
%   and format are user specified.
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
%===================================================================================================
function data_print_array(file_name, format, data)

  [num_data, num_files] = size(data);
  for file_index = 1:num_files
    full_file_name = sprintf('%s%s%s%s', file_name, '_', ...
      num2str(file_index-1), '.txt');
    fp = fopen(full_file_name,'wt');
    if (format == 'int')
      fprintf(fp,'%d\n', data(:,file_index));
    elseif (format == 'real')
      fprintf(fp,'%10.5f\n', data(:,file_index));
    else
      fprintf(fp,'%x\n', data(:,file_index));
    end
    fclose(fp);
  end
end
