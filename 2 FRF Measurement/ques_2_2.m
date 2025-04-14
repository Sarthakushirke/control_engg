%% Frequency Response Function of a mass system (Two-point method)
%Plant with a simple mass 
% a)
m = 1; %kg
s = tf('s');
H = 1/(m*s^2);

opts = bodeoptions('cstprefs');
opts.PhaseWrapping = 'on';
bode(H, 'b', opts); % Plot SYS1 in blue
title('Bode Diagram of System 1');

%%
% calculate appropriate P and D so that the bandwidth (cross-over frequency of the open loop C(s)H(s)) is 10 Hz
c = (s+10)*8;

open_loop = c*H;

bode(open_loop, 'b', opts); % Plot SYS1 in blue

grid on

%% b) Create a Simulink model with a 1 kg mass and your calculated PD-controller. Inject 
% a noise signal in the closed loop just behind the controller block

model_out = sim('ques_2_2_simulink');

%% c) Study these signals in both time and frequency domain

% Plot the input and output signals in time domain 
figure;
subplot(2,1,1);
plot(model_out.tout, model_out.input.Data, 'DisplayName', 'Input Signal'); % Specify legend label
title('Input Signal');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Location', 'best'); % Add legend

subplot(2,1,2);
plot(model_out.tout, model_out.output.Data, 'DisplayName', 'Output Signal'); % Specify legend label
title('Output Signal');
xlabel('Time (s)');
ylabel('Amplitude');
legend('Location', 'best'); % Add legend

% frequency domain 
% Extract data arrays from time-series signals
input_data = model_out.input.Data;
output_data = model_out.output.Data;

fs = 1/0.001;

% Compute the power spectral density (PSD) estimates
[input_psd, input_freq] = pwelch(input_data,400,[],[],fs);
[output_psd, output_freq] = pwelch(output_data,400,[],[],fs);

% Plot the PSD estimates
figure;
subplot(2,1,1);
semilogx(input_freq, 10*log10(input_psd)); % Plot PSD of input signal
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
title('Input Signal Power Spectral Density');

subplot(2,1,2);
semilogx(output_freq, 10*log10(output_psd)); % Plot PSD of output signal
xlabel('Frequency (Hz)');
ylabel('Power/Frequency (dB/Hz)');
title('Output Signal Power Spectral Density');


%% d) Using tfestimate and coherence.

input =  model_out.input.Data;
output =  model_out.output.Data;
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


