#include "vecBool.h"

int main()
{
    VecBit vec;
    vec.set(5, 8);
    vec.set(2, 1);
    vec.set(3, 1);
    vec.set(6, 1);
    vec.set(11, 1);
    vec.set(12, 1);
    vec.set(0, 1);
    vec.set(1, 1);
    vec.set(4, 1);
    vec.set(1, 0);
    int a = vec[3];
    VecBit b(std::move(vec));
    std::cout << b.size() << std::endl;    
}