#include "./window.hpp"

#include <iostream>

GLFWInitException glfwInitException;
CreateWindowException createWindowException;
GLEWInitException glewInitException;

Window::Window() :
    _glfwWindow(nullptr),
    _wireMode(false)
{
    if (!glfwInit())
    {
        // Initialization failed
        throw glfwInitException;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    _glfwWindow = glfwCreateWindow(800, 600, "Window Init",
                                   nullptr, nullptr);

    if (_glfwWindow == nullptr)
    {
        glfwTerminate();
        throw createWindowException;
    }
    activateContext();

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw glewInitException;
    }

    glfwSetWindowUserPointer(_glfwWindow, this);

    glfwSetKeyCallback(_glfwWindow, _glfwKeyCallback);

    glfwGetFramebufferSize(_glfwWindow, &_width, &_height);

    glViewport(0, 0, _width, _height);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

Window::~Window() {
    std::cout << "Window destroyed" << std::endl;
    glfwTerminate();
}

void Window::_glfwKeyCallback(GLFWwindow* window, int key, int scancode,
                              int action, int mode) {
    // When a user presses the escape key, we set the WindowShouldClose property to true,
    // closing the application
    Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        w->_wireMode = !w->_wireMode;
        glPolygonMode(GL_FRONT_AND_BACK, w->_wireMode ? GL_LINE : GL_FILL);
    }
}
