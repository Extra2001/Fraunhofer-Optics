x = 1:128;
y = sin(x);
yy = fft(y);
yyy= yy.*yy;
plot(x, abs(yyy))