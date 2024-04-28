#include <iostream>
template <class T>
class Stack
{
    private:
    struct Node //Node is item and next
    {
        T item;
        Node * next;
    };
    // top and current are not for node, they are for the list (stack)
    Node * top, * current;
    public:
    Stack():top(Null)
    {

    }
    
    void push(T value)
    {
        Node *newItem = new Node; //create node in heap when pushing a value
        {
            if (newItem ==NULL)
            {
                std::cout<<"stack push cannot allocate memory";
            }
        }
        else
        {
            newItem->item = value;
            newItem->next = top;
            top = newItem;
        }
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void pop()
    {
        if(isEmpty())
        {
            std::cout<<"stack is empty on pop";
        }
        else
        {
            Node * temp = top;
            top = top->next;
            temp->next = Null;
            delete temp; //remove from heap
        }
    }
    void pop(T &stackTop)
    {
        if(isEmpty())
        {
            std::cout<<"stack is empty on pop save";
        }
        else
        {
            stackTop = top->item;
            Node * temp = top;
            top = top->next;
            temp->next = Null;
            delete temp; //remove from heap
        }
    }
    void getTop(T &topItem)
    {
        if(isEmpty())
        {
            std::cout<<"stack is empty on get top";
        }
        else
        {
            topItem = top->item;
            std::cout<<topItem;
        }
    }
    void display()
    {
        current = top;
        std::cout<<"\n Items in stack : ";
        std::cout<<"[ ";
        while (current !=Null)
        {
            std::cout<<current->item;
            current = current->next;
            std::cout<<", ";
        }
        std::cout<<" ]\n";
    }
};

int main()
{
    Stack<int> list;
    list.push(1);
    list.push(2);
    list.push(5);
    list.push(10);
    list.push(20);
    list.push(60);
    list.pop();
    list.display();

    int top = 0;
    std::cout<<"top item is : ";
    list.getTop(top);

    return 0;
}