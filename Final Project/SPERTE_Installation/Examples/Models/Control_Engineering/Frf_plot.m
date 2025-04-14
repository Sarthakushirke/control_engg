%%

input_2 = d;
output_2 = y;
nfft_1 = 100000;
noverlap_1 = nfft_1/2;
nfft_2 = 2000;
noverlap_2 = nfft_2/2;  
nfft_3 = 12000;
noverlap_3 = nfft_3/2;

Fs = 4000;

window_1 = hann(nfft_1);  
[H_1,hz_1] = tfestimate(input_2,output_2,window_1,noverlap_1,nfft_1,Fs);

window_2 = hann(nfft_2);  
[H_2,hz_2] = tfestimate(input_2,output_2,window_2,noverlap_2,nfft_2,Fs);

window_3 = hann(nfft_3);  
[H_3,hz_3] = tfestimate(input_2,output_2,window_3,noverlap_3,nfft_3,Fs);

[cxy_1, c_1] = mscohere(input_2,output_2,window_1,noverlap_1,nfft_1, Fs);

[cxy_2, c_2] = mscohere(input_2,output_2,window_2,noverlap_2,nfft_2, Fs);

[cxy_3, c_3] = mscohere(input_2,output_2,window_3,noverlap_3,nfft_3, Fs);

mag_1 = abs(H_1);
phase_1 = rad2deg(angle(H_1));

mag_2 = abs(H_2);
phase_2 = rad2deg(angle(H_2));

mag_3 = abs(H_3);
phase_3 = rad2deg(angle(H_3));

%%
figure;

subplot(3,1,1);
plot1 = semilogx(hz_1, 20*log10(mag_1), 'Color', [0, 0, 1, 0.2]); % Blue color with alpha 0.05 (index 1)
hold on 
plot2 = semilogx(hz_2, 20*log10(mag_2), 'Color', [1, 0, 0, 0.8]); % Green color with alpha 0.8 (index 2)
hold on 
plot3 = semilogx(hz_3, 20*log10(mag_3), 'Color', [0, 1, 0, 1]); % Red color with alpha 1 (index 3)
ylabel('Magnitude [dB]')
grid on
legend([plot1, plot2, plot3], '$F_r$ = 0.04 Hz', '$F_r$ = 2 Hz', '$F_r$ = 0.33 Hz', 'Interpreter', 'latex');
title('FRF Measurement');
subplot(3,1,2);
plot1 = semilogx(hz_1, phase_1, 'Color', [0, 0, 1, 0.2]); % Blue color with alpha 0.05 (index 1)
hold on
plot2 = semilogx(hz_2, phase_2, 'Color', [ 1, 0, 0, 0.8]); % Green color with alpha 0.8 (index 2)
hold on
plot3 = semilogx(hz_3, phase_3, 'Color', [0, 1, 0, 1]); % Red color with alpha 1 (index 3)
ylabel('\textbf{Phase} $ [^\circ]$','Interpreter', 'latex')
grid on


subplot(3,1,3);
plot1 = semilogx(hz_1, cxy_1, 'Color', [0, 0, 1, 1]); % Blue color with alpha 1 (index 1)
hold on
plot2 = semilogx(hz_2, cxy_2, 'Color', [1, 0, 0, 0.8]); % Green color with alpha 0.8 (index 2)
hold on
plot3 = semilogx(hz_3, cxy_3, 'Color', [0, 1, 0, 1]); % Red color with alpha 1 (index 3)
xlabel('Frequency [Hz]')
ylabel('Coherence')
grid on



