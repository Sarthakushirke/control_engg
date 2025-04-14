%%
%Calculate the error
% 9s trajector constant velocity range :- 75669:89736
% 11s trajector constant velocity range :- 45606:64408
% 12s trajector constant velocity range :- 52104:69725
cum_err_1 = [];
for i= 52104:69725
    % cum_err_1 = [cum_err_1;Basic_feedforward_error(i)];
    cum_err_1 = [cum_err_1;closed_loop_error(i)];
end
rms(cum_err_1)
max(cum_err_1)

%%
cum_err_2 = [];
for i= 52104:69725
    cum_err_2  = [cum_err_2 ;robust_error(i)];
end
rms(cum_err_2 )
max(cum_err_2 )

%%
nfft = 8000; %5000;
noverlap = nfft/2;

Fs = 4000;
window = hann(nfft);  

% [pxx_1, y_1] = pwelch(closed_loop_error, window, noverlap, nfft, Fs, "onesided", "psd");
[pxx_1, y_1] = pwelch(Basic_feedforward_error, window, noverlap, nfft, Fs, "onesided", "psd");
[pxx_2, y_2] = pwelch(robust_error, window, noverlap, nfft, Fs, "onesided", "psd");
subplot(3,1,1)
semilogx(y_1, pow2db(pxx_1),'Color', [1, 0, 0, 1], 'LineWidth', 1)
hold on 
semilogx(y_2, pow2db(pxx_2),'Color', [0, 1, 0, 1], 'LineWidth', 1)
grid on;
title('PSD of Error - Basic feedforward and performance feedforward controller')
%ylabel('$\mathrm{rad^2/Hz}$', 'Interpreter', 'latex');
ylabel('$\mathrm{db}$', 'Interpreter', 'latex');
xlabel('Frequency[Hz]');
legend('RMS Error = 0.0135', 'RMS Error = 0.0031');

%% CPSD

Camp_1 = cumsum(pxx_1);
Camp_2 = cumsum(pxx_2);
subplot(3,1,2)
semilogx(y_1,Camp_1, 'Color', [1, 0, 0, 1], 'LineWidth', 1)
hold on
semilogx(y_2,Camp_2,'Color', [0, 1, 0, 1], 'LineWidth', 1)
grid on;
ylabel(' rad');
xlabel('Frequency [Hz]')
title('Cumulative amplitude spectrum')

iPxx_1 = flip(pxx_1);
iCamp_1 = cumsum(iPxx_1);
iPxx_2 = flip(pxx_2);
iCamp_2 = cumsum(iPxx_2);
subplot(3,1,3)
iCamp_1 = flip(iCamp_1);
iCamp_2 = flip(iCamp_2);
semilogx(y_1,iCamp_1, 'Color', [1, 0, 0, 1], 'LineWidth', 1)
hold on
semilogx(y_2,iCamp_2, 'Color', [0, 1, 0, 1], 'LineWidth', 1)
grid on;
ylabel('rad');
xlabel('Frequency [Hz]')
title('Inverse of Cumulative amplitude spectrum')


