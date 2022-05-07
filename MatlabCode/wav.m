[x,Fs] = audioread("C:\Users\jingx\Downloads\保卫黄河.wav");

x = x(:,1);
x = x';
N = length(x);%求取抽样点数
t = (0:N-1)/Fs;%显示实际时间
x = x+sin(2*pi*5000*t)./200+sin(2*pi*10000*t)./200;

% %FIR
% NN    = 50;       % Order
% flag = 'scale';  % Sampling Flag
% win = blackman(NN+1);
% b  = fir1(NN, 5/48);
% figure(1)
% freqz(b)
% Hd = dfilt.dffir(b);
% x = filter(Hd, x);

% IIR
% Fs:信号的采样频率
% fp：滤波器的通带频率
fp = 2400;
% fs:滤波器的截止频率
fs = 5000;
% Ap：通带最大衰减
Ap = 3;
% As：阻带最小衰减
As = 20;
Wp = 2*pi*fp/Fs;
Ws = 2*pi*fs/Fs;
[n,Wc] = buttord(Wp/pi,Ws/pi,Ap,As);
[b,a] = butter(n,Wc,'low');
omega=[Wp Ws]; 
figure(1)
freqz(b,a);

figure(2)
y = fft(x);%对信号进行傅里叶变换
f = Fs/N*(0:round(N/2)-1);%显示实际频点的一半，频域映射，转化为HZ
subplot(211);
plot(t,x,'g');%绘制时域波形
xlabel('Time/s');ylabel('Amplitude');
title('信号的波形');
grid;
subplot(212);
plot(f,abs(y(1:round(N/2))));
xlabel('Frequency/Hz');ylabel('Amplitude');
title('信号的频谱');
grid;

x = filter(b, a, x);

figure(3)
y = fft(x);%对信号进行傅里叶变换
f = Fs/N*(0:round(N/2)-1);%显示实际频点的一半，频域映射，转化为HZ
subplot(211);
plot(t,x,'g');%绘制时域波形
xlabel('Time/s');ylabel('Amplitude');
title('信号的波形');
grid;
subplot(212);
plot(f,abs(y(1:round(N/2))));
xlabel('Frequency/Hz');ylabel('Amplitude');
title('信号的频谱');
grid;