// glsl version 4.5
#version 450

vec2 positions[3] = vec2[](
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5, 0.5)
);

// main function is executed once for each vertex
void main(){

    // vector4, first three component is divided by the last one
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}