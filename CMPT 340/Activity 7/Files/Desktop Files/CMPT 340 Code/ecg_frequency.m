%% Biosignal (ECG) - frequency analysis
% We examine how to analyze a 1D ECG signal in the frequency domain.
% At each point in time we have a single value measuring the electrical activity.

%% How to run this demo
% You can download the datasets from canvas

%%
% Download the below files and re-create the directory structure given below.
%
%   /ecg_frequency.m
%   /ecg/ecgdemodata1.mat

clear all; close all;
% Create a directory for the GIFs.
mkdir(fullfile(pwd,'html'))

%% Load and plot the ECG data.
ecgNamePath = fullfile(pwd,'ecg','ecgdemodata1.mat');
ecgStruct = load(ecgNamePath);
ecg = ecgStruct.ecg;

% This is the complete signal in the time domain.
figure; plot(ecg); xlabel('time'); ylabel('electrical activity');


%% Fourier Transform of the signal
% Let us look at the ECG in the fourier domain.
% One command in matlab!
% FFT: Fast Fourier Transform

ftecg = fft(ecg);

% Note that temporal domain and the fourier domain are the same size.
size(ecg)
size(ftecg)
%%

% So what does the fourier look like? Examine the first 5 values.
ftecg(1:5)'

%% Fourier Transform is Complex

% Aside from the first entry, the values are complex numbers
% with both real and imaginary parts.

% We can examine a complex number in more detail.
% For example, look at the 3rd value, and some other simple examples

real(ftecg(3))
imag(ftecg(3))
abs(ftecg(3)) %  sqrt(real(ftecg(3))^2 + imag(ftecg(3))^2)
angle(ftecg(3))
%%

% Look at some simple examples:

real(1+2j)
imag(1+2j)
abs(3+4j) % sqrt(3^2 + 4^2)
angle(1+2j)*180/pi
angle(1+1j)*180/pi
angle(0+1j)*180/pi

%% Plotting the Fourier Transform

% Okay, let's plot this to see what it looks like.
figure; plot(abs(ftecg)); xlabel('frequency'); ylabel('magnitude of fourier components');
%%

% Hmmm... not much to see here.. something in the bottom right and then if
% you look closely, a huge spike on the left.

% We can rearrage the output so that the zero-frequency component is in the
% middle using fftshift().

figure; plot(abs(fftshift(ftecg))); xlabel('frequency'); ylabel('magnitude of fourier components');

%% The zero frequency: The "constant" component of the signal
% Note that the zero frequency component captures the sum of the signal.
% If you look at help fft in matlab, you can easily see X(1)=sum(x)
% Other FFT definitions might have X(1) = mean(x)
sum(ecg)
ftecg(1)

% Note that ftecg folds.
abs(ftecg(2)) == abs(ftecg(end))
abs(ftecg(3)) == abs(ftecg(end-1))

% We can center the signal around zero, and note how the zero frequency
% component disapeares. Let's compare before (blue) and after (red),

% Subtract the mean to center at zero.
ecg0=ecg-mean(ecg);
figure; plot(ecg); hold on; plot(ecg0,'r'); title('ecg centered at zero');
%%
ftecg=fft(ecg);
figure; plot(abs(fftshift(ftecg)),'.--'); title('before mean subtract');
%%
ftecg0=fft(ecg-mean(ecg));
hold on; plot(abs(fftshift(ftecg0)),'r.--'); title('after mean subtract');
%%


%% Labelling the frequency (horizontal) axis, in Hz
%
% To fix the labels (frequencies in Hz) along the frequency (x-axis):
%%
%
% * we ensure the middle value in the vector after _fftshift()_ is at zero Hz
% * we have equal number of values on the left and right of the zero,
%   i.e. we must have an odd number of entries.
%   So, for even number, we pad an extra zero (but not when odd)
% * we assume Sampling frequency = 2 * Maximum Frequency (or Fmax=Fs/2)
%
% Also, let's make the values along the y-axis clearer by using a log-plot,
% _semilogy()_

% Check if there are an even number of signal values.
L = length(ecg);
if L/2 == round(L/2), % Even
    
    % This will automatically pad ecg with an extra 0.
    ftecg = fft(ecg, L+1);
    L=L+1;
end

% Get the rate that was used to sample this data.
Fs = ecgStruct.samplingrate;

% Generate L evenly spaced numbers between -0.5 and 0.5. Multiply by the
% Maximum Frequency.
f = linspace(-0.5 , 0.5 , L ) * Fs/2;

figure;
semilogy(f,fftshift(abs(ftecg)))
title('Amplitude Spectrum of y(t)')
xlabel('Frequency (Hz)')
ylabel('|ftecg(f)|')
grid on


