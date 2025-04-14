s = tf('s');
H1 = (s+2)^2/(s^2*(s+3)*(s^2+s+25)); % F to x1
H2 = (s+2)^2/(s^2*(s+3)*(s^2+s+25)); % F to x2

% Plot the Bode plot with logarithmic frequency and magnitude axes
bode(H1);
hold on; % Hold the plot
bode(H2);
legend('H1', 'H2'); % Add legend
