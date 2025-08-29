#include <raylib.h>
#include <cmath>
#include <rlgl.h>

void drawEarthOrbit(float orbit_radius);
void drawMoonOrbit(float orbit_radius, Vector3 earth_posision);
Vector3 getNewEarthPosition(float orbit_radius, float current_time);
Vector3 getNewMoonPosition(float orbit_radius, float current_time, Vector3 earth_position);
Vector3 getNewObjectPosition(float orbit_radius, float current_time, Vector3 main_position, float speed);
void drawOrbit(float orbit_radius, Vector3 main_position);