%===================================================================================================
% L-3 Cincinnati Electronics Proprietary
%===================================================================================================
% File Name: plot_data.m
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
function plot_data(expect_path, source_path, target_path, data_name)

  expect_file = sprintf('%s%s%s', expect_path, data_name, '.txt');
  source_file = sprintf('%s%s%s', source_path, data_name, '.txt');
  
  expect_data = load(char(expect_file));
  source_data = load(char(source_file));

  expect_size = size(expect_data);
  source_size = size(source_data);

  if (expect_size(1) < source_size(1))
    data_length = expect_size(1);
  else
    data_length = source_size(1);
  end

  error = expect_data(1:data_length) - source_data(1:data_length);

  for i=1:length(data_name)
    if (data_name(i) == '_')
      title_name(i) = ' ';
    else
      title_name(i) = data_name(i);
    end
  end

  fig_hndl = figure;
  clf;

  subplot(2,1,1);
  plot(expect_data(1:data_length), 'b');
  hold on;
  plot(source_data(1:data_length), 'm');
  title(title_name);
  legend('Expect', 'Source');

  subplot(2,1,2);
  plot(error, 'g');
  title('Difference');

  set(fig_hndl, 'Name', data_name);

%   target_file = sprintf('%s%s%s', target_path, data_name, '.fig');
%   saveas(gcf, target_file);
end
