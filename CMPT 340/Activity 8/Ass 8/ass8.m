GGOVals = load('GGO_value.mat').GGO_values;
diagnosis = load('diagnosis.mat').diagnosis;
%Calculating mean and std:
positiveGGOValues = [];
negativeGGOValues = [];
for i = 1:100
 if diagnosis(i) == 1
 positiveGGOValues = [positiveGGOValues GGOVals(i)];
 else
 negativeGGOValues = [negativeGGOValues GGOVals(i)];
 end
end
meanPositiveGGOVals = mean(positiveGGOValues)
stdPositiveGGOVals = std(positiveGGOValues)
meanNegativeGGOVals = mean(negativeGGOValues)
stdNegativeGGOVals = std(negativeGGOValues)

% Choose the threshold range and step
% Build the distribution function
positiveGGOValues = sort(positiveGGOValues);
negativeGGOValues = sort(negativeGGOValues);
figure(1);
% Positive
positiveY = normpdf(positiveGGOValues,meanPositiveGGOVals,stdPositiveGGOVals);
% Negative
negativeY = normpdf(negativeGGOValues,meanNegativeGGOVals,stdNegativeGGOVals);
thresholdRange = [11 106];
thresholdValues = [];
step = 8;
% Plot your figures
plot(positiveGGOValues,positiveY,'r');
hold on
plot(negativeGGOValues,negativeY,'b');
xlim(thresholdRange);
xline(36,'--');
xline(44,'--');
xline(52,'--');
for g = 0 : 11
 thresholdValues = [thresholdValues g*step+12];
end
xticks(thresholdValues);
xlabel('AI generated GGO score') ;
ylabel('Probability') ;