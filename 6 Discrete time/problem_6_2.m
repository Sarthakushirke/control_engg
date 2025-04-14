% a) Lead filter
s = tf('s');
f1 = 10; % 40 Hz
f2 = 100;

Lead = ((1/(2*pi*f1))*s+1)/((1/(2*pi*f2))*s+1);

% Sampling frequency
fs = 500; % Hz
Ts = 1/fs;

% Discretize the lead filter using different methods
methods = {'zoh', 'foh', 'tustin', 'prewarp', 'matched'};

figure;
hold on;
for i = 1:length(methods)
    if strcmp(methods{i}, 'prewarp')
        % Choose the critical frequency based on your requirements
        fc = 500;% Specify the critical frequency here
        syszoh = c2d(Lead, Ts, methods{i}, fc);
    else
        syszoh = c2d(Lead, Ts, methods{i});
    end
    bode(syszoh);
end
bode(Lead, 'b'); % Plot the continuous-time lead filter in blue
legend(methods{:}, 'Continuous-Time');
title('Bode Diagram of Discrete-Time Lead Filters');
hold off;


%% b) Adding a Notch filter 
s = tf('s');
f1 = 200; % Hz
f2 = 200; % Hz (same as f_notch)
beta1 = 0.0005;
beta2 = 0.01;

C = ((1/(2*pi*f1)^2)*s^2 + (2*beta1/(2*pi*f1))*s + 1) / ((1/(2*pi*f2)^2)*s^2 + (2*beta2/(2*pi*f2))*s + 1);

Final = Lead + C;

% Sampling frequency
fs = 1000; % Hz
Ts = 1/fs;

% Discretize the lead filter using different methods
methods = {'zoh', 'foh', 'tustin', 'prewarp', 'matched'};

figure;
hold on;
for i = 1:length(methods)
    if strcmp(methods{i}, 'prewarp')
        % Choose the critical frequency based on your requirements
        fc = 500;% Specify the critical frequency here
        syszoh = c2d(Final, Ts, methods{i}, fc);
    else
        syszoh = c2d(Final, Ts, methods{i});
    end
    bode(syszoh);
end
bode(Final, 'b'); % Plot the continuous-time lead filter in blue
legend(methods{:}, 'Continuous-Time');
title('Bode Diagram of Discrete-Time Lead Filters');
hold off;

%% c) 
