V = [70,60,30,80,40,20,50,90,85,45,75,65,55,15,35,45,45,65,65,75];
C = [1,1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0];

negative = [];
positive = [];      %positive 

threshold = 50;

for i = 1 : 20
    if C(i) == 1
        positive = [positive V(i)];
    else
        negative = [negative V(i)];
    end
end

sort(positive)
sort(negative)