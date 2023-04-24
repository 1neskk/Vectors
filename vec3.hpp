#include "vec2.hpp"

template <class T>
class vec3
{
public:
    union
    {
        struct { T x, y, z; };
        struct { T r, g, b; };
        struct { T V[3]; };
    };

    vec3() : x(0), y(0), z(0) {}
    vec3(T x, T y, T z) : x(x), y(y), z(z) {}
    vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}
    vec3(const vec2<T>& v, T z) : x(v.x), y(v.y), z(z) {}

    vec3& operator=(const vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }

    vec3& operator+=(const vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    vec3& operator-=(const vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    vec3& operator*=(T s) { x *= s; y *= s; z *= s; return *this; }
    vec3& operator/=(T s) { x /= s; y /= s; z /= s; return *this; }

    vec3 operator+(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }
    vec3 operator-(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }
    vec3 operator*(T s) const { return vec3(x * s, y * s, z * s); }
    vec3 operator/(T s) const { return vec3(x / s, y / s, z / s); }

    //Scalar operations
    friend vec3 operator*(T s, const vec3& v) { return vec3(s * v.x, s * v.y, s * v.z); }
    friend vec3 operator/(T s, const vec3& v) { return vec3(s / v.x, s / v.y, s / v.z); }

    vec3& operator++() { ++x; ++y; ++z; return *this; }
    vec3& operator--() { --x; --y; --z; return *this; }
    vec3 operator++(int) { vec3 v(*this); x++; y++; z++; return v; }
    vec3 operator--(int) { vec3 v(*this); x--; y++; z--; return v; }

    //Unary minus
    vec3 operator-() const { return vec3(-x, -y, -z); }

    bool operator==(const vec3& v) const { return x == v.x && y == v.y && z == v.z; }
    bool operator!=(const vec3& v) const { return x != v.x || y != v.y || z != v.z; }

    T dot(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }
    T length() const { return sqrt(x * x + y * y + z * z); }
    vec3 normalize() const { return *this / length(); }

    friend std::ostream& operator<<(std::ostream& os, const vec3& v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, vec3& v)
    {
        is >> v.x >> v.y >> v.z;
        return is;
    }

    T& operator[](int i) { return V[i]; }
    const T& operator[](int i) const { return V[i]; }
};
typedef vec3<float> Vec3;