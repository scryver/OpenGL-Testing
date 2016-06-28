#include "./clock.hpp"

GampyCPP::Clock::Clock() :
    _lastTime(0.0), _newFrameTime(0.0)
{

}

GampyCPP::Clock::~Clock()
{

}

bool GampyCPP::Clock::initialize()
{
    glfwSetTime(_lastTime);
    return glfwGetTime() != 0.0;
}

bool GampyCPP::Clock::shutdown()
{
    _lastTime = 0.0;
    _newFrameTime = 0.0;
    return true;
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
