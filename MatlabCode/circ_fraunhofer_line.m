function II = circ_fraunhofer_line(D, N, sita, lambda, f, xd, yd)
II= zeros(N,N);
    Lp = 10e-3;
    for iii= -2:2
        sital = sita;
        sital = sital + iii;
    sital = atan((yd+f*tand(sital))/f);
    Ls = f*N*lambda/Lp;
    delta = Ls/N;
    x = (-N/2:N/2-1)*delta;
    [x1, y1] = meshgrid(x);
    r = sqrt(x1.^2 + y1.^2);
    aperture = double(r < D/2);
    aperture(r == D/2) = 0.5;
    aperture = complex(aperture);
    for ii=1:N
        phi = double(ii - N/2) * delta * 2*pi*sin(sital) / lambda;
        aperture(ii, :) = aperture(ii, :).*(cos(phi) + 1i*sin(phi));
    end
    for ii=1:N
        phi = double(ii - N/2) * delta * 2*pi*sin(atan(xd/f)) / lambda;
        aperture(:, ii) = aperture(:, ii).*(cos(phi) + 1i*sin(phi));
    end
    result = fftshift(fft2(aperture));
    I=real(result.*conj(result));
        II =II + I;
    end
end
