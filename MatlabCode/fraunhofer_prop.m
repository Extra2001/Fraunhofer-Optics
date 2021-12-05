function [Uout, x2, y2] = fraunhofer_prop(Uin, lambda, delta, Dz)
% function [Uout, x2, y2] = fraunhofer_prop(Uin, wave, delta, Dz)
% performing a Fraunhofer propagation 
 
% Uin : Source-plane optical field
% lambda : wavelength of the source
% delta : grid spacing in source plane
% Dz : the distance between object and lens
% Uout : optical field of observation plane 
% x2, y2 : the coordinate in the observation plane
 
    N = size(Uin,1); % assume square grid
    k = 2*pi/lambda; % optical wavevector
    fx = (-N/2:N/2-1)/(N*delta);
    % observation plane coordinates
    [x2, y2] = meshgrid(lambda * Dz * fx);
    clear('fx');
    Uout = exp(1i*k/(2*Dz)*(x2.^2+y2.^2))...
        / (1i*lambda*Dz) .* ft2(Uin,delta);