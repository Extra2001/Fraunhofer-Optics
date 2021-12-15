    D = 25e-6;
    N = 512;
    sita = 10;
    lambda = 632.8e-9;
    Lp = 10e-3;
    f = 0.05;
    xd = -1e-3;
    yd = 1e-3;
    sita = atan((yd+f*tand(sita))/f);
    Ls = f*N*lambda/Lp;
    %N = N * 2;
    delta1 = Ls/N;
    x = (-N/2:N/2-1)*delta1;
    [x1, y1] = meshgrid(x);
    r = sqrt(x1.^2 + y1.^2);
    aperture = double(r < D/2);
    aperture(r == D/2) = 0.5;
    aperture = complex(aperture);
    for ii=1:N
        phi = double(ii - N/2) * delta1 * 2*pi*sin(sita) / lambda;
        aperture(ii, :) = aperture(ii, :).*(cos(phi) + 1i*sin(phi));
    end
    for ii=1:N
        phi = double(ii - N/2) * delta1 * 2*pi*sin(atan(xd/f)) / lambda;
        aperture(:, ii) = aperture(:, ii).*(cos(phi) + 1i*sin(phi));
    end
    figure(1)
    imagesc(aperture.*conj(aperture))

    result = fftshift(fft2(aperture));
    % result = result(N/4:N*3/4, N/4:N*3/4);
    
    I=real(result.*conj(result));
    figure(2)
    imagesc(I)