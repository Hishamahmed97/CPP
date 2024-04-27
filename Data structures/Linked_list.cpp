#include <iostream>
template <typename T>
class Stack
{
    private:
    struct Node
    {
        T item;
        Node *next;
    };
    Node *top, *current;

    public:
    Stack() : top(NULL)
    {

    }
    void push(T value)
    {
        Node *newItem
    }
    void pop()
    {
        if (Empty())
        {
            std::cout <<"stack is empty on pop ";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop(T &stackTop)
    {
        if (Empty())
        {
            std::cout<<"stack is empty on pop save";
        }
        else
        {
            stackTop = Top->item;
            Node *temp = top;
            top = top->next;
            temp->next = Null;
        }
    }
}