Nx = length(x);
nsc = floor(Nx/4.5);
nov = floor(nsc/2);
nff = max(256,2^nextpow2(nsc));

t = spectrogram(x,hamming(nsc),nov,nff);

maxerr = max(abs(abs(t(:))-abs(s(:))))
ns = 8;
ov = 0.5;
lsc = floor(Nx/(ns-(ns-1)*ov));

t = spectrogram(x,lsc,floor(ov*lsc),nff);

maxerr = max(abs(abs(t(:))-abs(s(:))))
t = 0:0.001:2;
x = chirp(t,100,1,200,'quadratic');
spectrogram(x,128,120,128,1e3)
spectrogram(x,blackman(128),60,128,1e3)
ax = gca;
ax.YDir = 'reverse';
t = 0:0.001:2;
x = chirp(t,100,1,200,'quadratic');

spectrogram(x,128,120,128,1e3,'yaxis')
title('Quadratic Chirp')
t = 0:0.001:2;
x = chirp(t,0,1,150);

spectrogram(x,256,250,256,1e3,'yaxis')
title('Linear Chirp')
t = 0:0.001:2;
x = chirp(t,20,1,60,'logarithmic');

spectrogram(x,256,250,[],1e3,'yaxis')
title('Logarithmic Chirp')
ax = gca;
ax.YScale = 'log';
Fs = 1000;
t = 0:1/Fs:2-1/Fs;
y = chirp(t,100,1,200,'quadratic');
spectrogram(y,100,80,100,Fs,'yaxis')
view(-77,72)
shading interp
colorbar off
[s,f,t,p] = spectrogram(y,100,80,100,Fs);

[q,nd] = max(10*log10(p));

hold on
plot3(t,f(nd),q,'r','linewidth',4)
hold off
colorbar
view(2)