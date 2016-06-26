#ifndef GAMPYCPP_ENGINE_VECTOR2D_HPP
#define GAMPYCPP_ENGINE_VECTOR2D_HPP


namespace GampyCPP {

namespace Math {

struct Vector2D
{
    float x;
    float y;
    explicit Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) { }
};

inline Vector2D operator+(const Vector2D& left, const Vector2D& right);
inline Vector2D operator*(float scalar, const Vector2D& vector);
inline Vector2D operator*(const Vector2D& vector, float scalar);

#include "./vector2d.inl"

}  // namespace Math

}  // namespace GampyCPP

#endif  // GAMPYCPP_ENGINE_VECTOR2D_HPP
