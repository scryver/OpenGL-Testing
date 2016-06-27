#ifndef GAMPYCPP_ENGINE_Clock_HPP
#define GAMPYCPP_ENGINE_Clock_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GampyCPP {

class Clock
{
public:
    Clock() : _lastTime(0.0), _newFrameTime(0.0) { }
    ~Clock() { }

    bool initialize() { glfwSetTime(_lastTime); return glfwGetTime() != 0.0; }
    bool shutdown() { _lastTime = 0.0; _newFrameTime = 0.0; return true; }

    void newFrame() { _lastTime = _newFrameTime; _newFrameTime = glfwGetTime(); }
    float timeElapsedLastFrame() { return _newFrameTime - _lastTime; }

private:
    double _lastTime;
    double _newFrameTime;
};

}  // namespace GampyCPP

#endif  // GAMPYCPP_ENGINE_Clock_HPP
