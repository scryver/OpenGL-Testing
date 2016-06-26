#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../engine/src/All.hpp"

using GampyCPP::Math::Vector2D;

namespace
{
    Vector2D verts[] =
    {
        Vector2D(+0.0f, +0.1f),
        Vector2D(-0.1f, -0.1f),
        Vector2D(+0.1f, -0.1f),
    };
    const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);
    Vector2D shipPosition(0.0, 0.0);
}

int main(int argc, char* argv[])
{
    std::cout << "GampyCPP Version "
              << GampyCPP::VERSION_MAJOR << "."
              << GampyCPP::VERSION_MINOR
              << std::endl;

    GampyCPP::Window window;
    window.backgroundColor(GampyCPP::ColorRGBA(0.2f, 0.3f, 0.3f, 0.0f));

    GampyCPP::Shader shader2d("../res/shaders/simple2d.vs", "../res/shaders/simple.fs");

    GLuint VBO;
    GLuint VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);
        // glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
    }
    glBindVertexArray(0);

    while(!window.shouldClose())
    {
        // Check and call events
        glfwPollEvents();

        // Render
        glClear(GL_COLOR_BUFFER_BIT);
        {

            shader2d.use();
            glBindVertexArray(VAO);

            Vector2D translatedVerts[NUM_VERTS];
            for (unsigned int i = 0; i < NUM_VERTS; i++)
            {
                translatedVerts[i] = verts[i] + shipPosition;
            }

            glBufferSubData(GL_ARRAY_BUFFER, 0,
                            sizeof(translatedVerts), translatedVerts);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            glBindVertexArray(0);
        }

        // Swap the front/back buffer
        window.swapBuffers();
    }

    return 0;
}
