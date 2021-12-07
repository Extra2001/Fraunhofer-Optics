function I = circ_fraunhofer(L, D, N, f, sita, lambda, xd, yd)
    N = double(N);
    delta = double(L/N);
    x = double((-N/2:N/2-1))*delta;
    k = 2*pi/ lambda;
    [x1,y1] = meshgrid(x);
    aperture = circ(x1, y1, D, delta, sita, lambda);

    fx = (3.66*lambda * f/D*  (2.0*double((-N/2: N/2-1)) / double(N))) -(xd+f*tand(sita));
    fy = (3.66*lambda * f/D*  (2.0*double((-N/2: N/2-1)) / double(N))) -(yd+f*tand(sita));

    [x2, y2] = meshgrid(fx,fy);
    function res = temp_func(aa, bb, cc)
        res = aa*exp(-1i*k/f*((x2*bb+y2*cc)))*delta^2;
    end
    result = ((arrayfun(@temp_func, aperture, x1, y1, 'UniformOutput', false)));
    result
    %result = aperture * exp(-1i*k/f*((x2*x1+y2*y1))) *delta^2;
    result = result /lambda/f;
    I=real(result.*conj(result));
    imagesc(I)
end
