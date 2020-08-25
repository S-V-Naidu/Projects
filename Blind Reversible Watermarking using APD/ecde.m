clc;close all;clear all;
b=imread('Guinea Pig.jpg');
imshow(b)
figure;
b=rgb2gray(b);
imhist(b)
figure;
imshow(b)
title('image in gray scale')
figure;
b1=histeq(b);
imshow(b1)
title('Histogram equivalent');
figure;
imhist(b1)
figure;
for n=1:8
    for m=1:8
        d(n,m)=b(n,m);
    end
end
disp('b=')
d
for n=1:8
    if (mod(n,2) == 0)
        for m=8:1
            c(n,m)=d(n,m) - d(n,m+1);
        end
    else
        for m=1:8
            c(n,m)=d(n,m) - d(n,m-1);
        end
    end
end
disp('New d=')
d
imshow(d)
title('Final image')
figure;
imhist(d)
figure;
histeq(d)