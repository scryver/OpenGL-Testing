#include "../build/config.h"

#include <cmath>
#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "./renderelement.hpp"
#include "./shaders.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode);


int main(int argc, char* argv[])
{
    std::cout << "Version "
              << GLFW_GAME_VERSION_MAJOR << "." << GLFW_GAME_VERSION_MINOR
              << std::endl;

    if (!glfwInit())
    {
        // Initialization failed
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL",
                                          nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    GLuint shaderProgram = loadShaders("../res/shaders/simple.vs", "../res/shaders/simple.fs");
    GLuint changeShader = loadShaders("../res/shaders/changer.vs", "../res/shaders/changer.fs");
    // glUseProgram(shaderProgram);

    // RenderElement triangle(shaderProgram);
    // triangle.init({
    //     -0.5f, -0.5f, 0.0f,
    //      0.5f, -0.5f, 0.0f,
    //      0.0f,  0.5f, 0.0f
    // });

    RenderElement square(shaderProgram);
    square.init({
        0.85f, 0.85f, 0.0f,  // Top Right
        0.85f, 0.5f, 0.0f,  // Bottom Right
        0.5f, 0.5f, 0.0f,  // Bottom Left
        0.5f, 0.85f, 0.0f   // Top Left
    }, {  // Note that we start from 0!
        0, 1, 3,   // First Triangle
        1, 2, 3    // Second Triangle
    });

    RenderElement cube(changeShader);
    cube.init({
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

    while(!glfwWindowShouldClose(window))
    {
        // Check and call events
        glfwPollEvents();

        // Render
        // ...
        glClear(GL_COLOR_BUFFER_BIT);
        {
            square.draw();
            // triangle.draw();
            cube.draw();

            glBindVertexArray(0);
        }

        // Swap the front/back buffer
        glfwSwapBuffers(window);
    }

    cube.destroy();
    square.destroy();
    // triangle.destroy();

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    static bool wireMode = false;
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        wireMode = !wireMode;
        glPolygonMode(GL_FRONT_AND_BACK, wireMode ? GL_LINE : GL_FILL);
    }
}
