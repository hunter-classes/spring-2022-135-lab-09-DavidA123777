#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include <cmath>
#include "coord3d.h"
TEST_CASE("Checks to see that the length of the vector is accurate"){
  Coord3D pointA = {1,1,1};
  CHECK(length(&pointA) == sqrt(3));
  Coord3D pointB = {0,0,0};
  CHECK(length(&pointB) == 0);
  Coord3D pointC = {0,0,-2};
  CHECK(length(&pointC) == 2);
}

TEST_CASE("checks output when the first point is farther"){
  Coord3D pointD = {10,20,30};
  Coord3D pointE = {5,10,20};
CHECK(fartherFromOrigin(&pointD, &pointE) == &pointD);
}

TEST_CASE("checks output when the second point is farther"){
  Coord3D pointD = {5,5,10};
  Coord3D pointE = {5,10,20};
CHECK(fartherFromOrigin(&pointD, &pointE) == &pointE);
}

TEST_CASE("checks output when both points have the same length, returns first point"){
  Coord3D pointD = {5,10,20};
  Coord3D pointE = {5,10,20};
CHECK(fartherFromOrigin(&pointD, &pointE) == &pointD);
}

TEST_CASE("Checks to see that the position of the object moved correctly"){
   Coord3D pos = {0 , 0 , 100.0};
   Coord3D vel = {1, -5, 0.2};
   move(&pos, &vel, 2.0);
   CHECK(pos.x == 2);
   CHECK(pos.y == -10);
   CHECK(pos.z == 100.4);

}
TEST_CASE("Checks to see that the position of the object moved correctly when dt = 0"){
   Coord3D pos = {0 , 0 , 100.0};
   Coord3D vel = {1, -5, 0.2};
   move(&pos, &vel, 0);
   CHECK(pos.x == 0);
   CHECK(pos.y == 0);
   CHECK(pos.z == 100.0);

}
TEST_CASE("Checks to see that the position of the object moved correctly when dt is negative"){
   Coord3D pos = {0 , 0 , 100.0};
   Coord3D vel = {1, -5, 0.2};
   move(&pos, &vel, -1);
   CHECK(pos.x == -1);
   CHECK(pos.y == 5);
   CHECK(pos.z == 99.8);

}


TEST_CASE("Checks that a variable is created dynamically and equivalent to a variable with the same coordinates"){
  double x = 10;
  double y = 20;
  double z = 30;
  Coord3D pointA = {10,20,30};
  Coord3D *pos = createCoord3D(x,y,z);
  CHECK(pos->x == pointA.x);
  CHECK(pos->y == pointA.y);
  CHECK(pos->z == pointA.z);
}

TEST_CASE("Checks that a variable is deleted dynamically through a function"){
  double x = 10;
  double y = 20;
  double z = 30;
  Coord3D *pos = createCoord3D(x,y,z);
  deleteCoord3D(pos);
  //CHECK(pos->x != 10);
  //CHECK(pos->x != 20);
  //CHECK(pos->z != 30);


}


// add your tests here
