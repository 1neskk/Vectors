#include <iostream>
#include <cmath>
#include <cassert>

template <class T>
class vec2
{
public:
    union
    {
        struct { T x, y; };
        struct { T s, t; };
        struct { T u, v; };
        struct { T V[2]; };
    };

    vec2() : x(0), y(0) {}
    vec2(T x, T y) : x(x), y(y) {}
    vec2(const vec2& v) : x(v.x), y(v.y) {}

    vec2& operator=(const vec2& v) { x = v.x; y = v.y; return *this; }

    vec2& operator+=(const vec2& v) { x += v.x; y += v.y; return *this; }
    vec2& operator-=(const vec2& v) { x -= v.x; y -= v.y; return *this; }
    vec2& operator*=(T s) { x *= s; y *= s; return *this; }
    vec2& operator/=(T s) { x /= s; y /= s; return *this; }

    vec2 operator+(const vec2& v) const { return vec2(x + v.x, y + v.y); }
    vec2 operator-(const vec2& v) const { return vec2(x - v.x, y - v.y); }
    vec2 operator*(T s) const { return vec2(x * s, y * s); }
    vec2 operator/(T s) const { return vec2(x / s, y / s); }

    //Scalar operations
    friend vec2 operator*(T s, const vec2& v) { return vec2(s * v.x, s * v.y); }
    friend vec2 operator/(T s, const vec2& v) { return vec2(s / v.x, s / v.y); }

    vec2& operator++() { ++x; ++y; return *this; }
    vec2& operator--() { --x; --y; return *this; }
    vec2 operator++(int) { vec2 v(*this); x++; y++; return v; }
    vec2 operator--(int) { vec2 v(*this); x--; y++; return v; }

    //Unary minus
    vec2 operator-() const { return vec2(-x, -y); }

    bool operator==(const vec2& v) const { return x == v.x && y == v.y; }
    bool operator!=(const vec2& v) const { return x != v.x || y != v.y; }

    friend std::ostream& operator<<(std::ostream& os, const vec2& v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, vec2& v)
    {
        is >> v.x >> v.y;
        return is;
    }

    T angleRad(const vec2& v) const { return acos(dot(v) / (length() * v.length())); }
    T angleDeg(const vec2& v) const { return angle(v) * 180 / M_PI; }
    T dot(const vec2& v) const { return x * v.x + y * v.y; }
    T length() const { return sqrt(x * x + y * y); }
    vec2& normalize() { *this /= length(); return *this; }

    T& operator[](int i) { assert(i >= 0 && i < 2); return V[i]; }
    const T& operator[](int i) const { assert(i >= 0 && i < 2); return V[i]; }
};
typedef vec2<float> Vec2;
