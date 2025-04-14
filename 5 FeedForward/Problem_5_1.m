s = tf('s');

F = (1000*3202)/(s^2*(s^2+20*s+3202));

opts = bodeoptions('cstprefs');
opts.PhaseWrapping = 'on';
bode(F, 'b', opts);
title('Bode Diagram of System');