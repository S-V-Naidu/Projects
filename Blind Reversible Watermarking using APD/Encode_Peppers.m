%Attempt for watermarking pepper

clc;close all;clear all;
l=imread('peppers(matlab).jpg');
o=l;
imshow(l)
title('Original pepper image');
figure;
l=rgb2gray(l);
o=rgb2gray(o);
imshow(l)
title('Grayscale converted pepper');
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
%imshow(l)
%title('Pepper after APD')
%figure;

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

h = 'Ramaiah Institute of Technology';
h = logical(dec2bin(h) - '0');
%{
p=0;
for n=1:298
    for m=1:298
        d = b(n,m);     
        d=logical(dec2bin(d, 8) - '0');
        d= int8(d);
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
q = 1;
r = 1;
for n=1:50
    for m=1:50
        if( l(n,m) == f)
            if(q ==32)
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
A=zeros(298,298);
   for n=1:50
    for m=1:50
        A(n,m) = a(n,m) + A(n,m);
    end
   end
A;
A=uint8(A);
for n=1:298
    for m=1:298
        s(n,m) = o(n,m) - A(n,m);
    end
end
imshow(s);
title('Watermarked image')
%imwrite(s,'Watermarked_Peppers.png','png');
psnr(o,s)
%}