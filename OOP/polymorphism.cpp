#include <iostream>

class shape
{
    private:
    float len = 5;
    float wid = 6;
    public:
    virtual void area()
    {
        std::cout<<"area of shape :"<<len*wid<<std::endl;
    }
};

class Rectangle : public shape
{
    private:
    float len = 2;
    float wid = 3;

    void area()
    {
        std::cout<<"area of rectangle :"<<len*wid<<std::endl;
    }
};
class circle : public shape
{
    private:
    float r = 2;

    void area()
    {
        std::cout<<"area of circle :"<<(r*r)*3.14<<std::endl;
    }
};

class triangle : public shape
{
    private:
    float b = 2;
    float h = 3;

    void area()
    {
        std::cout<<"area of triangle :"<<0.5*b*h<<std::endl;
    }
};

int main()
{
    shape *shape_ptr;
    shape sh;
    Rectangle rec;
    circle cr;
    triangle tr;
    shape_ptr = &sh;
    shape_ptr->area();
    shape_ptr = &rec;
    shape_ptr->area();
     shape_ptr = &cr;
    shape_ptr->area();
     shape_ptr = &tr;
    shape_ptr->area();


    return 0;
}