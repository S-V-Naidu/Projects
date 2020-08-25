clc;clear all;close all;
o = imread('lena(matlab).png');
o = rgb2gray(o);
s = imread('Watermarked_Lena.png');

for n=1:50
    for m=1:50
        a(n,m) = o(n,m) - s(n,m);
    end
end
a
%{
q=1;
r=1;
for n=1:50
    for m=1:50
        if( a(n,m) == 1 | a(n,m) == -1)
            h(q,r) = 0;
        end
        
        if( a(n,m) == 2 | a(n,m) == -2)
            h(q,r) = 1;
        end
            
    end
end
%}
b = 'Ramaiah Institute of Technology';
b = logical(dec2bin(b) - '0')

%psnr(a,b)