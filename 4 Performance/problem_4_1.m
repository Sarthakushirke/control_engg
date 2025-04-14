load('modl.mat')

%% Construct the system

SYS = ss(al,bl,cl,dl);

figure;

opts = bodeoptions('cstprefs');
opts.PhaseWrapping = 'on';
bode(SYS, 'b', opts); % Plot SYS1 in blue
title('Bode Diagram of System 1');
grid on;