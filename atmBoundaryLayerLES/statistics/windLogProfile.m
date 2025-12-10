%----------------------------------------------------------------------------
%   University    |   DIFA - Dept of Physics and Astrophysics 
%       of        |   Research group in Atmospheric Physics
%    Bologna      |   (https://physics-astronomy.unibo.it)
%----------------------------------------------------------------------------
% Program Name
%       functionPlot.m
%
% Author
%       Carlo Cintolesi
%
% Revision history
%
% Program Purpose 
%       Print data to plot a function 
%       
% Note
%       run in terminal typing "octave -q functionPlot.m"
%
%------------------------------------------------------------------------------
%
%                                     ***
%
% -----------------------------------------------------------------------------

% Parameters
k     = 0.41;
h     = 1;
URef  = 22.74;                  % URef = uRef/uStar
Ret   = 590;

% Computation of z0
% -----------------
z0 = e^(-URef*k)

% Computation of log profile
% --------------------------
%z = 0.0001:0.05:1;             % linear partition
z = logspace(-4,0);             % log partition
U = (1/k)*log(z/z0); 

% Write the result on the output-file
fileID = fopen('atmLogU.dat','w');
fprintf(fileID,'%g %g \n', [z; U]);
fclose(fileID);


