#version 410 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec2 position;

// Values that stay constant for the whole mesh.
// uniform mat4 MVP;

void main() {
    gl_Position = vec4(position.x, position.y, 0.0, 1.0);
}
