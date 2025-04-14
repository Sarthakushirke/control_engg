
t = linspace(0,20, length(Reference));
% Error  
plot(t',Stabilizing, 'Color', [0.5, 0, 0.5, 0.5], 'LineWidth', 1); % Blue line for Untuned_error with alpha value 0.5
xlabel('Time (seconds)'); % Adjust the x-label to represent time in seconds
ylabel('Error (radians)');
title('Minimal Trajector error');


grid on
hold on 

plot(t',Stabilizing_ff, 'Color', [0.651, 1, 1, 0.8], 'LineWidth', 1);

plot(t',Performance_ff, 'Color', [0.4, 1, 0, 1], 'LineWidth', 1);

% Tuned Kfc
plot(t',0.001*Reference, 'Color', [0, 0, 1, 0.8], 'LineStyle', '--', 'LineWidth', 1); % Red dashed line for Error_kfc with alpha value 0.5

plot(t',0.001*Velocity, 'Color', [1, 0, 0, 0.8], 'LineStyle', '--', 'LineWidth', 1);


yline(0.012, 'LineWidth', 1)

hold on

yline(-0.012, 'LineWidth', 1)


legend('RMS error = 0.0653', 'RMS error = 0.0599', 'RMS error = 0.0056','Reference','velocity'); % Adding legends for each plot
