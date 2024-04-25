#include <iostream>
#include "rect_oop.h"

        void Rectangle::set_length(float len) // resolution scope was added because class is defined in other file
        {
            if (len >=0)
            {
            length = len;
            }
            else
            std::cout<<"Error, please enter positive number for length"<<std::endl;
        }
        void Rectangle::set_width(float wid)
        {
            if (wid >= 0)
            {
                width = wid;
            }
            else
            std::cout<<"Error, please enter positive number for width "<<std::endl;
        }

        float Rectangle::get_length()
        {
            return length;
        }
        float Rectangle::get_width()
        {
            return width;
        }
        float Rectangle::get_area()
        {
            return length*width;
        }
