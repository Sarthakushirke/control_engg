%System H1 and H2
s = tf('s');

H1 = 1000*((s+6)/(s^3+20*s^2+5000*s));

H2 = 1000*((s-6)/(s^3+20*s^2+5000*s));

figure;
bode(H1)
title('Bode Plot of System H1');

figure;
bode(H2)
title('Bode Plot of System H2');

%% Design the controller C1 for H1

%check the shapeit "shapeit_controller_3_3.fig"

%% Design the controller C1 for H1 and C1 for H2

out = sim('open_loop_CH_model_3_3');

%% Verify the result by checking the time response plot

plot(out.tout,out.output)