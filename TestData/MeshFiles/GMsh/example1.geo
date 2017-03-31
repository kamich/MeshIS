// Inputs
squareSide = 200; //m
meshThickness = squareSide / 10; 
gridsize = squareSide / 20;

// All numbering counterclockwise from bottom-left corner
Point(1) = {-squareSide/2, -squareSide/2, 0, gridsize};
Point(2) = {squareSide/2, -squareSide/2, 0, gridsize};
Point(3) = {squareSide/2, squareSide/2, 0, gridsize};
Point(4) = {-squareSide/2, squareSide/2, 0, gridsize};
Line(1) = {1, 2};				// bottom line
Line(2) = {2, 3};				// right line
Line(3) = {3, 4};				// top line
Line(4) = {4, 1};				// left line
Line Loop(5) = {1, 2, 3, 4}; 	
// the order of lines in Line Loop is used again in surfaceVector[]
Plane Surface(6) = {5};

surfaceVector[] = Extrude {0, 0, meshThickness} {
 Surface{6};
 Layers{1};
 Recombine;
};

Physical Surface("front") = surfaceVector[0];
Physical Volume("internal") = surfaceVector[1];
Physical Surface("bottom") = surfaceVector[2];
Physical Surface("right") = surfaceVector[3];
Physical Surface("top") = surfaceVector[4];
Physical Surface("left") = surfaceVector[5];
Physical Surface("back") = {6}; // from Plane Surface (6) ...