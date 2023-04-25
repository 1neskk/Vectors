#include "vec4.hpp"

int main()
{
    Vec3 v1(7.350f, 0.221f, 5.188f);
    Vec3 v2(2.751f, 8.259f, 3.985f);
    std::cout << v1.angleDeg(v2) << std::endl;
    
    return 0;
}
//g++ test.cpp -o test
