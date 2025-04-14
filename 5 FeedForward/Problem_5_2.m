% Define the number of pulses per revolution
pulses_per_revolution = 8000;

% Calculate the resolution in radians
resolution_rad = 2*pi / pulses_per_revolution;

% Display the result
disp(['Resolution of the measurements in radians: ', num2str(resolution_rad), ' rad']);
