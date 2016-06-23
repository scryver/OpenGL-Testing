#include "./window.hpp"

#ifndef NDEBUG
#include <iostream>
#endif

GLFWInitException glfwInitException;
CreateWindowException createWindowException;
GLEWInitException glewInitException;

int Window::_referenceCount = 0;


Window::Window() :
    _glfwWindow(nullptr),
    _wireMode(false)
{
    if (_referenceCount == 0) {
#ifndef NDEBUG
        std::cout << "GLFW Init" << std::endl;
#endif
        if (!glfwInit())
        {
            // Initialization failed
            throw glfwInitException;
        }
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

    glfwSetWindowUserPointer(_glfwWindow, this);
    glfwSetKeyCallback(_glfwWindow, _glfwKeyCallback);

    glfwGetFramebufferSize(_glfwWindow, &_width, &_height);
    glViewport(0, 0, _width, _height);

    backgroundColor(0.f, 0.f, 0.f, 1.f);

    _referenceCount++;
}

Window::~Window() {
    _referenceCount--;
    if (_referenceCount == 0) {
#ifndef NDEBUG
        std::cout << "GLFW Terminate" << std::endl;
#endif
        glfwTerminate();
    }
}

void Window::activateContext() {
    glfwMakeContextCurrent(_glfwWindow);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        throw glewInitException;
    }
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
