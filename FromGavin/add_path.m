%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: add_path.m
%
% Description: This function adds the project path which includes all
%   subdirectories.
%
% Inputs:
%   None
%
% Outputs:
%   None
%
% Dependencies:
%   None
%===================================================================================================
function add_path()

  dir_path = set_path('7_Matlab\');
  path(genpath(dir_path), path);
end
