#ifndef GLFW_GAME_Window_HPP
#define GLFW_GAME_Window_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>

#include "./objects.hpp"

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


namespace GampyCPP {

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
        glfwSwapBuffers(_glfwWindow);
    }

    void activateContext();

    void backgroundColor(float r, float g, float b, float a = 1.0f) {
        _backgroundColor.r = r;
        _backgroundColor.g = g;
        _backgroundColor.b = b;
        _backgroundColor.a = a;

        glClearColor(_backgroundColor.r,
                     _backgroundColor.g,
                     _backgroundColor.b,
                     _backgroundColor.a);
    }

    void backgroundColor(const ColorRGB& color) {
        _backgroundColor = color;
        glClearColor(_backgroundColor.r,
                     _backgroundColor.g,
                     _backgroundColor.b,
                     _backgroundColor.a);
    }

    void backgroundColor(const ColorRGBA& color) {
        _backgroundColor = color;
        glClearColor(_backgroundColor.r,
                     _backgroundColor.g,
                     _backgroundColor.b,
                     _backgroundColor.a);
    }

private:
    GLFWwindow*     _glfwWindow;
    bool            _wireMode;
    int             _width, _height;
    ColorRGBA _backgroundColor;

    static void _glfwKeyCallback(GLFWwindow* window, int key, int scancode,
                                 int action, int mode);

    static int _referenceCount;
};

}  // namespace GampyCPP

#endif  // GLFW_GAME_Window_HPP
