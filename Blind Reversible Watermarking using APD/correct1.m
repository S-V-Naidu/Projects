clc;close all;clear all;
a=imread('original.png');
b=imread('original.png');
b=rgb2gray(b);
imhist(b)
figure;
b1=histeq(b);
imshow(a)
title('Original one');
figure;
imshow(b)
title('Gray scale one');
figure;
imshow(b1)
title('Hist. equivalent');
figure;
imhist(b1)
figure;
disp('a=')
for n=1:8
    for m=1:8
        a(n,m)
    end
end
disp('b=')
for n=1:8
    for m=1:8
        b(n,m)
    end
end
for n=1:8
    for m=1:8
        d=b(n,m);
        d=dec2bin(d,8);
        d=bitget(d,1);
        if(d == 1)
            a(n,m) = a(n,m) + 1;
        end
    end
end
disp('New a:')
for n=1:8
    for m=1:8
        a(n,m)
    end
end
imshow(a)
title('Final a');