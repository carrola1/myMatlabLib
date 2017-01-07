%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: array2vector.m
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

function [vector] = array2vector(array)

  [row_length, column_length] = size(array);
  vector = zeros(row_length*column_length,1);

  for index = 1:column_length
    start = row_length*(index-1)+1;
    stop = row_length*index;
    vector(start:stop) = array(:,index);
  end
end
