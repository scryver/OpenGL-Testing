#ifndef GLFW_GAME_Window_HPP
#define GLFW_GAME_Window_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>

class GLFWInitException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to initialize GLFW";
    }
};


class CreateWindowException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to create GLFW window";
    }
};


class GLEWInitException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to initialize GLEW";
    }
};


class Window
{
public:
    Window();
    ~Window();

    const int width() const { return _width; }
    const int height() const { return _height; }

    const bool wireMode() const { return _wireMode; }
    void setWireMode(const bool wires) { _wireMode = wires; }

    bool shouldClose() {
        return glfwWindowShouldClose(_glfwWindow);
    }

    void swapBuffers() {
        // Swap the front/back buffer
        glfwSwapBuffers(_glfwWindow);
    }

    void activateContext() {
        glfwMakeContextCurrent(_glfwWindow);
    }

private:
    GLFWwindow*     _glfwWindow;
    bool            _wireMode;
    int             _width, _height;

    static void _glfwKeyCallback(GLFWwindow* window, int key, int scancode,
                                 int action, int mode);
};

#endif  // GLFW_GAME_Window_HPP
