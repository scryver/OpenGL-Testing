#include "../build/config.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "./objects.hpp"
#include "./window.hpp"
#include "./renderelement.hpp"
#include "./shader.hpp"


int main(int argc, char* argv[])
{
    std::cout << "Version "
              << GLFW_GAME_VERSION_MAJOR << "." << GLFW_GAME_VERSION_MINOR
              << std::endl;

    Window window;
    window.backgroundColor(GampyCPP::ColorRGB(0.2f, 0.3f, 0.3f));

    Shader simpleShader("../res/shaders/simple.vs", "../res/shaders/simple.fs");
    Shader changeShader("../res/shaders/changer.vs", "../res/shaders/changer.fs");

    RenderElement triangle;
    triangle.init({
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    }, {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    });
    triangle.setShader(&changeShader);

    RenderElement square(&simpleShader);
    square.initIdx({
        0.85f, 0.85f, 0.0f,  // Top Right
        0.85f, 0.5f, 0.0f,  // Bottom Right
        0.5f, 0.5f, 0.0f,  // Bottom Left
        0.5f, 0.85f, 0.0f   // Top Left
    }, {  // Note that we start from 0!
        0, 1, 3,   // First Triangle
        1, 2, 3    // Second Triangle
    });

    RenderElement cube(&changeShader);
    cube.initIdx({
        0.5f, 0.5f, 0.5f,  // Top Right
        0.5f, -0.5f, 0.5f,  // Bottom Right
        -0.5f, -0.5f, 0.5f,  // Bottom Left
        -0.5f, 0.5f, 0.5f,   // Top Left
        0.5f, 0.5f, -0.5f,  // Top Right
        0.5f, -0.5f, -0.5f,  // Bottom Right
        -0.5f, -0.5f, -0.5f,  // Bottom Left
        -0.5f, 0.5f, -0.5f,   // Top Left
    }, {  // Note that we start from 0!
        0, 1, 3,   // Front First Triangle
        1, 2, 3,   // Front Second Triangle
        1, 5, 2,   // Right First Triangle
        5, 6, 2,   // Right Second Triangle
        5, 4, 6,   // Back First Triangle
        4, 7, 6,   // Back Second Triangle
        4, 0, 7,   // Left First Triangle
        0, 3, 7,   // Left Second Triangle
        4, 5, 0,   // Bottom First Triangle
        5, 1, 0,   // Bottom Second Triangle
        3, 2, 7,   // Top First Triangle
        2, 6, 7    // Top Second Triangle
    });

    while(!window.shouldClose())
    {
        // Check and call events
        glfwPollEvents();

        // Render
        // ...
        glClear(GL_COLOR_BUFFER_BIT);
        {
            square.draw();
            triangle.draw();
            // cube.draw();

            glBindVertexArray(0);
        }

        // Swap the front/back buffer
        window.swapBuffers();
    }

    cube.destroy();
    square.destroy();
    triangle.destroy();

    return 0;
}
