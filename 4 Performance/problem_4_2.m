load('controller_4_2.mat')
    
%% Apply disturbance and check the response

% Define the sampling frequency and time vector
fs = 1000; % Sampling frequency (Hz)
t = 0:1/fs:1; % Time vector from 0 to 1 second with 1/fs increment

% Generate the sine wave
A = 1; % Amplitude
f = 2; % Frequency (Hz)
x = A * sin(2*pi*f*t);

% Plot the sine wave
% plot(t, x);
% xlabel('Time (s)');
% ylabel('Amplitude');
% title('Sine Wave with Amplitude 1 and Frequency 2 Hz');
%% Transfer function from d to e

e = (shapeit_data.P.sys/(1+(shapeit_data.P.sys*shapeit_data.C_tf)))*x;


%% Run the simulink model 

out = sim('simulink_4_2');

%% Plot the output/response from the simulink model 

plot(out.tout,out.output)


