#include <iostream>

class person
{
    public:
    int age;
    int ID;
    std::string name;

    void display()
    {
        std::cout<<age<<" "<<ID<<" "<<name<<std::endl;
    }
};

template <typename T>
void swap(T *a,T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}



int main()
{

    person x;
    x.age = 20;
    x.ID = 1234;
    x.name = "ahmed";

    person y;
    y.age = 40;
    y.ID = 5678;
    y.name = "hisham";


    swap(&x,&y);

    x.display();
    y.display();
    
    return 0;
}