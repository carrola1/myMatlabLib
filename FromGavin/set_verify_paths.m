%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: set_verify_paths.m
%
% Description: This function sets the appropriate paths for the plotting the
%   vector files.
%
% Inputs:
%   file_name: File name of the vectors to be compared
%
% Outputs:
%   expect_path: Full path of the expect data file
%   source_path: Full path of the source data file
%   target_path: Full path of the plot capture file
%
% Dependencies:
%   None
%===================================================================================================
function [expect_path, source_path] = set_verify_paths(file_name)

  expect_subpath = sprintf('%s%s%s', '7_Matlab\Fixed_Point_Model\Unit_Test\', file_name, '\');
  source_subpath = sprintf('%s%s%s', '3_Implementation\Unit_Test\', file_name, '\testbench\');

  expect_path = set_path(expect_subpath);
  source_path = set_path(source_subpath);
end
