#version 330
uniform float u_time;
in vec2 fragTexCoord;
out vec4 finalColor;

void main() {
    vec2 p = fragTexCoord;
    vec3 col = 0.5 + 0.5 * cos(u_time + p.xyx + vec3(0, 2, 4));
    finalColor = vec4(col, 1.0);
}
