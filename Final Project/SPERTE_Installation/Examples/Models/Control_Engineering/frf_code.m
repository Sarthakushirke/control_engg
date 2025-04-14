%%

input = d;
output = y;
nfft = 12000;
noverlap = nfft/2;  

Fs = 4000;
window = hann(nfft);  
[H,hz] = tfestimate(input,output,window,noverlap,nfft,Fs);


[cxy, c] = mscohere(input,output,window,noverlap,nfft, Fs);

mag = abs(H);
phase = rad2deg(angle(H));

figure; 
subplot(2,1,1);

semilogx(hz, 20*log10(mag),'b','LineWidth', 1);

ylabel('Magnitude[dB]')

grid on

P2 = subplot(2,1,2);

semilogx(hz,phase,'b','LineWidth', 1);

ylabel('Phase[degrees]')
grid on

% P3 = subplot(3,1,3);
% 
% semilogx(hz,cxy,'b','LineWidth', 1)
% xlabel('Frequency[Hz]')
% ylabel('Coherence[-]')
% grid on



%% Controller plot shapeit and 
% Additional steps for overlaying bode plot of shapeit_data.C_tf
% Assuming shapeit_data.C_tf is a transfer function model compatible with bode function
[magB,phaseB,wout] = bode(shapeit_data.C_tf, 2*pi*hz); % Getting magnitude and phase at your frequencies

% Convert magB to dB and phaseB to degrees, note that bode gives mag in abs and phase in degrees
magB_db = 20*log10(squeeze(magB));
phaseB_deg = squeeze(phaseB);

% Overlay on existing plots
subplot(2,1,1); % Magnitude plot
hold on; % Keep existing plot
semilogx(hz, magB_db, 'r','LineWidth', 1); % Overlay Bode magnitude in red dashed line
legend('Discrete controller', 'Continuous (shapeit)')

subplot(2,1,2); % Phase plot
hold on; % Keep existing plot
semilogx(hz, phaseB_deg, 'r','LineWidth', 1); % Overlay Bode phase in red dashed line
legend('Discrete controller', 'Continuous (shapeit)')