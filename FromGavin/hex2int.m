%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: hex2int.m
%
% Description: This function converts a hexidecimal byte to an integer. The
%   integer result is unsigned.
%
% Operational Type: Sample
%
% Inputs:
%   hex_byte: Input byte in hex format
%
% Outputs:
%   integer_byte: Integer result after conversion
%
% Dependencies:
%   None
%===================================================================================================
function [integer_byte] = hex2int(hex_byte)

  integer_byte = 0;
  for index = 1:2
    if (hex_byte(index) == '0')
      integer_nibble = 0;
    elseif (hex_byte(index) == '1')
      if (index == 1)
        integer_nibble = 16;
      else
        integer_nibble = 1;
      end
    elseif (hex_byte(index) == '2')
      if (index == 1)
        integer_nibble = 32;
      else
        integer_nibble = 2;
      end
    elseif (hex_byte(index) == '3')
      if (index == 1)
        integer_nibble = 48;
      else
        integer_nibble = 3;
      end
    elseif (hex_byte(index) == '4')
      if (index == 1)
        integer_nibble = 64;
      else
        integer_nibble = 4;
      end
    elseif (hex_byte(index) == '5')
      if (index == 1)
        integer_nibble = 80;
      else
        integer_nibble = 5;
      end
    elseif (hex_byte(index) == '6')
      if (index == 1)
        integer_nibble = 96;
      else
        integer_nibble = 6;
      end
    elseif (hex_byte(index) == '7')
      if (index == 1)
        integer_nibble = 112;
      else
        integer_nibble = 7;
      end
    elseif (hex_byte(index) == '8')
      if (index == 1)
        integer_nibble = 128;
      else
        integer_nibble = 8;
      end
    elseif (hex_byte(index) == '9')
      if (index == 1)
        integer_nibble = 144;
      else
        integer_nibble = 9;
      end
    elseif (hex_byte(index) == 'a')
      if (index == 1)
        integer_nibble = 160;
      else
        integer_nibble = 10;
      end
    elseif (hex_byte(index) == 'b')
      if (index == 1)
        integer_nibble = 176;
      else
        integer_nibble = 11;
      end
    elseif (hex_byte(index) == 'c')
      if (index == 1)
        integer_nibble = 192;
      else
        integer_nibble = 12;
      end
    elseif (hex_byte(index) == 'd')
      if (index == 1)
        integer_nibble = 208;
      else
        integer_nibble = 13;
      end
    elseif (hex_byte(index) == 'e')
      if (index == 1)
        integer_nibble = 224;
      else
        integer_nibble = 14;
      end
    elseif (hex_byte(index) == 'f')
      if (index == 1)
        integer_nibble = 240;
      else
        integer_nibble = 15;
      end
    end
    integer_byte = integer_byte + integer_nibble;
  end
end
