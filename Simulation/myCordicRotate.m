function [x,y] = myCordicRotate(angle,stages,numBitsXY,numBitsAngle)
% Designer:     Andrew Carroll
%
% Description:  Simulates digital cordic algorithm in rotation mode. Uses
%               fixed point numbers to determine true accuracy of digital
%               system. Input a rotation angle in radians (0-2pi) and
%               output x and y cordinates on unit circle. Starts at 0 rad
%               on unit circle and rotates counter clockwise. Capable of
%               accepting array inputs.
%
% Inputs:       angle        : angle in radians (0 to 2pi)
%               stages       : number of cordic stages
%               numBitsXY    : # of bits to use for x and y registers
%               numBitsAngle : # of bits to use for atan lookup table
%
% Outputs       x            : x coordinate out
%               y            : y coordinate out

%%

% Setup variable types
x_comp     = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
y_comp     = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
x_comp_new = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
y_comp_new = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
yshift     = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
xshift     = fi(zeros(1,length(angle)),1,numBitsXY,numBitsXY-1);
angleAdd   = fi(zeros(1,length(angle)),0,numBitsAngle,numBitsAngle);
d          = zeros(1,length(angle));
angleTemp  = zeros(1,length(angle));

% Calculate gain of cordic based on # of stages (~.607)
k = 1/sqrt(1+2^(-2*0));
for ii = 1:stages-1
    k      = k*1/sqrt(1+2^(-2*ii));
end

% start at position (1,0)
x_comp(:) = ones(1,length(angle)).*fi(-k,1,numBitsXY,numBitsXY-1); % adjust for cordic gain
y_comp(:) = ones(1,length(angle)).*fi(0,1,numBitsXY,numBitsXY-1);

angle  = fi(angle/(2*pi),0,numBitsAngle,numBitsAngle);

%% Initial Stage
for ii = 1:length(angle)
    if angle(ii) <= .5
        d(ii) = -1;
    else
        d(ii) = 1;
    end;
end

x_comp_new(:) = y_comp.*d*-1;
y_comp_new(:) = x_comp.*d;

angleTemp  = double(angle) + (-d*double(fi(.25,0,numBitsAngle,numBitsAngle)));
angle(:)   = angleTemp;

for ii = 1:length(angle)
    if angle(ii) < .5
        d(ii) = -1;
    else
        d(ii) = 1;
    end;
end
x_comp(:) = x_comp_new;
y_comp(:) = y_comp_new;

%% Loop for rest of stages
for ii = 0:stages-1
    yshift(:)     = bitsra(y_comp.*d,ii);
    x_comp_new(:) = x_comp - yshift;
    xshift(:)     = bitsra(x_comp.*d,ii);
    y_comp_new(:) = y_comp + xshift;
    angleAdd(:)   = ones(1,length(angle)).*fi((abs(atan(2^(-ii))))/2/pi,0,numBitsAngle,numBitsAngle);
    angleTemp     = double(angle) + (-d.*double(angleAdd));
    angle(:)      = angleTemp; 
    for jj = 1:length(angle)
        if angle(jj) >= .5
            d(jj) = 1;
        else
            d(jj) = -1;
        end;
    end
    x_comp(:) = x_comp_new;
    y_comp(:) = y_comp_new;
end;

%% Output
phase = double(angle*2*pi);           % should be 0
x = double(x_comp);
y = double(y_comp);
end