#include "vec4.hpp"

int main()
{
    Vec3 v1(8.462f, 7.893f, -8.187f);
    Vec3 v2(6.984f, -5.975f, 4.778f);
    std::cout << v1.cross(v2) << std::endl;
    //std::cout << v2.normalize() << std::endl;
    
    return 0;
}
//g++ test.cpp -o test
