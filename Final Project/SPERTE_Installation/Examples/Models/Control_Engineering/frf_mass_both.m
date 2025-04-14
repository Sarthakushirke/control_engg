%% System 1
input1 = d1;
output1 = y1;

%% System 2
input2 = d;
output2 = y;

%% Common Parameters
nfft = 12000;
noverlap = nfft/2;  
Fs = 4000;
window = hann(nfft);  

%% Calculate TF Estimate and Coherence for System 1
[H1,hz1] = tfestimate(input1,output1,window,noverlap,nfft,Fs);
[cxy1, c1] = mscohere(input1,output1,window,noverlap,nfft, Fs);

mag1 = abs(H1);
phase1 = rad2deg(angle(H1));

%% Calculate TF Estimate and Coherence for System 2
[H2,hz2] = tfestimate(input2,output2,window,noverlap,nfft,Fs);
[cxy2, c2] = mscohere(input2,output2,window,noverlap,nfft, Fs);

mag2 = abs(H2);
phase2 = rad2deg(angle(H2));

%% Plotting
figure; 

subplot(3,1,1);
semilogx(hz1, 20*log10(mag1), hz2, 20*log10(mag2));
ylabel('Magnitude[dB]')
grid on
legend('Non-colocated System', 'Colocated mass system')

subplot(3,1,2);
semilogx(hz1, phase1, hz2, phase2);
ylabel('Phase[degrees]')
grid on
legend('Non-colocated System', 'Colocated mass system')

subplot(3,1,3);
semilogx(hz1, cxy1, hz2, cxy2)
xlabel('Frequency[Hz]')
ylabel('Coherence[-]')
grid on
legend('Non-colocated System', 'Colocated mass system')
