% a)
s = tf('s');
% Define parameters
M = 0.05;   % Cart mass (kg)
m = 0.04;   % Pendulum mass (kg)
b = 0.02;   % Friction coefficient (kg/s)
g = 9.81;   % Gravity (m/s^2)
L = 0.15;   % Pendulum length (m)

H = s/((-1/6)*(4*M+m)*L*s^3-(2/3)*L*b*s^2+g*(M+m)*s+g*b);

opts = bodeoptions('cstprefs');
opts.PhaseWrapping = 'on';
bode(H, 'b', opts); % Plot SYS1 in blue
title('Bode Diagram of System');
grid on;

% Define the transfer function
% numerator = [1,0]; % Since the numerator is just 's'
% denominator = [-(1/6)*(4*M + m)*L, -(2/3)*L*b, g*(M + m), g*b];
% H = tf(numerator, denominator);
% 
% % Plot the Bode diagram
% figure;
% bode(H);
% title('Bode Diagram of the Inverted Pendulum System');

% Calculate and display the poles
poles = pole(H);
zeros = zero(H);
disp('Zero of the system:');
disp(zeros);
disp('Poles of the system:');
disp(poles);

% Determine system stability
if all(real(poles) < 0)
    disp('The system is stable.');
else
    disp('The system is unstable.');
end

%% b)

% Define the controllers
C1 = 1;
C2 = -0.55;

% Define the open-loop transfer functions
OL1 = C1 * H;
OL2 = C2 * H;

%%

% Plot the Nyquist plots of the open loops
figure;
nyquist(OL1);
legend('C1H')
title('Nyquist Plot of Open Loop C1H');
% grid on;

figure;
nyquist(OL2);
title('Nyquist Plot of Open Loop C2H');
legend('C2H');
% grid on;


% Check the step responses of the system
%% Simulate
out = sim('closed_loop_model_3_2');
%% Plot
% Plot the step response of the first closed-loop system
figure;
plot(out.tout, out.output);
title('Step Response of Closed Loop C1H');
xlabel('Time');
ylabel('Output');
grid on;

% Plot the step response of the second closed-loop system
figure;
plot(out.tout, out.output1);
title('Step Response of Closed Loop C2H');
xlabel('Time');
ylabel('Output');
grid on;


%% Designing a stabilizing controller 




