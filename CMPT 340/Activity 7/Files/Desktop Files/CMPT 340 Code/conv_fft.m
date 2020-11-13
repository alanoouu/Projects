%% impulse response, convolution, fourier

%% clean up

clear variables; close all;
clc; format compact

%% system response

inp = [1 0 0 0 0 0 1];  % input (happens to be an impulse)
%inp = [10 0 2]; % another input 
%inp = [5 9 3]; % gradualy make inp and sys more complicated... 
sys = [3 2 1];  % impulse respose

out=conv(inp,sys)
plot(out,'--*')
hold on
stem(out,'*')

%% convolution <-> multiplication, and inverse
s1=rand(1,4)
s2=rand(1,4)

fs1=fft(s1);
fs2=fft(s2);

m1=conv(s1,s2,'same')
m2=ifft(fs1.*fs2)

% pad
% why? 
%  when signal is aperiodic, its Fourier is continuous.
%  but we can't represent continuous Fourier in matlab
%  we need a discrete version of the fourier.
%  this means we need to sample the Fourier
%  sampling the Fourier (mult. by comb), creates copies of the signal.
%  we don't want the signal copies to overlap, so we pad #

s1p=[s1 zeros(1,length(s2)-1)]
s2p=[s2 zeros(1,length(s1)-1)]

fs1p=fft(s1p); plot(s1p,'r');hold on
fs2p=fft(s2p); plot(s2p,'b')

m3=conv(s1p,s2p)
m4=ifft(fs1p.*fs2p)
%compare m3 and m4, should be equal aside from other 0s
figure; plot(m3,'go--');hold on; plot(m4,'*k-')

%% timing fourier vs. convolution
N=100000;
tic;   a=conv(rand(N,1),rand(N,1));   toc
tic;   ifft(fft(rand(N,1)).*fft(rand(N,1)));  toc

