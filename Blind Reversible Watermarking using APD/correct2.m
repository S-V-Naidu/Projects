clc;close all;clear all;
b=imread('original.png');
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
disp('b=')
for n=1:8
    for m=1:8
        b(n,m)
    end
end
for n=1:8
    if (mod(n,2) == 0)
        for m=1:8
                b(n,m)=abs(b(n,m) - b(n,m+1));
        end
    else
        for m=8:1
            b(n,m)=abs(b(n,m) - b(n,m-1));
        end
    end
end
disp('New b=')
for n=1:8
    for m=1:8
        b(n,m)
    end
end
