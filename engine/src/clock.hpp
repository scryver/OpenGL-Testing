#ifndef GAMPYCPP_ENGINE_Clock_HPP
#define GAMPYCPP_ENGINE_Clock_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace GampyCPP {

class Clock
{
public:
    Clock();
    ~Clock();

    bool initialize();
    bool shutdown();

    void newFrame();
    double dtLastFrame() const;

private:
    double _lastTime;
    double _newFrameTime;
};

}  // namespace GampyCPP

#endif  // GAMPYCPP_ENGINE_Clock_HPP
