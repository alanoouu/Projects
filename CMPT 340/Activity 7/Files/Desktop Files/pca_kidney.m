%% CMPT340 - Activity 7: Kidney PCA 
%
% *Goal*
% In this assignment, we will apply PCA on 3D point clouds of kidneys.
% This will allow us to create a model that learns how kidneys deform.
% We will be able to manipulate this model and it will deform based on the
% variations found in our dataset.
%
%
% *Data files*
% The data files are under the folder ./kidneys_3d_points:
% The folder contains sets of 3D points for 20 kidneys.
%
% *Instructions*
% The questions and specific instructions are given below. We have included
% some "checks" with answers to allow you to see if certain parts of your
% code corresponds to what we expect. If you have the same answers, 
% this should help confirm that you are on the right track.
%
% Some of the instructions are not specific questions, but are there
% to help guide you through the work.
% 
% Whenever you see:
%
% %--------- Your Code Here ------%
%
% %-------------------------------%
%
% You should enter your code in that area. 
%
% You don't have to submit anything for this activity. The solution key
% will be posted afterwards.
% 
%
% *Save your results*
% please save your results as .gif under the folder ./html
% you should still be able to visualize your results using generic image viewer
% after closing MATLAB
 
% Clean up
clear all; close all;
clc
 
if ~exist('html')
    mkdir('html')
end
 
%% Q. Load and display the sample data
% Load the file "DeformedObject (13).mat" into variable K13.
% Use plot3 to plot all the point as small dots.
% Do not connect the dots together.
 
%--------- Your Code Here ------%
K13 = load('kidneys_3d_points/DeformedObject (13).mat').DeformedObject;
plot3(K13(:,1), K13(:,2), K13(:,3),'.');
 
%-------------------------------%
 
% *** check ***
display(sprintf('Load data check (size): %i', isequal(size(K13),[1924,3])));
display(sprintf('Load data check (coordinate): %i', round(K13(1924,1))==41));
 
 
% Find how many 3D points (landmarks) there are.
% Save the answer in variable L
 
%--------- Your Code Here ------%
L = size(K13,1);
 
%-------------------------------%
display(sprintf('Num Landmark check: %i',L == 1924))
 
%% Q. Create observation matrix
% Convert K13 into a single column observation by stacking the x coordinates, 
% the y coordinates, then the z coordinates all below each other
 
%--------- Your Code Here ------%
K13 = vertcat(K13(:,1), K13(:,2), K13(:,3));

%-------------------------------%
 
% *** check ***
display(sprintf('K13 column check (size): %i', isequal(size(K13),[5772,1])))
display(sprintf('K13 column check (value): %i', round(K13(5769))==16))
%%
 
 
%% Q. Load all data files and save all the data into an observation matrix X
% the resulting X should have:
% number of rows = number of observations (i.e. number of kidneys);
%
% number of columns = number of 3D points per kidney * 3 (we multiply by 3
% as each point has x,y and z coordinates);
%
%         
 
%--------- Your Code Here ------%
path = fullfile(pwd,'kidneys_3d_points');

numObservations = 20;
 
for i = 1:numObservations
    inputFile = load(fullfile(path, ['DeformedObject (', sprintf('%i',i), ').mat'])).DeformedObject;
    vertInput = vertcat(inputFile(:,1), inputFile(:,2), inputFile(:,3));
    for j = 1:(1924*3)
        X(i,j) = vertInput(j);
    end
end
 
%-------------------------------%
 
% *** check ***
display(sprintf('X size:%i',isequal(size(X),[20,5772])));
% check some sample coordinates
display(sprintf('X values:%i', isequal(round(X(10,20)),43)));
display(sprintf('X values:%i', isequal(round(X(19,4000)),66)));
 

%% Q. Plot all data 
% Write a for loop that will display, one at a time, all kidneys using plot3
% Create a GIF of each kidney and export the figures under the html folder.
fAllData = figure(1);
%--------- Your Code Here ------%

