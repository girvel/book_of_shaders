#include "raylib.h"
#include <stddef.h>

typedef struct {
    Shader shader;
    int timeLoc, resolutionLoc;
    long modtime;
} ShaderInfo;

const char *shader_filename = "shader.frag";

void shader_try_reload(ShaderInfo *info) {
    long modtime = GetFileModTime(shader_filename);
    if (info->modtime == modtime) return;
    bool was_zero = info->modtime == 0;
    info->modtime = modtime;

    Shader shader = LoadShader(NULL, shader_filename);
    if (!IsShaderValid(shader)) return;
    TraceLog(LOG_INFO, "Loaded some valid shader");

    if (!was_zero) UnloadShader(info->shader);
    info->shader = shader;
    info->timeLoc = GetShaderLocation(shader, "u_time");
    info->resolutionLoc = GetShaderLocation(shader, "u_resolution");
}

void shader_send(ShaderInfo *info) {
    float time = GetTime();
    SetShaderValue(info->shader, info->timeLoc, &time, SHADER_UNIFORM_FLOAT);
    float resolution[2] = { GetScreenWidth(), GetScreenHeight(), };
    SetShaderValue(info->shader, info->resolutionLoc, resolution, SHADER_UNIFORM_VEC2);
}

int main(void) {
    InitWindow(800, 600, "Doing the Book of Shaders");

    ShaderInfo shader_info = {0};
    while (!WindowShouldClose()) {
        shader_try_reload(&shader_info);
        shader_send(&shader_info);

        BeginDrawing();
            ClearBackground(BLACK);
            BeginShaderMode(shader_info.shader);
                DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
            EndShaderMode();
            DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadShader(shader_info.shader);
    CloseWindow();
    return 0;
}
