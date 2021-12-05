% example_fraunhofer_circ.m
% Simulating a Fraunhofer diffraction pattern with comparison to the
% analtic result
 
close all; clear all; clc;
 
N = 512;                % number of grid points per side
L = 7.5e-3;             % total size of the grid [m]
delta = L/N;            % source-plane grid spacing [m]
D = 1e-3;               % diameter of the aperture [m]
lambda = 1e-6;          % optical wavelength [m]
k = 2*pi/lambda;
Dz = 20;                % propagation distance [m]
x = (-N/2:N/2-1)*delta;
[x1,y1] = meshgrid(x);
Uin = circ(x1,y1,D);
[Uout, x2, y2] = fraunhofer_prop(Uin, lambda, delta, Dz);
 
Iout = Uout .* conj(Uout); % Numerical intensity

% analytic result
Uout_th = exp(1i*k/(2*Dz)*(x2.^2+y2.^2))...
    / (1i*lambda*Dz)*D^2*pi/4 ...
    .*jinc(D*sqrt(x2.^2+y2.^2)/(lambda*Dz));

Iout_th = Uout_th .* conj(Uout_th); % analytic intensity

% line profile
U_y0 = Uout(:,find(x==0));        % Amplitude
U_y0_th = Uout_th(:,find(x==0));
 
I_y0 = Iout(:,find(x==0));        % Intensity
I_y0_th = Iout_th(:,find(x==0));
 
%
figure,
imagesc(x2(1,:),y2(:,1),Iout)
axis([-0.1 0.1 -0.1 0.1]);axis square;
title('Numerical Intensity On detection plane')
 
figure,
imagesc(x2(1,:),y2(:,1),Iout_th),
axis([-0.1 0.1 -0.1 0.1]);axis square;
title('Analytic Intensity On detection plane')
 
figure, 
plot(x2(1,:),I_y0,'x',x2(1,:),I_y0_th,'-s','linewidth',1.2)
xlim([-0.2 0.2]); xlabel('x [m]'); ylabel('Intensity');
legend('Numerical', 'Analytic')
grid on
 
figure, 
plot(x2(1,:),abs(U_y0),'x',x2(1,:),abs(U_y0_th),'-s','linewidth',1.2)
xlim([-0.2 0.2]); xlabel('x [m]'); ylabel('Irradiance');
legend('Numerical', 'Analytic')
grid on