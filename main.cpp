#include <iostream>
#include "coord3d.h"
#include "funcs.h"

int main()
{
std::cout << "Task A takes point P and outputs the length \n" << std::endl;
Coord3D pointP = {10,20,30};
Coord3D pointQ = {-20, 21, -22};
std::cout << length(&pointP) << std::endl;

std::cout << "\nTask B takes point P and point Q and outputs the farther length\n" << std::endl;
//std::cout << length(&pointQ) << std::endl;

std::cout << "Address of P: " << &pointP << std::endl;
std::cout << "Address of Q: " << &pointQ << std::endl << std::endl;
Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
std::cout << "ans = " << ans << std::endl;


std::cout << "\nTask C takes a point pos and a velocity vel and outputs the new position\n" << std::endl;
Coord3D pos = {0, 0, 100.0};
Coord3D vel = {1, -5, 0.2};
move(&pos, &vel, 2.0);
std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;


double x = 10;
double y = 20;
double z = 30;
double a = 5.5;
double b = -1.4;
double c = 7.77;
std::cout << "\nTask E creates a variable ppos and pvel dynamically" <<
" using values that were given and then deletes the variables to free storage\n" << std::endl;
Coord3D *ppos = createCoord3D(x,y,z);

Coord3D *pvel = createCoord3D(a,b,c);
move(ppos, pvel, 10.0);
std::cout << "Coordinates after 10 seconds: " <<
(*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

deleteCoord3D(ppos);
deleteCoord3D(pvel);


  return 0;
}
