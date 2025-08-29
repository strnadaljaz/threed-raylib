#include "functions.h"

void drawOrbit(float orbit_radius, Vector3 main_position)
{
    int segments = 120;
    for (int i = 0; i < segments; i++)
    {
        float kot1 = (2 * PI / segments) * i;
        float kot2 = (2 * PI / segments) * (i + 1);
        
        Vector3 p1 = {orbit_radius * cosf(kot1) + main_position.x, 0.0f, orbit_radius * sinf(kot1) + main_position.z};
        Vector3 p2 = {orbit_radius * cosf(kot2) + main_position.x, 0.0f, orbit_radius * sinf(kot2) + main_position.z};

        DrawLine3D(p1, p2, LIGHTGRAY);
    }
}

// void drawEarthOrbit(float orbit_radius)
// {
//     int segments = 120; // 360 stopinj v krogu, prfekten krog, 120 se ne vidi razlika
//     for (int i = 0; i < segments; i++)
//     {
//         float kot1 = (2 * PI / segments) * i;
//         float kot2 = (2 * PI / segments) * (i + 1);

//         Vector3 p1 = {orbit_radius * cosf(kot1), 0.0f, orbit_radius * sinf(kot1)};
//         Vector3 p2 = {orbit_radius * cosf(kot2), 0.0f, orbit_radius * sinf(kot2)};

//         DrawLine3D(p1, p2, LIGHTGRAY);
//     }
// }

// void drawMoonOrbit(float orbit_radius, Vector3 earth_posision)
// {
//     float earth_x = earth_posision.x;
//     float earth_z = earth_posision.z;
//     int segments = 120;
//     for (int i = 0; i < segments; i++)
//     {
//         float kot1 = (2 * PI / segments) * i;
//         float kot2 = (2 * PI / segments) * (i+1);

//         Vector3 p1 = {earth_x +  orbit_radius * cosf(kot1), 0.0f, earth_z + orbit_radius * sinf(kot1)};
//         Vector3 p2 = {earth_x + orbit_radius * cosf(kot2), 0.0f, earth_z + orbit_radius * sinf(kot2)};

//         DrawLine3D(p1, p2, LIGHTGRAY);
//     }
// }

Vector3 getNewObjectPosition(float orbit_radius, float current_time, Vector3 main_position, float speed)
{
    float angle = current_time * 2.0f * PI / speed;
    float new_x = main_position.x + cosf(angle) * orbit_radius; 
    float new_z = main_position.z + sinf(angle) * orbit_radius;

    return {new_x, 0.0f, new_z};
}

// Vector3 getNewEarthPosition(float orbit_radius, float current_time)
// {
//     float angle = current_time * 2.0f * PI / 60;
//     float new_x = cosf(angle) * orbit_radius;
//     float new_z = sinf(angle) * orbit_radius;

//     return {new_x, 0.0f, new_z};
// }

// Vector3 getNewMoonPosition(float orbit_radius, float current_time, Vector3 earth_position)
// {
//     float angle = current_time * 2.0f * PI / 4.48459959f;
//     float new_x = earth_position.x + cosf(angle) * orbit_radius;
//     float new_z = earth_position.z + sinf(angle) * orbit_radius;

//     return {new_x, 0.0f, new_z};
// }