#include "./clock.hpp"

GampyCPP::Clock::Clock()
{
    reset();
}

GampyCPP::Clock::~Clock()
{
    // Empty
}

bool GampyCPP::Clock::reset()
{
    _lastTime = 0.0;
    _newFrameTime = 0.0;
    glfwSetTime(_lastTime);
    return glfwGetTime() != 0.0;
}

void GampyCPP::Clock::newFrame()
{
    _lastTime = _newFrameTime;
    _newFrameTime = glfwGetTime();
}

double GampyCPP::Clock::dtLastFrame() const
{
    return _newFrameTime - _lastTime;
}
