
t = linspace(0,20, length(d(52104:69725)));
% Error 
plot(t',closed_loop_error(52104:69725), 'Color', [0, 1, 0, 1], 'LineWidth', 1); % Blue line for Untuned_error with alpha value 0.5
xlabel('Time (seconds)'); % Adjust the x-label to represent time in seconds
ylabel('Error (radians)');
title('Feedforward Tuning');


grid on
hold on 

%%
t = linspace(0,20, length(d(3213:20834)));
% Error 
plot(t',d(3213:20834), 'Color', [0, 1, 0, 1], 'LineWidth', 1); % Blue line for Untuned_error with alpha value 0.5
xlabel('Time (seconds)'); % Adjust the x-label to represent time in seconds
ylabel('Error (radians)');
title('Feedforward Tuning');


%%
%plot(t',Error_47, 'Color', [0, 1, 0, 1], 'LineWidth', 1);

% Tuned Kfc
plot(t',0.001*Reference, 'Color', [0, 0, 1, 0.5], 'LineStyle', '--', 'LineWidth', 1); % Red dashed line for Error_kfc with alpha value 0.5

plot(t',0.001*Velocity, 'Color', [1, 0, 0, 0.8], 'LineStyle', '--', 'LineWidth', 1);


yline(0.012)

hold on

yline(-0.012)



legend('RMS Error = 0.0056 with peak 0.0120', 'Reference', 'Velocity'); % Adding legends for each plot
