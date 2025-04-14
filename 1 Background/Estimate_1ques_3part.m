%LOAD H1 and H2
load("Background\frfdata.mat")
%%
% System1 H1
mag1 = abs(H1);
phase1 = rad2deg(angle(H1));

% System2 H2
mag2 = abs(H2);
phase2 = rad2deg(angle(H2));

%% Plot 

figure; 

% Magnitude plot
ax1 = subplot(2,1,1);
semilogx(hz, 20*log10(mag1));
hold on;
semilogx(hz, 20*log10(mag2));
ylabel('Magnitude [dB]')
legend('System1', 'System2');
grid on;

% Phase plot
ax2 = subplot(2,1,2);
semilogx(hz, phase1);
hold on;
semilogx(hz, phase2);
ylabel('Phase [degrees]')
xlabel('Frequency [Hz]')
grid on;

linkaxes([ax1,ax2],'x')

%% Use pathtool to add the frffit folder which is Program files --> Matlab --> Toolbox

%For system 1
[a1,b1,c1,d1] = frsfit(H1,hz,[8,3,0],0);

%For system 2
[a2,b2,c2,d2] = frsfit(H2,hz,[6,4,0],0);

%% Create a system using ss command

SYS1 = ss(a1,b1,c1,d1);

SYS2 = ss(a2,b2,c2,d2);

%% Create a system from the obtained model parameters (e.g. by using ss.m or tf.m).
%Plot your systems together with the data in a Bode diagram and comment on them.

figure;

subplot(2,1,1);
opts = bodeoptions('cstprefs');
opts.PhaseWrapping = 'on';
bode(SYS1, 'b', opts); % Plot SYS1 in blue
title('Bode Diagram of System 1');
grid on;

subplot(2,1,2);
bode(SYS2, 'r', opts); % Plot SYS2 in red
title('Bode Diagram of System 2');
grid on;



legend('System 1', 'System 2');





