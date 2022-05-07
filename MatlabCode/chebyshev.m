wp=3000*2*pi;
ws=12000*2*pi;
Rp=0.5;
Rs=50;
[N,Wn]=cheb1ord(wp,ws,Rp,Rs,'s');
[b,a]=cheby1(N,Rp,Wn,'low','s');
w=linspace(1,15000,1000)*2*pi;
H=freqs(b,a,w);
magH=abs(H);
phaH=unwrap(angle(H));
plot(w/(2*pi), 20*log10(magH),'k');
xlabel('频率(Hz)');
ylabel('幅度(dB)');
title('切比雪夫模拟滤波器')
grid on