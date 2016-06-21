#version 410 core
out vec4 color;

uniform vec4 ourColor;  // We set this in the OpenGL code

void main()
{
    color = ourColor;
}
