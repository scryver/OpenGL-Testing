#ifndef GFLW_GAME_Objects_HPP
#define GFLW_GAME_Objects_HPP

#include <GL/glew.h>

namespace GampyCPP {

struct Position2D {
    GLfloat x;
    GLfloat y;
};

struct Position3D {
    GLfloat x;
    GLfloat y;
    GLfloat z;
};

struct ColorRGB {
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

struct ColorRGBA {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
};

struct TexCoord2D {
    GLfloat u;
    GLfloat v;
};

}

#endif  // GFLW_GAME_Objects_HPP
