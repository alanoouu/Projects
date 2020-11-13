%% fourier sinusoids
clear; close all;

%% create temporal signal
Ts=0.001; %second / sample
Fs=1/Ts; %sample / second
t=[0:Ts:10];% time samples in second
f=10.001; %freq in Hz
s1=sin(2*pi*f*t); %the samples

%% plot temporal signal
plot(s1);
xlabel('sample')
ylabel('value')

%%
plot(t,s1);
xlabel('time (sec)')
ylabel('value')
title('note 10 cycles per second')

%% calculate Fourier transform
S1=fft(s1);
whos %note: complex

%% plot spectrum
stem(abs(S1),'.'); 
xlabel('frequency')
ylabel('abs(S(f))');
title('spectrum sample')

%% Fixing the f axis - I
LS = length(S1);

% Fourier indices: 1,2,3,...,length(S1)
% Should be mapped to frequencies -Fs/2 to +Fs/2
%
% 1          ==> -Fs/2
% length(S1) ==> +Fs/2
%
%   "frequency" = m "index" + b;
% 
% -Fs/2 = m*1          + b  ==> m = -Fs/2 - b
% +Fs/2 = m*length(S1) + b  ==> Fs/2 = (-Fs/2-b)* LS + b
%                           ==> Fs/2 = -Fs/2*LS -b*LS +b
%                           ==> Fs(1/2+LS/2) = b*(1-LS)
%                           ==> b = Fs(1/2+LS/2)/(1-LS)
%                           ==> m = -Fs/2 - b                    
b =  Fs*(1/2+LS/2)/(1-LS);
m = -Fs/2 - b;
f = m * [1:LS] + b;

%%
% Or simply:
f=linspace(-Fs/2,Fs/2,length(S1));

plot(f,abs(S1));
xlabel('frequency');
ylabel('|S1(f)|');

%% Fixing the f axis - II

plot(f,fftshift(abs(S1)),'-');
xlabel('frequency');
ylabel('|S1(f)|');


%% Another sinusoid
f2=3; s2=sin(2*pi*f2*t);
S2=fft(s2);
hold on; plot(f,fftshift(abs(S2)),'r')

%% More...
f3=2.5; s3=sin(2*pi*f3*t);
f4=1.4; s4=sin(2*pi*f4*t);
f5=0.6; s5=sin(2*pi*f5*t);

sall=s1+s2+s3+s4+s5;
hold off;
plot(sall)

%% Let's add a "constant" 

SALL = fft(sall);
plot(f,fftshift(abs(SALL)),'r')

sall=sall+10;
SALL = fft(sall);
plot(f,fftshift(abs(SALL)),'r')