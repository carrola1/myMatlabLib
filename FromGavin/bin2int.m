%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: bin2int.m
%
% Description: This function converts a binary number to an integer. The
%   integer result can be specified to be signed or unsigned.
%
% Operational Type: Sample
%
% Inputs:
%   binary_data: Input binary value
%   conv_type: Specifies signed or unsigned conversion
%
% Outputs:
%   integer_data: Output integer value
%
% Dependencies:
%   None
%===================================================================================================
function [integer_data] = bin2int(binary_data, conv_type)

  % Variable initializations
  binary_width = length(binary_data);

  if (strcmp(conv_type, 'sign'))
    % Signed conversion
    if (binary_data(binary_width) == 0)
      integer_data = 0;
    else
      integer_data = -(2^(binary_width-1));
    end

    for index = 1:(binary_width-1)
      if (binary_data(index) == 1)
        integer_data = integer_data + 2^(index-1);
      end
    end  
  else
    % Unsigned conversion
    integer_data = 0;
    for index = 1:binary_width
      if (binary_data(index) == 1)
        integer_data = integer_data + 2^(index-1);
      end
    end  
  end
end
