#include <iostream>
#include <raylib.h>
#include <cmath>
#include <rlgl.h>
#include "functions.h"

int main()
{
    const int WIDTH = 800, HEIGHT = 800;
    const char *TITLE = "3d with raylib";
    const int FPS = 144;

    int monitor_width, monitor_height;

    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(FPS);

    bool fullscreen = false;
    bool grid = true; 
    bool cursor = false;

    // Camera
    Camera3D camera = {0};
    camera.position = (Vector3){50.0f, 5.0f, 50.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Sun
    Vector3 sun_position = {0.0f, 0.0f, 0.0f};
    float sun_radius = 15.0f;
    // Earth
    float orbit_radius = 30.0f;
    Vector3 earth_position = {0.0f, 0.0f, orbit_radius};
    float earth_radius = 2.5f;
    // Moon
    float moon_orbit_radius = 5.0f;
    Vector3 moon_position = {0.0f, 0.0f, orbit_radius + 5.0f};
    float moon_radius = 0.5f;

    float last_time = 0.0f;

    DisableCursor();

    while (!WindowShouldClose())
    {
        float current_time = GetTime();

        if (IsKeyPressed(KEY_C))
        {
            cursor = !cursor;
            if (cursor)
                EnableCursor();
            else
                DisableCursor();
        }

        if (IsKeyPressed(KEY_F)) 
        {
            if (!fullscreen)
            {
                monitor_width = GetMonitorWidth(0);
                monitor_height = GetMonitorHeight(0);

                SetWindowSize(monitor_width, monitor_height);
                ToggleFullscreen();
                DisableCursor();
            }
            else 
            {
                SetWindowSize(WIDTH, HEIGHT);
                ToggleFullscreen();
                DisableCursor();
            }
        }

        if (IsKeyPressed(KEY_G))
        {
            grid = !grid;
        }

        if (current_time - last_time >= 0.05f)
        {        DrawGrid(20, 10.0f);
            last_time = current_time;

            earth_position = getNewEarthPosition(orbit_radius, current_time);
            moon_position = getNewMoonPosition(moon_orbit_radius, current_time, earth_position);
        }

        if (!cursor) 
        {
            UpdateCamera(&camera, CAMERA_THIRD_PERSON);       
        }
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        DrawSphere(sun_position, sun_radius, YELLOW);
        DrawSphere(earth_position, earth_radius, BLUE);
        DrawSphere(moon_position, moon_radius, GRAY);
        drawEarthOrbit(orbit_radius);
        //DrawText3D(GetFontDefault(), "Earth", {earth_position.x, 3.0f, earth_position.z}, 0.8f, 0.1f, 0.0f, false, WHITE);
        drawMoonOrbit(moon_orbit_radius, earth_position);
        if (grid) 
        {
            DrawGrid(20, 10.0f);
        }
        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}