%% Signal created by gradually adding more frequencies
% let's see how as we gradually add frequencies we can construct
% the original signal
fId = figure;
mask=zeros(1,length(ftecg));
for k=2:5:1000,
    % A value of 1 in the mask means use the frequencies. More details
    % on a similar example can be found in the examples below.
    mask(k)=1;
    mask(end-k+2)=1;
    ftecg_grad = ftecg.*mask;
    subplot(211);
    stem(log(fftshift(abs(ftecg_grad))));
    %axis([0 4.5e4 10^0 10^9]);
    subplot(212);
    plot(real(ifft(ftecg_grad)));
    hold on; plot(ecg,'r');hold off
    pause(0.001);
    
    %%%%%%%%%%%%%%%%%%
    % This is just for creating the gif.
    frame = getframe(fId); % Note that we're specifiying the frameId now.
    im = frame2im(frame);
    [A,map] = rgb2ind(im,256);
    
    filename = fullfile('html','ecg_add_freq.gif');
    if k == 2;
        imwrite(A,map,filename,'gif','LoopCount',Inf,'DelayTime',0.1);
    else
        imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.1);
    end
    %%%%%%%%%%%%%%%%%%%
end
close(fId);

%%
% <<ecg_add_freq.gif>>


%% Simple high pass filtering
% The goal here is to remove the low frequencies while leaving the
% rest of the signal intact.

% This will be our window size.
nz = 100;

% Let's get the length of the fourier of ecg,
lenEcg = size(ftecg,2)

%%

% And then create a vector of ones that is the length of ftecg - 200.
midOnes = ones(1,lenEcg-(2*nz));

lenEcg - size(midOnes,2)

%%

% We will now create a vector with ones in the middle and zeros on the
% border.
flt = [zeros(1,nz), midOnes, zeros(1,nz)];

% Note that it is the same size as the ftecg.
size(flt)
size(ftecg)
%%

% Now multiply this filter with the fourier transformed ecg. This
% effectively zeros out the first and last 100 frequencies while leaving
% the rest.
% Note that .* is component-wise multiplication:
%   [1,2,3,4,5] .* [0,1,1,1,0] = [0,2,3,4,0]

ftecg_hp = ftecg .* flt;


% Note that the signals at each end are zeroed out in red.
% Also note that the the signal at each end represents low frequencies as
% this signal is folded.
figure; semilogy(abs(ftecg), 'b', 'linew', 3); 
axis([-5000, 15^4, 10^-2, 12^8 ])
hold on;
semilogy(abs(ftecg_hp),'r')
legend('original', 'after high pass');
%%

% Plot using fftshift...
figure; plot(abs(fftshift(ftecg_hp))); xlabel('frequency'); ylabel('magnitude of fourier components');
hold on; plot(10^4*fftshift(flt),'r','linew',2)
legend('Filtered fourier','high pass filter')
%%

%% Inverse FFT
% Now we take the INVERSE of the fourier transform to go back to the time
% domain. Note that we are taking the inverse on the signal with some of
% the frequencies removed. Note also that due to the computer's finite
% precision, some small complex values appear in the temporal signal,
% which we remove with the function: real.

ecg_hp = real( ifft( ftecg_hp));

figure;
% Plot the original ecg signal.
plot(ecg,'r');
hold on;
% Plot the ecg signal in the time domain after we removed some frequencies.
plot(ecg_hp,'b');
xlabel('time'); ylabel('electrical activity'); grid
legend('original ecg','ecg with low frequencies removed');


%% Removing different frequencies
% Here we examine what happens when we remove different parts of the
% frequencies.
mkdir(fullfile(pwd,'html'))
fId = figure;
for nz = 1:20:1000
    hold off;
    
    % This is the filter. Notice that for each iteration, we get rid of
    % more of the frequencies.
    flt = [zeros(1,nz), ones(1,length(ftecg) - (2*nz)), zeros(1,nz)];
    
    % Apply the filter to the fourier transformed ecg signal.
    % 'ftecg' is the ecg signal after a fourier transform.
    ftecg_flt = ftecg .* flt;
    
    % Go back to the time domain.
    ecg_flt = real( ifft(ftecg_flt));
    
    
    % Plot the filtered signal.
    plot(ecg_flt,'b','linew',4);
    
    hold on;
    
    % Plot the original signal centered around 0.
   % plot(ecg-mean(ecg),'r','linew',1);
    
    
    xlabel('time'); ylabel('electrical activity');
    ylim([-400,1000])
    legend('filtered', 'original ecg');
    
    drawnow
    
    %%%%%%%%%%%%%%%%%%
    % This is just for creating the gif.    
    frame = getframe(1);
    im = frame2im(frame);
    [A,map] = rgb2ind(im,256);
    
    filename = fullfile('html','ecg_temporal.gif');
    if nz == 1;
        imwrite(A,map,filename,'gif','LoopCount',Inf,'DelayTime',0.1);
    else
        imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.1);
    end
    %%%%%%%%%%%%%%%%%%%
    
    pause(0.1)
end
%close(fId);

%%
% <<ecg_temporal.gif>>

