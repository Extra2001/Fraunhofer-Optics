function z = feng(x,y,D,delta,sita,lambda)
% matlab code for evaluating the circ function
    r = abs(x);
    z = double(r<D/2);
    z(r<=D/2) = 0.5;
    N = size(x);
    N = N(1);
    
    for ii=1:N
        phi = (ii - N/2) * delta * 2*pi*sind(sita) / lambda;
        z(ii, :) = z(ii, :).*(cos(phi) + 1i*sin(phi));
    end