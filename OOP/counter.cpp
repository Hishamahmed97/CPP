#include<iostream>
class car
{
    private:
    std::string factory;
    std::string color;
    int model;
    static int counter;

    public :
    car() : factory("Mini"),color("red"),model(2019) // parametrized constructor
    {
        std::cout<<"constructor"<<std::endl;
        counter ++;
    }
    int get_counter()
    {
        return counter;
    }
    

};

    int car::counter = 0; //global variable

int main()
{
    car c1;
    car c2;
    car c3;

    std::cout<<c3.get_counter()<<std::endl;
    return 0;
}
