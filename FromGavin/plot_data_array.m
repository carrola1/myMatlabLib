%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: plot_data_array.m
%
% Description: This function is used to plot a set of data arrays to files.
%
% Inputs:
%   expect_path: Full path of the expect data file
%   source_path: Full path of the source data file
%   target_path: Full path of the plot capture file
%   data_name: File identifier for the vectors to be compared
%   num_files: Number of files in the array to be plotted
%
% Outputs:
%   None
%
% Dependencies:
%   None
%===================================================================================================
function plot_data_array(expect_path, source_path, target_path, data_name, num_files)

  for file_index = 1:num_files
    full_data_name = sprintf('%s%s%s', data_name, '_', num2str(file_index-1));
    plot_data(expect_path, source_path, target_path, full_data_name);
  end

end
