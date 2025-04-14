%% Notch filter 
s = tf('s');
f1 = 40; % 40 Hz
f2 = 40;
beta1 = 0.01*10; %Damping for zeros
beta2 = 1; %Damping for poles

F = ((1/(2*pi*f1)^2)*s^2 + (2*beta1/(2*pi*f1))*s +1) / ((1/(2*pi*f2)^2)*s^2 + (2*beta2/(2*pi*f2))*s +1);

bode(F);


%%
% a) First the run the "ques_2_1_notch_simulink.slx" to get the input and the
% output

out = sim('ques_2_1_notch_simulink');
%%
% b) Compare the filter response with its input in time domain. Do
%you see any difference? :- I can't spot any difference

% Load the input and output signals from the MATLAB workspace
% First do "a".

% Plot the input and output signals
figure;
subplot(2,1,1);
plot(out.tout, out.Input_notch_filter.Data, 'DisplayName', 'Input Signal'); % Specify legend label
title('Input Signal');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Location', 'best'); % Add legend

subplot(2,1,2);
plot(out.tout, out.Output_notch_filter.Data, 'DisplayName', 'Output Signal'); % Specify legend label
title('Output Signal');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Location', 'best'); % Add legend


%% c) Compare the input and output in frequency domain by calculating their auto power

% Extract data arrays from time-series signals
input_data = out.Input_notch_filter.Data;
output_data = out.Output_notch_filter.Data;

fs = 1/0.001;

% Compute the power spectral density (PSD) estimates
[input_psd, input_freq] = pwelch(input_data,400,[],[],fs);
[output_psd, output_freq] = pwelch(output_data,400,[],[],fs);

% Plot the PSD estimates
figure;
subplot(2,1,1);
plot(input_freq, 10*log10(input_psd)); % Plot PSD of input signal
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
title('Input Signal Power Spectral Density');

subplot(2,1,2);
plot(output_freq, 10*log10(output_psd)); % Plot PSD of output signal
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
title('Output Signal Power Spectral Density');



%%  d) Determine the FRF of the notch filter using the ratio between the appropriate cross and
%auto power spectral densities 

%cross power of 2 signals
[cpsd_1, freq] = cpsd(input_data,output_data,400,[],[],fs);

ratio_tf = cpsd_1./input_psd;

% Plot the cross power spectral density (CPSD) estimate
figure;
plot(freq, abs(cpsd_1));
xlabel('Frequency (Hz)');
ylabel('Cross Power Spectral Density');
title('Cross Power Spectral Density Estimate between Input and Output Signals');

% Plot the transfer function
figure;
plot(freq, mag2db(abs(ratio_tf)));
xlabel('Frequency (Hz)');
ylabel('Transfer Function');
title('Transfer Function of Notch Filter');



%% d) Using tfestimate and coherence.

input =  out.Input_notch_filter.Data;
output =  out.Output_notch_filter.Data;
nfft = 5000;
noverlap = nfft/2;  

Fs = fs;
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


