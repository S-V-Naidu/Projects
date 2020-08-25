%% Default Values of Spectrogram
% Generate $N_{\tt x}=1024$ samples of a signal that consists of a sum of
% sinusoids. The normalized frequencies of the sinusoids are $2\pi/5$
% rad/sample and $4\pi/5$ rad/sample. The higher frequency sinusoid has 10
% times the amplitude of the other sinusoid.

% Copyright 2015 The MathWorks, Inc.


%%

N = 1024;
n = 0:N-1;

w0 = 2*pi/5;
x = sin(w0*n)+10*sin(2*w0*n);

%%
% Compute the short-time Fourier transform using the function defaults.
% Plot the spectrogram.

s = spectrogram(x);

spectrogram(x,'yaxis')

%%
% Repeat the computation.
%
% * Divide the signal into sections of length ${\tt nsc}=\lfloor N_{\tt
% x}/4.5\rfloor$.
% * Window the sections using a Hamming window.
% * Specify 50% overlap between contiguous sections.
% * To compute the FFT, use $\max(256,2^p)$ points, where
% $p=\lceil\log_2N_{\tt x}\rceil$.
%
% Verify that the two approaches give identical results.

Nx = length(x);
nsc = floor(Nx/4.5);
nov = floor(nsc/2);
nff = max(256,2^nextpow2(nsc));

t = spectrogram(x,hamming(nsc),nov,nff);

maxerr = max(abs(abs(t(:))-abs(s(:))))

%%
% Divide the signal into 8 sections of equal length, with 50% overlap
% between sections. Specify the same FFT length as in the preceding step.
% Compute the short-time Fourier transform and verify that it gives the
% same result as the previous two procedures.

ns = 8;
ov = 0.5;
lsc = floor(Nx/(ns-(ns-1)*ov));

t = spectrogram(x,lsc,floor(ov*lsc),nff);

maxerr = max(abs(abs(t(:))-abs(s(:))))