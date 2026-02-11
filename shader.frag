#version 330
uniform float u_time;
uniform vec2 u_resolution;
out vec4 finalColor;

float PI = 3.14;

float box(vec2 p, float x0, float y0, float x1, float y1) {
    return p.x >= x0 && p.x <= x1 && p.y >= y0 && p.y <= y1 ? 1. : 0.;
}

vec3 white = vec3(1., 1., 1.);

void main() {
    vec2 relp = gl_FragCoord.xy / u_resolution;
    vec3 color = vec3(0.);
    color += white * box(relp, .1, .1, .2, .2);
    finalColor = vec4(color, 1.);
}
