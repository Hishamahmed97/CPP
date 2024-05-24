#include <iostream>

// template for each function just before them --> generic programming

template<typename T>
T sum(T x,T y)
{
    return x+y;
}

template<typename N>
N sub(N x,N y)
{
    return x-y;
}
int main()
{
float x = 5;float y = 6.5;
std::cout<<sum(x,y)<<std::endl;
std::cout<<sub(x,y)<<std::endl;
return 0;
}