%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: int2bin.m
%
% Description: This function converts an integer number to binary.
%
% Operational Type: Sample
%
% Inputs:
%   integer_data: Input integer value
%   binary_width: Width of the binary output
%   conv_type: Specifies signed or unsigned integer format
%
% Outputs:
%   binary_data: Output binary value
%
% Dependencies:
%   None
%===================================================================================================
function [binary_data] = int2bin(integer_data, binary_width, conv_type)

  % Variable initializations
  binary_data = zeros(binary_width, 1);

  if (strcmp(conv_type, 'sign'))
    % Signed conversion
    if (integer_data >= 0)
      sign = 0;
    else
      sign = 1;
    end
    magnitude = abs(integer_data);

    for index = binary_width:-1:1
      threshold = 2^(index-1);
      if (magnitude >= threshold)
        binary_data(index) = 1;
        magnitude = magnitude - threshold;
      end
    end

    if (sign == 1)
      % Invert all bits
      for index = 1:binary_width
        binary_data(index) = not(binary_data(index));
      end

      % Add 1 to result
      prev_carry = 1;
      for index = 1:binary_width
        carry = and(binary_data(index), prev_carry);
        binary_data(index) = xor(binary_data(index), prev_carry);
        prev_carry = carry;
      end
    end

  else
    % Unsigned conversion
    for index = binary_width:-1:1
      threshold = 2^(index-1);
      if (integer_data >= threshold)
        binary_data(index) = 1;
        integer_data = integer_data - threshold;
      end
    end
  end
end
