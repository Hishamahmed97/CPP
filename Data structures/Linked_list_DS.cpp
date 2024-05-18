/*
Linked List data structure
Operations: create(),display(),count(),search(),insert(first,last,before specific item),
delete(first,last,specific item), replace();
*/
#include <iostream>

class Node
{
    public:
    int data;
    Node * next;
};

class Linked_List
{
    public:

    Node * head;
    Linked_List()
    {
        head = NULL;
    }

    bool isempty()
    {
        return (head==NULL);
    }
    void insert_first(int newitem)
    {
        if (isempty())
        {
        Node  * new_Node = new Node;
        new_Node->data = newitem;
        new_Node->next = NULL;
        head = new_Node;
        }
        else
        {
        Node * new_Node = new Node;
        new_Node->data = newitem;
        new_Node->next = head;
        head = new_Node;
        }
    }
    void display()
    {
        Node * temp = head;
        std::cout<<"Displaying list elemnts \n";
        while(temp != NULL)
        {
            std::cout<<temp->data<<"\t";
            temp = temp->next;
        }
        std::cout<<"\n";
    }
    int counter()
    {
        int counter = 0;
        Node * temp = head;
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isfound(int key)
    {
        bool found = true;
        Node * temp = head;
        while(temp != NULL)
        {
            if (temp->data == key)
            {
                found =true;
                break;
            }
            else
            {
                found =false;
                
            }
            temp = temp->next;
        }
        return found;
    }
    void insert_before(int item,int newitem)
    {
        if (isfound(item)==true)
        {
        Node *new_node = new Node;
        new_node->data = newitem;

        Node * temp = head; 
        while (temp->next->data != item && temp!=NULL)
        {
        temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
        }
        else
        {
            std::cout<<"item not found \n";
        }
    
    }
    void append(int newitem) //adding before latest node
    {
        if (isempty())
        {
            insert_first(newitem);
        }
        else
        {
        Node * temp = head;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        Node * newNode = new Node;
        newNode->data = newitem;
        temp->next = newNode;
        newNode->next = NULL;
        }
    }
    int delet(int item)
    {
       int del_value;
       if (isempty())
       {
        std::cout<<"list is empty, no items to delete \n";
       }
        if (head->data == item)
        {
            Node * del_ptr = head;
            head = head->next;
            del_value=del_ptr->data;
            delete del_ptr;
            return del_value;
        }
        else
        {
       Node * del_ptr = head;
       Node * prev = NULL;
       while (del_ptr->data != item)
       {
        prev = del_ptr;
        del_ptr = del_ptr->next;
       }
       prev->next = del_ptr->next;
       del_value = del_ptr->data;
       delete del_ptr;
       return del_value;
       }
    }
};
int main()
{
    Linked_List my_list;
    if (my_list.isempty()==true)
    std::cout<<"list is empty \n";
    else
    std::cout<<"list contains "<<my_list.counter()<<"\n";
    int newitem;
    bool continu =true;
    while (continu == true)
    {
    std::cout<<"enter item to add to list \n";
    std::cin>>newitem;
    my_list.insert_first(newitem);
    std::cout<<"press one to keep adding, zero to stop \n";
    std::cin>>continu;
    }
    my_list.display();
    std::cout<<"no. of elements in list =\t"<<my_list.counter()<<"\n";
    int key;
    std::cout<<"enter key required \n";
    std::cin>>key;
    if (my_list.isfound(key)==true)
    {
        std::cout<<"founded \n";
    }
    else
    {
        std::cout<<"not founded \n";
    }
    int item;
    std::cout<<"enter item to add value before it \n";
    std::cin>>item;
    std::cout<<"enter new value to add \n";
    std::cin>>newitem;
    my_list.insert_before(item,newitem);
    my_list.display();
    std::cout<<"enter new value to append \n";
    std::cin>>newitem;
    my_list.append(newitem);
    my_list.display();
    int new_item;
    std::cout<<"enter value to delete \n";
    std::cin>>new_item;
    my_list.delet(new_item);
    my_list.display();
    return 0;
}