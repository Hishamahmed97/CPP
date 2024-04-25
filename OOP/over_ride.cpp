#include <iostream>

class A
{
    public:
    virtual void display() //for override
    {
        std::cout<<"Hi"<<std::endl;
    }
};

class B : public A
{
    public:
    void display() override //for override
    {
        std::cout<<"Bye Bye"<<std::endl;
    }
};
int main()
{
    A a;
    B b;
    a.display();
    b.display();
}