#include "vec2.hpp"

int main()
{
    Vec2 v1(1.0f, 2.0f);
    Vec2 v2(3.0f, 4.0f);
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    Vec2 v3 = v1 + v2;
    Vec2 v4 = v1 - v2;
    Vec2 v5 = v1 * 2;
    Vec2 v6 = v1 / 2;
    Vec2 v7 = -v1;
    float dot = v1.dot(v2);
    float length = v1.length();
    Vec2 v8 = v1.normalize();
    return 0;
    //git test
}

//g++ test.cpp -o test