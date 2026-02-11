#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Doing the Book of Shaders");

    Shader shader = LoadShader(0, "shader.fs");
    int timeLoc = GetShaderLocation(shader, "u_time");

    while (!WindowShouldClose()) {
        float time = GetTime();
        SetShaderValue(shader, timeLoc, &time, SHADER_UNIFORM_FLOAT);

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
