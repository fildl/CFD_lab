%----------------------------------------------------------------------------
%   University    |   DIFA - Dept of Physics and Astrophysics 
%       of        |   Research group in Atmospheric Physics
%    Bologna      |   (https://physics-astronomy.unibo.it)
%----------------------------------------------------------------------------
% Program Name
%       plotData.m
%
% Author
%       Carlo Cintolesi
%
% Revision history
%       First version 24 Nov 2020
%
% Program Purpose 
%       Plot with octave/matlab
%       
% Note
%       run in terminal typing "octave -q plotData.m"
%
%------------------------------------------------------------------------------

% Info:
printf('RUNNING: plotData.m ------------------------------------------------\n')
set(0, "defaultlinelinewidth", 2);

% Open data files (three columns format)
A = load('line_UMean.xy');
B = load('atmLogU.dat');

% Organise data
z   = A(:,1);               % First column (z coordinate)
Ux  = A(:,2);
Uy  = A(:,3);
Uz  = A(:,4);

zlog= B(:,1);
Ulog= B(:,2);

% Plot Data
hold on
plot(Ux,z)
plot(Ulog,zlog, '--')

% - axes (if needed)
%axis([-1 1 -2 2])        % [xMin xMax yMin yMax]

% - labels
xlabel('< U_x >/U_*')
ylabel('z/H')

% - legend
legend('LES','Theoretical')
legend('Location','northwest')
legend('boxoff')

% - font
set(gca, "linewidth", 2, "fontsize", 16)
set(legend, "fontsize", 16)
set(legend, 'LineWidth', 2);

% - print
printf('\n Done! Plot save in figure.png \n \n')
print -dpng figure.png
hold off

printf('-----------------------------------------------------------------end \n \n')
