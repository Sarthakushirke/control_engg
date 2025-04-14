
% H = tf([1 2 4],[1 4 28 75 0]);

s = tf('s');
H = (s+2)^2/(s^2*(s+3)*(s^2+s+25));
% Plot the Bode plot with logarithmic frequency and magnitude axes
bode(H);
%%  omega --> 0
%When the omega --> 0 the value that we get is the start of the bode plot
%but we need to convert it to db
db = 20*log10(1/25);

























%% System Identification (FRF)
% mag = abs(H);
% phase = rad2deg(angle(H));
% 
% figure; 
% subplot(3,1,1);
% 
% semilogx(hz, 20*log10(mag));
% 
% ylabel('Magnitude[dB]')
% 
% grid on
% 
% P2 = subplot(3,1,2);
% 
% semilogx(hz,phase);
% 
% ylabel('Phase[degrees]')
