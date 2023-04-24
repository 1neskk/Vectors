#include "vec3.hpp"

int main()
{
    Vec2 v1(5.581f, -2.136f);
    Vec3 v2(1.996f, 3.108f, -4.554);
    std::cout << v1.normalize() << std::endl;
    std::cout << v2.normalize() << std::endl;
    
    return 0;
}
//g++ test.cpp -o test
