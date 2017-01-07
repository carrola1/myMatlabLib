%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: set_path.m
%
% Description: This function sets the project path.
%
% Inputs:
%   sub_dir: Subdirectory path
%
% Outputs:
%   dir_path: Full path name of the data file
%
% Dependencies:
%   None
%===================================================================================================
function [dir_path] = set_path(sub_dir)

  root = 'C:\SVN\c2v2\8_Xcvr\';
  dir_path = sprintf('%s%s', root, sub_dir);
end
