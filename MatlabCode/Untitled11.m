L = 0.1e-3;
D = 25e-6;
L = D;
N = 128;
f = 500e-3;
sita = 0;
delta = L/N;
lambda = 632.8e-9;
x = (-N/2:N/2-1)*delta;
k = 2*pi/ lambda;
[x1,y1] = meshgrid(x);
aperture = circ(x1,y1,D, delta, sita, lambda);
figure(1)
imagesc(aperture.*conj(aperture))
xd=5e-3;
yd=5e-3;

% fx = ((-N/2:N/2-1)*delta+(xd+f*tand(sita)));
% fy = ((-N/2:N/2-1)*delta+(yd+f*tand(sita)));
fx = (3.66*lambda * f/D*  (2*(-N/2: N/2-1) / N)) -(xd+f*tand(sita));
fy = (3.66*lambda * f/D*  (2*(-N/2: N/2-1) / N)) -(yd+f*tand(sita));

[x2, y2] = meshgrid(fx,fy);
result = zeros(N);
for ii=1:N
    for jj=1:N
        hh = (aperture(ii, jj) * exp(-1i*k/f * ((x2*(ii-N/2)*delta) + (y2*(jj-N/2)*delta))) * delta^2) / lambda / f;
        result = result + hh;
    end
end

figure(2)
imagesc(result.*conj(result))

figure(3)
surf(x2, y2, result.*conj(result))

I=real(result.*conj(result));
