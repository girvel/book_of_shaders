#version 330
uniform float u_time;
uniform vec2 u_resolution;
out vec4 finalColor;

float PI = 3.14;

float box(vec2 p, float x0, float y0, float x1, float y1) {
    return p.x >= x0 && p.x <= x1 && p.y >= y0 && p.y <= y1 ? 1. : 0.;
}

vec3 white = vec3(1., 1., 1.);
vec3 black = vec3(0., 0., 0.);
vec3 red = vec3(1., 0., 0.);

float ridge(float x) {
    return abs(2 * mod(x, 1) - 1) / 2;
}

float f(float x) {
    return ridge(x);
}

void main() {
    vec2 relp = gl_FragCoord.xy / u_resolution.y;
    vec3 color = vec3(relp.x, relp.y, ridge(u_time / 10));

    // relp -= .5;
    // relp *= 10;
    // vec3 color = relp.y >= f(relp.x) ? white : black;
    // color = mix(color, red, smoothstep(.02, 0, abs(relp.y)));
    // color = mix(color, red, smoothstep(.02, 0, abs(relp.x)));

    finalColor = vec4(color, 1.);
}
