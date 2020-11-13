%% Biosignal (ECG) - temporal analysis
% We examine how to analyze a 1D ECG signal in the time domain. 
% At each point in time we have a single value.

%% How to run this demo
% You can download the datasets from Canvas

%%
% Download the below files and re-create the directory structure given below.
%   
%   /ecg_temporal.m 
%   /ecg/ecgdemodata1.mat


% Clean up the workspace.
clear variables; close all

% Load the ECG data.
ecgNamePath = fullfile(pwd,'ecg','ecgdemodata1.mat');
ecgStruct = load(ecgNamePath);
ecg = ecgStruct.ecg;

%% Plot the ECG full temporal signal
figure; 
plot(ecg);
title(['ECG with sampling rate:' num2str(ecgStruct.samplingrate)]);
xlabel('time'); ylabel('voltage'); grid on;

%% Plot one cardiac cycle
ecg1time = 3500:3900;
ecg1volt = ecg(ecg1time);
figure; 
plot(ecg1volt);
title('One cardic cycle (ECG)');
xlabel('time'); ylabel('voltage'); grid on;

%% Detect the max and min of a singal

hold on; % Add to the previous figure.

% Get the max value and the index it is stored at.
[maxValue, maxInd] = max(ecg1volt);

plot(maxInd,ecg1volt(maxInd),'ro','linew',5);

[minValue, minInd] = min(ecg1volt);

plot(minInd, ecg1volt(minInd),'ko','linew',5);
hold off;


%% Moving average
% So far the data we are looking at seems pretty noisy. We might want to
% get a sense of the average of the data points over a small period of time. 
% Here's how we can keep some of the trends in the signal while removing some of
% the noise.

% The number of time points we want to average by.
n = 200;

% How much should we consider each neighbouring value by.
weights = ones(1,n)/n;

% They are all the same value. This means we are weighing the neighbouring
% singal by the same amount.
weights(1:5)
%%

% Filter the ecg signal by the weights. This is done for each time point
% (that's why it is called a "moving" average).
avg = filter(weights, 1, ecg);

figure; 
% Plot the original signal.
plot(ecg,'b');
hold on;
% Plot the moving average.
plot(avg,'r');
xlabel('time'); ylabel('voltage'); grid on;
%%

% We can subtract this moving average (avg) from our original signal (ecg)
ecg_rm_avg = ecg - avg;
hold on;
plot(ecg_rm_avg,'g');

%% Moving median (nlfilter example)

% We can define a function that takes as input 'x' and outputs the median
% of all the values in 'x'.
fun = @(x) median(x(:));

% If we had 2D (e.g. images) we could change this to do a median filter in
% 2D. But we will just use a 1D filter since we only have 1D data here.
% Note here we are looking at 100 values (vs. n=200 from before).
slideWindow = [1 100];

% Similar to filter but we can specify how to filter and the window size.
med = nlfilter(ecg, slideWindow, fun);

figure;
% Original signal.
plot(ecg,'b');
hold on;

% The median filter.
plot(med,'r');
hold on;

% Subtract the median filter from the orginal signal.
ecg_rm_med = ecg - med;
plot(ecg_rm_med, 'g');
hold on;

% Let us compare this with the signal subtracted by the moving average.
plot(ecg_rm_avg,'k');

legend('original','median','orig - med','orig - avg');
%%

% See that these two filter are a bit different.
figure; 
plot(avg(1000:10000)); hold on;
plot(med(1000:10000),'r');


%% Detect cycles.
% So why would we want to compute these moving averages and subtract them
% from the signals? Well, one reason might be to detect cycles.

% Since the signal has been transformed to be around 0, we can pick a
% single threshold by eye.
T = 400;

% Find all the ecg values that are over this threshold.
ind = find(ecg_rm_avg > T);

% When the values are over the threshold, we set it to 1.
point_proc = zeros(size(ind));
point_proc(ind) = 1;

% If it is still 0, then set to nan.
point_proc(point_proc==0) = nan;

% To make it clearer, let's look at a smaller time block.
xDim = 10000:15000;

figure;
% The original signal.
plot(ecg(xDim),'g');
hold on;
% The signal with the average removed.
plot(ecg_rm_avg(xDim),'k');
% Plot the threshold value.
plot(1:size(xDim,2),repmat(T,size(xDim,2),1),'-','linew', 2);
% The cycles or peaks detected.
plot(point_proc(xDim), 'ro', 'linew', 2);
legend('original','average removed', 'threshold','peaks');
%%
