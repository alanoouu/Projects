close all; clear all;
syms Txx Txy Tyy
DT=[Txx Txy; Txy Tyy];
[evecs,evals]=eig(DT);
e1=simplify(evals(1,1));
e2=simplify(evals(2,2));
% e1 = Txx/2 + Tyy/2 - (Txx^2 - 2*Txx*Tyy + 4*Txy^2 + Tyy^2)^(1/2)/2
% e2 = Txx/2 + Tyy/2 + (Txx^2 - 2*Txx*Tyy + 4*Txy^2 + Tyy^2)^(1/2)/2
clear Txx Tyy Tyz vecs evals e1 e2
[Txx,Txy,Tyy]=meshgrid(-10:.1:10);
e1 = Txx/2 + Tyy/2 - (Txx.^2 - 2*Txx.*Tyy + 4*Txy.^2 + Tyy.^2).^(1/2)/2;
e2 = Txx/2 + Tyy/2 + (Txx.^2 - 2*Txx.*Tyy + 4*Txy.^2 + Tyy.^2).^(1/2)/2;
allow = double(e1>=0 & e2>=0);

p=patch(isosurface(Txx,Txy,Tyy,allow,0.9));
isonormals(Txx,Txy,Tyy,allow,p);
set(p,'FaceColor','red','EdgeColor','none');
daspect([1,1,1]); view(3); axis tight; camlight; lighting gouraud; 
xlabel Txx; ylabel Txy; zlabel Tyy; grid on;
title('sub-space with nonnegative eigenvalues');

