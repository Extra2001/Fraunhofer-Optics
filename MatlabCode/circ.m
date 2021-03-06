function z = circ(x,y,D,delta,sita,lambda)
% matlab code for evaluating the circ function
    r = sqrt(x.^2+y.^2);
    z = double(r<D/2);
    z(r == D/2) = 0.5;
    N = size(x);
    N = N(1);
    z = complex(z);
    for ii=1:N
        phi = double(ii - N/2) * delta * 2*pi*sind(sita) / lambda;
        z(ii, :) = z(ii, :).*(cos(phi) + 1i*sin(phi));
    end