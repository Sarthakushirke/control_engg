% a) Simulink model  (Three point method)

model_out = sim('frf_ex3');

%%  b) Determine the sensitivity of the closed loop system by performing an FRF measurement

input =  disturbance;
output =  input_u;
nfft = 5000;
noverlap = nfft/2;  
Fs = 1000;
window = hann(nfft);  
[H,hz] = tfestimate(input,output,window,noverlap,nfft,Fs);

[cxy, c] = mscohere(input,output,window,noverlap,nfft, Fs);

mag = abs(H);
phase = rad2deg(angle(H));

figure; 
subplot(3,1,1);

semilogx(hz, 20*log10(mag));

ylabel('Magnitude[dB]')

grid on

P2 = subplot(3,1,2);

semilogx(hz,phase);

ylabel('Phase[degrees]')
grid on

P3 = subplot(3,1,3);

semilogx(hz,cxy)
xlabel('Frequency[Hz]')
ylabel('Coherence[-]')
grid on


%% c) o determine the process sensitivity of the closed loop

input_1 =  disturbance;
output_1 =  error_1;
  
[H_1,hz_1] = tfestimate(input_1,output_1,window,noverlap,nfft,Fs);

[cxy_1, c_1] = mscohere(input_1,output_1,window,noverlap,nfft, Fs);

mag_1 = abs(H_1);
phase_1 = rad2deg(angle(H_1));

figure; 
subplot(3,1,1);

semilogx(hz_1, 20*log10(mag_1));

ylabel('Magnitude[dB]')

grid on

P4 = subplot(3,1,2);

semilogx(hz_1,phase_1);

ylabel('Phase[degrees]')
grid on

P5 = subplot(3,1,3);

semilogx(hz_1,cxy_1)
xlabel('Frequency[Hz]')
ylabel('Coherence[-]')
grid on

%% d) How can you determine the plant dynamics using only sensitivity and process sensitivity
plant = H_1/H;

mag_p = abs(plant);
phase_p = rad2deg(angle(plant));

figure;

% Plot for magnitude
subplot(4,1,1);
semilogx(hz_1, 20*log10(mag_p));
ylabel('Magnitude[dB]');
grid on;
title('Magnitude Response of Plant');

% Plot for phase
subplot(4,1,2);
semilogx(hz_1, phase_p);
ylabel('Phase[degrees]');
grid on;
title('Phase Response of Plant');

% Plot for coherence
subplot(4,1,3);
semilogx(hz, cxy);
xlabel('Frequency[Hz]');
ylabel('Coherence[-]');
grid on;
title('Coherence - Senstivity');

% Plot for coherence (Modified System)
subplot(4,1,4);
semilogx(hz_1, cxy_1);
xlabel('Frequency[Hz]');
ylabel('Coherence[-]');
grid on;
title('Coherence -  Process Sensitvity');

sgtitle('Frequency Response Analysis'); % Overall title for the figure
