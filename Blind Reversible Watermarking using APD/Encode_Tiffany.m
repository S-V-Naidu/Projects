%Attempt for watermarking tiffany.

clc;close all;clear all;
l=imread('tiffany(matlab).jpg');
o=l;
imshow(l)
title('Original Tiffany image');
figure;
l=rgb2gray(l);
o=rgb2gray(o);
imshow(l)
title('Grayscale converted Tiffany');
figure;
imhist(l)
figure;
l=single(l);
imshow(edge(l))
title('Border of intensity changes')
figure;

for n=1:50
    for m=1:50
        l(n,m)=(l(n,m) - l(n,m+1));
    end
end

f=1;
z = -f;
for n=1:50
    for m=1:50
        if (l(n,m) > 1 )
            I(n,m) = l(n,m) + 1;
        elseif (l(n,m) < -1)
            I(n,m) = l(n,m) - 1;
        else 
            I(n,m)=l(n,m);
        end
    end
end
I;
%i=zeros(220,220);
%   for n=1:50
%    for m=1:50
%        i(n,m) = I(n,m) + i(n,m);
%    end
%end

%b=imread('HelloBitmap.jpg');
%imshow(b)
%title('Original bitmap');
%figure;
%imhist(rgb2gray(b))
%b = rgb2gray(b);
%imshow(b)
%figure;
%figure;
%b=single(b);

count=0;
for n=1:50
    for m=1:50
        if (I(n,m) == 1)
            count = count + 1;
        elseif (I(n,m) == -1)
            count = count + 1;
        else 
            count = count;
        end
    end
end
count
%{
p=0;
for n=1:200
    for m=1:200
        d = b(n,m);     
        d=logical(dec2bin(d, 8) - '0');
        d= int8(d);
        %d = bitget(d,1);
        p = p + 1;
        h(p)= d(1,1);
        count = count - 1;
        if (count == 0)
            break;
        end
    end 
    if(count == 0)
        break;
    end
end
h;
%}
h = 'Ramaiah Institute of Technology';
h = logical(dec2bin(h) - '0');

q = 1;
r = 1;
for n=1:50
    for m=1:50
        if( l(n,m) == f)
            if(q == 32)
                a(n,m) = l(n,m);
            else
                if(h(q,r) == 1)
                    a(n,m) = l(n,m) + 1;
                    r = r + 1;
                else
                    a(n,m) = l(n,m);
                    r = r + 1;
                end
            end
        elseif( l(n,m) == z)
            if(q == 32)
                a(n,m) = l(n,m);
            else
                if(h(q,r) == 1)
                    a(n,m) = l(n,m) - 1;
                    r = r + 1;
                else
                    a(n,m) = l(n,m);
                    r = r + 1;
                end
            end
        else
            a(n,m) = l(n,m);
        end
        if( r == 8)
            q = q + 1;
            r = 1;
            
        end
    end
end
a;
l;
%a = uint8(a);
%imshow(a)
%title('Watermarked image')
%i;
%a = single(a);

A=zeros(512,512);
   for n=1:50
    for m=1:50
        A(n,m) = a(n,m) + A(n,m);
    end
   end
A;
A = single(A);
A = uint8(A);
for n=1:512
    for m=1:512
        s(n,m) = o(n,m) - A(n,m);
    end
end

%s=uint8(s);
imshow(s);
title('Watermarked image')
%imwrite(s,'Watermarked_Tiffany.png','png');
psnr(o,s)
%}