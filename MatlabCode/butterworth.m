n=0:0.01:2;
N=5;
[z,p,k]=buttap(N);
[b,a]=zp2tf(z,p,k);
[H,w]=freqs(b,a,n);
magH2=(abs(H)).^2;
hold on
w = w.*12*10^3*pi;
plot(w,magH2);
axis([0 2*12*10^3*pi 0 1]);
xlabel('w');
ylabel('|H(jw)|^2');
grid