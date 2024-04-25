#include <iostream>
#include "rect_oop.h"

int main()
{
    Rectangle rec; //create instance from the class
    rec.set_length(10);
    rec.set_width(20);

    std::cout<<"entered length = "<<rec.get_length()<<std::endl;
    std::cout<<"entered width = "<<rec.get_width()<<std::endl;
    std::cout<<"Area = "<<rec.get_area()<<std::endl;


}