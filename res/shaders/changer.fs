#version 410 core

in vec3 ourColor;
out vec4 color;

// uniform vec4 ourColor;  // We set this in the OpenGL code (position can be retrieved and set)

void main()
{
    color = vec4(ourColor, 1.0f);
}
