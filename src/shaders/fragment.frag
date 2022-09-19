#version 450

layout(location = 0) out vec4 outColor;

// the color depends on the raster stage
void main() {
    // 0 to 1 range
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
}