#version 330
uniform float u_time;
uniform vec2 u_resolution;
out vec4 finalColor;

void main() {
    vec2 relp = gl_FragCoord.xy / u_resolution;
    finalColor = relp.x > .5 ? vec4(relp.yx, relp.y, 1.0) : vec4(.5);
}
