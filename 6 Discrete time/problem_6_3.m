% Define the length of the moving average filter
N = 10;

% Define the numerator coefficients of the transfer function
Denominator_coeffs = ones(1, N);

% Compute the transfer function
H = tf(N, Denominator_coeffs);

% Plot the frequency response (magnitude and phase)
figure;
bode(H);
title('Frequency Response of Moving Average Filter');
grid on;

%%
% Compute and plot the poles and zeros
figure;
pzplot(H);
title('Poles and Zeros of Moving Average Filter');
grid on;
