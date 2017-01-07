%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: vector2array.m
%
% Description: This function will convert a two-dimensional array of data into a
%   one-dimensional vector.
%
% Operational Type: N/A
%
% Inputs:
%   data: Data array
%
% Outputs:
%   serial_data: Serialized data
%
% Dependencies:
%   None
%===================================================================================================
function [array] = vector2array(vector,row_length)

  column_length = floor(length(vector)/row_length);
  array = zeros(row_length,column_length);

  for index = 1:column_length
    start = row_length*(index-1)+1;
    stop = row_length*index;
    array(:,index) = vector(start:stop);
  end
end
