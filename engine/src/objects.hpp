#ifndef GFLW_GAME_Objects_HPP
#define GFLW_GAME_Objects_HPP

#include <GL/glew.h>

namespace GampyCPP {

struct Position2D {
    explicit Position2D(float x_ = 0.0f, float y_ = 0.0f) : x(x_), y(y_) { }
    Position2D(const Position2D& copy) : x(copy.x), y(copy.y) { }
    GLfloat x;
    GLfloat y;

    Position2D& operator=(const Position2D& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
};

struct Position3D {
    explicit Position3D(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f) :
            x(x_), y(y_), z(z_) { }
    Position3D(const Position2D& xy, float z_ = 0.0f) :
            x(xy.x), y(xy.y), z(z_) { }
    Position3D(const Position3D& copy) : x(copy.x), y(copy.y), z(copy.z) { }
    GLfloat x;
    GLfloat y;
    GLfloat z;

    Position3D& operator=(const Position2D& other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    Position3D& operator=(const Position3D& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

struct ColorRGB {
    explicit ColorRGB(float red = 0.0f, float green = 0.0f, float blue = 0.0f) :
            r(red), g(green), b(blue) { }
    ColorRGB(const ColorRGB& copy) : r(copy.r), g(copy.g), b(copy.b) { }
    GLfloat r;
    GLfloat g;
    GLfloat b;

    ColorRGB& operator=(const ColorRGB& other) {
        r = other.r;
        g = other.g;
        b = other.b;
        return *this;
    }
};

struct ColorRGBA {
    explicit ColorRGBA(float red = 0.0f, float green = 0.0f, float blue = 0.0f,
                       float alpha = 1.0f) :
            r(red), g(green), b(blue), a(alpha) { }
    ColorRGBA(const ColorRGB& rgb, float alpha = 1.0f) :
            r(rgb.r), g(rgb.g), b(rgb.b), a(alpha) { }
    ColorRGBA(const ColorRGBA& copy) :
            r(copy.r), g(copy.g), b(copy.b), a(copy.a) { }
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;

    ColorRGBA& operator=(const ColorRGB& other) {
        r = other.r;
        g = other.g;
        b = other.b;
        return *this;
    }

    ColorRGBA& operator=(const ColorRGBA& other) {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
        return *this;
    }
};

struct TexCoord2D {
    explicit TexCoord2D(float u_ = 0.0f, float v_ = 0.0f) : u(u_), v(v_) { }
    TexCoord2D(const TexCoord2D& copy) : u(copy.u), v(copy.v) { }
    GLfloat u;
    GLfloat v;

    TexCoord2D& operator=(const TexCoord2D& other) {
        u = other.u;
        v = other.v;
        return *this;
    }
};

}

#endif  // GFLW_GAME_Objects_HPP