filename = 'kidneys.gif';
for i = 1:numObservations
    plot3(X(i,(1:1924)), X(i,(1925:3848)), X(i,(3849:5772)),'.');

    %%%%%%% GIF code referenced from https://www.mathworks.com/matlabcentral/answers/94495-how-can-i-create-animated-gif-images-in-matlab
    %%%%%%% and from the GIF code below
    
    drawnow;
    
    filename = fullfile('html','kidney.gif');
    frame = getframe(fAllData);
    img = frame2im(frame);
    [fig,cMap] = rgb2ind(img,256);
    if i == 1
        imwrite(fig,cMap,filename,'gif','Loopcount',inf);
    else
        imwrite(fig,cMap,filename,'gif','WriteMode','append');
    end
    %%%%%%%
end

%-------------------------------%
close(fAllData)
%%
 
%% Q. The mean kidney
% Calculate and plot the "mean kidney" shape. 
% The mean kidney is the kidney produced by taking the mean of all the
% kidney data. It should look like an "average" kidney.
 
%--------- Your Code Here ------%
mn = mean(X)';

plot3(mn(1:1924), mn(1925:3848), mn(3849:5772),'.');
%-------------------------------%
 
% *** check ***
display(sprintf('mean size check: %i', isequal(size(mn), [5772,1])));
% random check
display(sprintf('mean val check: %i', isequal(round(mn(1000:1005))', [ 51    54    53    58    56    62])));
 
 
 
%% Q. Apply PCA
% Perform PCA using the _pca()_ command. Make sure to compute the eigenvectors,
% scores, and eigenvalues.
% note that PCA sorts output eigenvalue magnitudes in decreading order
 
%--------- Your Code Here ------%
[eigenvectors,score,eigenvalues] = pca(X);

%-------------------------------%

%% Q. Extract PC1
% Extract the eigenvector with the largest eigenvalue and save it in
% a column variable PC1
 
%--------- Your Code Here ------%
PC1 = eigenvectors(:,1);
 
%-------------------------------%
display(sprintf('PC1 check:%i',isequal(round((PC1(100,1))*10^7),1444))); 
 
%% Q. Create a new shape along PC1 
% Create a new shape Xn by moving one *unit* along PC1 away
% from the mean. Represent Xn as a column vector.
%--------- Your Code Here ------%
Xn = PC1 + mn;
v1 = eigenvalues(1);
%-------------------------------%
display(sprintf('PC1 shape check:%i', isequal(round(Xn(200:205,1)'), [59    35    39    55    32    55])));
 
%% Q. Plot the shape from PC1
% Plot this new shape _Xn_ in 3D.
% Hint: This should look somewhat like a kidney still.
 
figure(2)
%--------- Your Code Here ------%
plot3(Xn(1:1924), Xn(1925:3848), Xn(3849:5772),'.');
 
%-------------------------------%
 
%% Q. Extract PC2
% Extract the eigenvector with the 2nd largest eigenvalue and save it
% in a column variable PC2 AND save its corresponding eigenvalue in variable l2
 
%--------- Your Code Here ------%
PC2 = eigenvectors(:,2);
v2 = eigenvalues(2);
%-------------------------------%
display(sprintf('PC2 check:%i', isequal(round(PC2(2000:2005,1)'*10^7), [-26968      -18511      -21273      -28805      -24438      -26308])));
display(sprintf('v2 check:%i', isequal(round(v2), 3113)));
 
 
%% Q. Create and plot the PC2 shape
% Create a new shape (also Xn) by moving 3 standard deviations along PC2
% away from the mean. Note that the eigenvector should be *appropriately* 
% weighted by it's correpsonding eigenvalue.
% Hint: This should look like a kidney.
 
%--------- Your Code Here ------%
Xn = 3*sqrt(v2) * PC2 + mn;

%-------------------------------%
 
% plot the shape in 3D
figure(3)
%--------- Your Code Here ------%
plot3(Xn(1:1924), Xn(1925:3848), Xn(3849:5772),'.');

%-------------------------------%
 
display(sprintf('PC2 shape: %i', isequal(round(Xn(1:5))', [46    43    45    45    52])));
 
 
%% Q. Moving along the first 3 PCs to generate new kidneys
% Plot the shape changes as the PCs are varied independently
% Write a loop that shows how the kidney changes when a single principal
% component (PC) is changed and the rest are fixed.
%
% We will only change the first 3 PCs.
%
% We will only allow the kidneys to change between -500 and +500 standard deviations
% so we get deformations that could be clearly visualized.
%
% We will also plot them so all appear in the same figure.
%
% Create a GIF and make sure it is saved under the html folder along with
% other figures
 
 
% Create our figure.
hFig = figure(4);
 
% Make it a bit larger so we can see the kidneys better. You might need to
% adjust this based on your screen size.
set(hFig, 'Position', [50 50 1500 400])
 
% Loop from -5 to +5 standard deviations, where we change by 0.1 standard
% deviation in each iteration.
for k=-5:0.1:5
    
    % Change PC1 goes here...    
    subplot(1,3,1);    
    
    %--------- Your Code Here ------%
    Xn1 = (k*sqrt(v1) * PC1) + mn;
    plot3(Xn1(1:1924), Xn1(1925:3848), Xn1(3849:5772),'.');
    
    %-------------------------------%

    % We add a title so we can see the standard deviation change.
    title(sprintf('PC1: %.3f', k));
    axis([0 100 0 150 0 100])
    axis image;
    
    % Change PC2
    subplot(1,3,2);
    %--------- Your Code Here ------%
    Xn2 = (k*sqrt(v2) * PC2) + mn;
    plot3(Xn2(1:1924), Xn2(1925:3848), Xn2(3849:5772),'.');
    
    %-------------------------------%    
    title(sprintf('PC2: %.3f', k));
    %axis([0 100 0 150 0 100])
    axis image
    
    % Change PC3
    subplot(1,3,3);
    %--------- Your Code Here ------%
    PC3 = eigenvectors(:,3);
    v3 = eigenvalues(3);
    
    Xn3 = (k*sqrt(v3) * PC3) + mn;
    plot3(Xn3(1:1924), Xn3(1925:3848), Xn3(3849:5772),'.');
    %-------------------------------%    
    title(sprintf('PC3: %.3f', k));
    %axis([0 100 0 150 0 100])
    axis image;     
    
    drawnow;
        
    %%%%%%% GIF code.
    filename = fullfile('html','pcChange.gif');
    frame = getframe(gcf);
    im = frame2im(frame);
    [imind,cm] = rgb2ind(im,256);
    if k == -5
        imwrite(imind,cm,filename,'gif','Loopcount',inf);
    else
        imwrite(imind,cm,filename,'gif','WriteMode','append');
    end
    %%%%%%%
    
    pause(0.05)
end
close(hFig);
%%
 
 
%% Q. Rough description of what happens when the PCs change
% Above we only changed 1 PC independently (fix the others, only change one) 
% In words, give a brief description of how the kidney subtely changes as we change each PC.
% Hint: Examine/rotate each kidney at the end of the above loop, and see
% in what ways the kidneys differ. 
% e.g. Does changing one PC stretch a specific part of the kidney?
% e.g. Does changing one PC cause the kidney to compress/expand?
 
pc1str = 'When PC1 increases, the kidney ';
%----- Your description here ------%
myPc1Description = ['from the frontal view, or in other words, when the kidney is viewed from the kidney bean shape, \n'... 
'it can be seen that as the standard deviation increases, the kidney becomes taller and wider, in other words, the kidney expands \n'...
'in height (Z-coordinate in figure) and width (X-coordinate in figure). Furthermore, the points that were originally out in the corners \n'...
'of the figure when the standard deviation was -5, got moved downwards and towards the center if the points were in the top half of the figure, \n'...
'and upwards and towards the center if the points were in the bottom half of the figure, producing a more pronounced kidney shape.\n\n' ...
'The top and bottom of the kidney show similar changes, therefore I will only describe the changes that I observed when the top of the kidney \n'...
'was observed. From the top, it can be seen that there is doubling expansion in the Y direction that occurs throughout the kidney, but an even \n'...
'greater expansion occurs in the center, changing what was originally the shape of an upside down pan to the shape of a round, rice-paddy hat. \n\n'...
'From the sides, we can see that as the standard deviation increases, the width of the figure (Y-coordinate in the figure) expands from a \n'...
'range of 15 to 30, to a range of 0 to 50. This expansion of the figure also means an expansion of the kidney. The data points throughout the \n'...
'kidney become more spread out, with the center of the kidney having the greatest expansion. Furthermore, the height expansion carries over from \n'...
'the frontal examination. \n\n' ...
'In summary, as PC1 increases, the total width, height, and thickness of the kidney all increase. \n\n' ];

%----------------------------------%
fprintf([pc1str, myPc1Description]);
 
pc2str = 'When PC2 increases, the kidney ';
%----- Your description here ------%
myPc2Description = ['the frontal view shows that height and width stay approximately the same, therefore the kidney is neither \n'...
'stretched nor compressed; however, the points that were originally at the bottom left of the figure got pushed upwards, creating a \n'...
'concentration of data points around Z = 60. \n\n'...
'Similar to PC1, as the standard deviation increases, the height (Y-coordinate) doubles throughout the top of the kidney. \n\n'...
'From the sides, we can again see an expansion similar to PC1, however, the expansion is less pronounced. \n\n' ...
'In summary, as PC2 increases, the total thickness of the kidney increases, but the total width and height stay approximately the same. \n\n' ];
 
%----------------------------------%
fprintf([pc2str, myPc2Description]);
 
pc3str = 'When PC3 increases, the kidney ';
%----- Your description here ------%
myPc3Description = ['a similar situation as PC1 is seen. The kidney is taller and wider, therefore stretched in both the \n'...
'height and width. The points that were originally out in the corners of the figure when the standard deviation was -5, got moved \n'...
'downwards and towards the center if the points were in the top half of the figure, and upwards and towards the center if the points \n'...
'were in the bottom half of the figure; however, it should be noted that the points in the bottom left of the figure when the standard \n'...
'deviation = 5, appear to be moved more upwards than PC1, but less than PC2, creating a concentration of data points around Z = 50. \n\n'...
'Unlike the other PCs, as the standard deviation increased, the shape of the top of the kidney compressed. The figure went from having \n'...
'a Y-coordinate range of 10 to 40, to having a range of 10 to 30. Furthermore, the shape went from what was originally an oval like shape \n'...
'to the shape of a mountain. \n\n'...
'From the sides, again, unlike the other PCs, there is a compression to the shape of the kidney. The range of the figure compressed \n'...
'from originally having a Y-range of 15 to 45, to having a range of 10 to 30. The most difference between the shape of the kidney sides \n'...
'can be see towards the top and bottom left corners of the figure, where the points which were originally more pushed out towards the \n'...
'corner move towards the center of the kidney. \n\n' ...
'In summary, as PC3 increases, the total width and height of the kidney increases, but the total thickness decreases. \n\n'];
 
%----------------------------------%
fprintf([pc3str, myPc3Description]);
 
 
%% Q. Come up with 3 interesting shapes
% Instead of changing 1 PC and fixing the rest, we can change the first 3 PCs at
% the same time. Come up with 3 interesting shapes where the first 3 PCs
% have different non-zero weightings.
%
% Deform between -500 and +500 standard deviations
% so we get deformations that could be clearly visualized.
% 
% Put the standard deviations values that you used in the title.
 
figure(5);
%--------- Your Code Here ------%
pc1std = -500;
pc2std = -400;
pc3std = -300;

Xn4 = (pc1std * PC1)+(pc2std * PC2)+(pc3std * PC3) + mn;
plot3(Xn4(1:1924), Xn4(1925:3848), Xn4(3849:5772),'.');
%-------------------------------%
title(sprintf('PC1: %.2f, PC2: %.2f, PC3: %.2f', pc1std,pc2std,pc3std));
axis image;
 
%%
figure(6);
%--------- Your Code Here ------%
pc1std = 500;
pc2std = 400;
pc3std = 300;

Xn5 = (pc1std * PC1)+(pc2std * PC2)+(pc3std * PC3) + mn;
plot3(Xn5(1:1924), Xn5(1925:3848), Xn5(3849:5772),'.');
%-------------------------------%
title(sprintf('PC1: %.2f, PC2: %.2f, PC3: %.2f', pc1std,pc2std,pc3std));
axis image;
 
%%
figure(7);
%--------- Your Code Here ------%
pc1std = -500;
pc2std = 100;
pc3std = 500;

Xn6 = (pc1std * PC1)+(pc2std * PC2)+(pc3std * PC3) + mn;
plot3(Xn6(1:1924), Xn6(1925:3848), Xn6(3849:5772),'.');
%-------------------------------%
title(sprintf('PC1: %.2f, PC2: %.2f, PC3: %.2f', pc1std,pc2std,pc3std));
axis image;
%%

