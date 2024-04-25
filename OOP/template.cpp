#include <iostream>

template<typename T>
T sum(T x,T y)
{
    return x+y;
}


int main()
{
float x =5;float y = 6.5;
std::cout<<sum(x,y)<<std::endl;
return 0;
}