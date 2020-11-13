% We will use these two files:
% ---------------------------
% ecgdemodata1.mat
% 130-2_c4.asc.txt

%% clean up

clear variables
close all
clc
format compact

%% ECG
clear
load('ecg/ecgdemodata1.mat')
ECG = fft(ecg);
plot(ECG) %complex numbers!
plot(abs(ECG)) % abs(a+ib) => sqrt(a^2 + b^2)
plot(log(abs(ECG))) % large dynamic range along vertical axis, use log
semilogy(abs(ECG))  
semilogy(fftshift(abs(ECG))) %fft shift, so zero frequency in the middle

%%
%offset
ECG(1)
sum(ecg)
% see help fft
%                     N
%       X(k) =       sum  x(n)*exp(-j*2*pi*(k-1)*(n-1)/N), 1 <= k <= N.
%                    n=1
% When k=1 ==> 
%                     N
%       X(1) =       sum  x(n)
%                    n=1
% so ECG(1) is equal sum(ecg)

mean(ecg)
ECG(1)/length(ecg)

ecg0=ecg-mean(ecg); %remove the mean
ECG0=fft(ecg0); 

plot(fftshift(abs(ECG0))) %this does not have "zero frequency"

%% EEG 
close all; clear all
eeg=importdata('eeg/130-2_c4.asc.txt');
subplot(311);
plot(eeg)
EEG=fft(eeg);
subplot(312);
semilogy(fftshift(abs(EEG)))

%% moving Fourier
ftsum=@(x) sum(abs(fft(x))); % define an inline function
% apply the function to blocks of the input
ffteeg = blkproc(eeg,[50 1],ftsum);  %block <--> blk
% we applied ftsum to 50 elements of the signal
% apply it to 1-50, to 2-51, 3-52, etc. and report the values
subplot(313);
plot(ffteeg);


