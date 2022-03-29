#include <iostream>
#include "funcs.h"
#include "coord3d.h"
#include <cmath>


double length(Coord3D *p){

return sqrt(pow(p->x,2)+pow(p->y,2)+pow(p->z,2));

}


Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
   double x = length( p1);
   double y = length( p2);
   if (x < y){
     return p2;
   }
   else if (y > x){
     return p1;
   }
   else{
     return p1;
   }

}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
 ppos->x = ppos->x + pvel->x * dt;
 ppos->y = ppos->y + pvel->y * dt;
 ppos->z = ppos->z + pvel->z * dt;
}









Coord3D* createCoord3D(double x, double y, double z){
Coord3D *p1;
p1 = new Coord3D;
*p1 = {x,y,z};
return p1;


}





void deleteCoord3D(Coord3D *p){
  delete p;
  p = nullptr;



}
