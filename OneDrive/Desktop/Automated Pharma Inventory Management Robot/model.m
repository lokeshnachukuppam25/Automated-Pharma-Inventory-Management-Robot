clear all
close all
clc

% Sample dataset
% Features:
% 1 – RFID detection status
% 2 – distance
% 3 – retrieval time

data = [
1 20 3 1
1 25 4 1
0 50 0 0
1 30 3 1
0 60 0 0
];

X = data(:,1:3);
Y = data(:,4);

% Split dataset
cv = cvpartition(length(Y),'HoldOut',0.3);

Xtrain = X(training(cv),:);
Ytrain = Y(training(cv));

Xtest = X(test(cv),:);
Ytest = Y(test(cv));

% Logistic Regression
mdl1 = fitglm(Xtrain,Ytrain,'Distribution','binomial');

% SVM model
mdl2 = fitcsvm(Xtrain,Ytrain);

% Random Forest
mdl3 = TreeBagger(50,Xtrain,Ytrain);

% Prediction
pred1 = round(predict(mdl1,Xtest));
pred2 = predict(mdl2,Xtest);
pred3 = round(predict(mdl3,Xtest));

% Accuracy
acc1 = sum(pred1==Ytest)/length(Ytest)*100;
acc2 = sum(pred2==Ytest)/length(Ytest)*100;
acc3 = sum(pred3==Ytest)/length(Ytest)*100;

fprintf("Logistic Regression Accuracy = %.2f%%\n",acc1)
fprintf("SVM Accuracy = %.2f%%\n",acc2)
fprintf("Random Forest Accuracy = %.2f%%\n",acc3)