#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Doing the Book of Shaders");

    Shader shader = LoadShader(0, "shader.frag");
    if (!IsShaderValid(shader)) return 1;
    int timeLoc = GetShaderLocation(shader, "u_time");
    int resolutionLoc = GetShaderLocation(shader, "u_resolution");

    while (!WindowShouldClose()) {
        float time = GetTime();
        SetShaderValue(shader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
        float resolution[2] = {
            GetScreenWidth(),
            GetScreenHeight(),
        };
        SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

        BeginDrawing();
            ClearBackground(BLACK);
            BeginShaderMode(shader);
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
            EndShaderMode();
            DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadShader(shader);
    CloseWindow();
    return 0;
}
