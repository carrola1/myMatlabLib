%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: plot_fft.m
%
% Description: This function reads two files and plots the difference.
%
% Inputs:
%   expect_path: Full path of the expect data file
%   source_path: Full path of the source data file
%   target_path: Full path of the plot capture file
%   data_name: File identifier for the vectors to be compared
%
% Outputs:
%   None
%
% Dependencies:
%   None
%===================================================================================================
function plot_fft(expect_path, source_path, target_path, data_name)

  expect_file = sprintf('%s%s%s', expect_path, data_name, '.txt');
  source_file = sprintf('%s%s%s', source_path, data_name, '.txt');
  
  expect_data = load(char(expect_file));
  source_data = load(char(source_file));

  expect_size = size(expect_data);
  source_size = size(source_data);

  % Take FFT
  [fExp,ampExp] = myFft(expect_data,1,1,'Hz',0);
  [fSrc,ampSrc] = myFft(source_data,1,1,'Hz',0);
  
  for i=1:length(data_name)
    if (data_name(i) == '_')
      title_name(i) = ' ';
    else
      title_name(i) = data_name(i);
    end
  end
  
  title_name = sprintf([title_name ' FFT']);

  fig_hndl = figure;
  clf;

  plot(ampSrc, 'm');
  hold on;
  plot(ampExp, 'b');
  title(title_name);
  ylabel('Magnitude dB');
  legend('Source', 'Expect');
  axis([0 length(ampExp) min(ampExp)-2 max(ampExp)+2]);

  set(fig_hndl, 'Name', data_name);

%   target_file = sprintf('%s%s%s', target_path, data_name, '.fig');
%   saveas(gcf, target_file);
end
