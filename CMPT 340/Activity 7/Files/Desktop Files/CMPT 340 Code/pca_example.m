%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%PCA
%GHASSAN HAMARNEH
%
%demonstrations presented here are similar to calculations done by hand
%see end of file for the same calculations making use of MATLAB's commands (cov,eig)
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all; clear

%% The observations: 5 observation, each has 2 variables (x,y)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

X=[10 20 15 30 45];
Y=[10 10 15 12 18];

%% the mean vector
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

M=(1/5)*(...
   [X(1);Y(1)] + ...
   [X(2);Y(2)] + ...
   [X(3);Y(3)] + ...
   [X(4);Y(4)] + ...
   [X(5);Y(5)]);

Mx=M(1)
My=M(2)

%% the covariance matrix
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

C=(1/(5-1)) * (... %C=1/(N-1).... equation
   [X(1)-Mx;Y(1)-My]*[X(1)-Mx;Y(1)-My]' + ...
   [X(2)-Mx;Y(2)-My]*[X(2)-Mx;Y(2)-My]' + ...
   [X(3)-Mx;Y(3)-My]*[X(3)-Mx;Y(3)-My]' + ...
   [X(4)-Mx;Y(4)-My]*[X(4)-Mx;Y(4)-My]' + ...
   [X(5)-Mx;Y(5)-My]*[X(5)-Mx;Y(5)-My]')


%% eigenvalue/vector decomposition of the covariance matrix
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%
% |C-L*I|=0
% 
% L: eigenvalue
% I: Identity matrix
%
% | C11-L      C12   |
% |                  |=0
% | C21        C22-L |
%
% (C11 - L)(C22-L)-C12^2   = 0
% L^2  + (-C11-C22)*L + (C11*C22-C12^2) = 0

a=1;
b=(-C(1,1)-C(2,2));
c=(C(1,1)*C(2,2)-C(1,2)^2);

L1=(-b-sqrt(b^2-4*a*c))/(2*a);
L2=(-b+sqrt(b^2-4*a*c))/(2*a);

if(L2>L1)
   tmp=L2;
   L2=L1;
   L1=tmp;
end

%the eigen values
L1,L2

%% the eigen vectors
% C*[p11;p12]=L1*[p11;p12]
% C11*p11 + C12*p12 = L1*p11  
p11=1;
p12=(L1-C(1,1))/C(1,2);
p1=[p11;p12]/sqrt(p11^2+p12^2)

% C*[p21;p22]=L2*[p21;p22]
% C11*p21 + C12*p22 = L2*p21  
p21=1;
p22=(L2-C(1,1))/C(1,2);
p2=[p21;p22]/sqrt(p21^2+p22^2)


%% checking the total variance
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

totVarL=L1+L2
totVarC=C(1,1)+C(2,2)

%% variance percentage explained by each variation mode
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

v1=L1/totVarL*100
v2=L2/totVarL*100

%% plotting the results
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

hold off
plot(X,Y,'bo','linew',6); %the observations
grid;
axis([5 50 5 20]);
hold on
plot(Mx,My,'mo','linew',6);%the mean
line(...
   [Mx-sqrt(L1)*p1(1) Mx+sqrt(L1)*p1(1)],... %line in the direction of the main variation mode
   [My-sqrt(L1)*p1(2) My+sqrt(L1)*p1(2)],...
   'LineWidth',2,'Color',[1 0 0]);

%% a new observation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

plot(20,15,'go','linew',6);

%% the new observation according to our model with 1 variational mode
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% move "b" from mean along new axis
% until distance to new point is minimized
% 
% D=(Mx+p1(1)*b-20)^2 + (My+p1(2)*b-15)^2
% dD/db1 = 2*(Mx+p1(1)*b-20)*p1(1) + 2*(My+p1(2)*b-15)*p1(2) = 0
% 2*Mx*p1(1)+2*p1(1)^2*b-2*20*p1(1) + 2*My*p1(2)+2*p1(2)^2*b-2*15*p1(2) = 0
% b=( -2*Mx*p1(1)+2*20*p1(1)-2*My*p1(2)+2*15*p1(2) ) / (2*p1(1)^2 + 2*p1(2)^2)

b=( -2*Mx*p1(1)+2*20*p1(1)-2*My*p1(2)+2*15*p1(2) ) / (2*p1(1)^2 + 2*p1(2)^2)

Xn=[Mx;My]+p1*b

plot(Xn(1),Xn(2),'co','linew',6);

%% 
axis equal
line([20 Xn(1)],[15 Xn(2)])


%% Checking results by using MATLABs Commands (cov,eig)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
C_chk=cov([X;Y]') %using MATLABs cov(...)
C % compare to C
[P_chk,L_chk]=eig(C_chk)  %using MATLABs eig(...)
p1,p2,L1,L2 % compare to p1 and p2 L1 L2

%P_chk(:,2) corresponds to -P1 (note eigenvalues)
b_chk=(-P_chk(:,2))'*([20;15]-[Mx;My])
b 

Xn_chk=[Mx;My]+(-P_chk(:,2))*b_chk
plot(Xn_chk(1),Xn_chk(2),'ko','linew',2);

%% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

legend(...
   'Original observations',...
   'The mean observation',...
   'Direction of 1st PC',...
   'The new observation',...
   'New observation according to the model',...
   'Error',...
   'Matlab Check');

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
