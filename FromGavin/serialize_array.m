%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: serialize_array.m
%
% Description: This function converts a 2-dimensional array into a single column by concatenating
%   individual columns.
%
% Operational Type: Sample
%
% Inputs:
%   input_array: Input array 2-dimensional
%
% Outputs:
%   serialized_array: Serialized array in vector form
%
% Dependencies:
%   bin2int
%===================================================================================================
function [serialized_array] = serialize_array(input_array)
  %% Take column by colum and assign to different row indices
  [num_rows, num_columns]  = size(input_array);
  serialized_array = zeros((num_rows * num_columns),1);

  for column_index = 1:num_columns
    start_index = ((column_index-1)*num_rows) + 1;
    end_index = start_index + num_rows - 1;
    serialized_array((start_index:end_index),1) = input_array(:,column_index);
  end
end
