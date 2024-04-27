#include <iostream>

const int MAX_SIZE = 100;

template <class T>

class Stack
{
    private:
    int top;
    T item[MAX_SIZE];
    public:
    //constructor
    Stack():top(-1)
    {

    }
    //to push element
    void push(T element)
    {
        if (top>=MAX_SIZE)
        {
            std::cout<<"stack is full";
        }
        else
        {
            top++;
            item[top] = element;
        }
    }
    bool isempty()
    {
        return top <0;
    }
    
    void pop()
    {
        if (!isempty())
        {
            top--;
        }
        else
        {
            std::cout<<"stack is empty in pop";
        }
    }
    //function override for pop to save pop value
    void pop(T &element)
    {
        if (!isempty())
        {
            element=item[top];
            top--;
        }
        else
        {
            std::cout<<"stack is empty at pop save";
        }
    }
    void getTop(T &stackTop)
    {
        if (!isempty())
        {
            stackTop = item[top];
            std::cout<<stackTop;
        }
        else
        {
            std::cout<<"stack is empty at get top";
        }
    }
    void print()
    {
        std::cout<<"[ ";
        for (int i=top;i>=0;i--)
        {
            std::cout<<item[i]<<", ";
        }
         std::cout<<"] \n";
    }

};

int main()
{
    Stack<int> arr;
    arr.push(20);
    arr.push(50);
    arr.push(12);
    arr.push(1);
    arr.push(3);
    arr.push(16);
    arr.print();
    //arr.pop();
    int y = 0;
    arr.pop(y);
    std::cout<<"y = "<<y<<"\n";
    int x = 0;
    std::cout<<"x = ";
    arr.getTop(x);

    Stack<std::string> mystring;
    mystring.push("Hisham");
    mystring.push("ahmed");
    mystring.push("mohamed");
    mystring.push("ahmed");
    mystring.print();
    return 0;
}