#include "vec3.hpp"

template <class T>
class vec4
{
public:
    union
    {
        struct { T x, y, z, w; };
        struct { T r, g, b, a; };
        struct { T V[4]; };
    };

    vec4() : x(0), y(0), z(0), w(0) {}
    vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    vec4(const vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    vec4(const vec3<T>& v, T w) : x(v.x), y(v.y), z(v.z), w(w) {}

    vec4& operator=(const vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }

    vec4& operator+=(const vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
    vec4& operator-=(const vec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
    vec4& operator*=(T s) { x *= s; y *= s; z *= s; w *= s; return *this; }
    vec4& operator/=(T s) { x /= s; y /= s; z /= s; w /= s; return *this; }

    vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
    vec4 operator-(const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
    vec4 operator*(T s) const { return vec4(x * s, y * s, z * s, w * s); }
    vec4 operator/(T s) const { return vec4(x / s, y / s, z / s, w / s); }

    //Scalar operations
    friend vec4 operator*(T s, const vec4& v) { return vec4(s * v.x, s * v.y, s * v.z, s * v.w); }
    friend vec4 operator/(T s, const vec4& v) { return vec4(s / v.x, s / v.y, s / v.z, s / v.w); }

    vec4& operator++() { ++x; ++y; ++z; ++w; return *this; }
    vec4& operator--() { --x; --y; --z; --w; return *this; }
    vec4 operator++(int) { vec4 v = *this; x++; y++; z++; w++; return v; }
    vec4 operator--(int) { vec4 v = *this; x--; y--; z--; w--; return v; }

    //Unary minus
    vec4& operator-() { x = -x; y = -y; z = -z; w = -w; return *this; }

    bool operator==(const vec4& v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }
    bool operator!=(const vec4& v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }

    T angleRad(const vec4& v) const { return acos(dot(v) / (length() * v.length())); }
    T angleDeg(const vec4& v) const { return angleRad(v) * 180 / M_PI; }
    T dot(const vec4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
    vec4 cross(const vec4& v) const { return vec4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0); }
    T length() const { return sqrt(x * x + y * y + z * z + w * w); }
    vec4 proj(const vec4& v) const { return dot(v) / (length() * length()) * (*this); }
    vec4 normalize() const { return *this / length(); }

    friend std::ostream& operator<<(std::ostream& os, const vec4& v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, vec4& v)
    {
        is >> v.x >> v.y >> v.z >> v.w;
        return is;
    }

    T& operator[](int i) { return V[i]; }
    const T& operator[](int i) const { return V[i]; }
};
typedef vec4<float> Vec4;
