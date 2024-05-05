/*
Array as a data structure
Operations: create(),fill(),display(),append(new item),insert(index,new item),search(key),delete(index),
enlarge(new size), merge(other array), getsize(),getlength()
*/
#include<iostream>

class array
{
private:
    int arraySize;
    int arrayLength;
    int * items;
public:
    array(int size) //constructor to create new empty array
    {
        arraySize = size;
        arrayLength = 0;
        items = new int [size];
    };
    void fill()
    {
        std::cout<<"how many items to fill ? \n";
        int no_of_items;
        std::cin>>no_of_items;
        if (no_of_items>arraySize)
        {
            std::cout<<"cannot exceed array size \n";
            return;
        }
        else 
        {
            for (int i = 0;i<no_of_items;i++) //try start i from length of array
            {
                std::cout<<"enter item no. "<<i<<"\n";
                std::cin>>items[i];
                arrayLength++;
            }
        }
    }
    void display()
    {
        std::cout<<"Array elemts are : \n";
        for (int i = 0;i<arrayLength;i++)
        {
            std::cout<<items[i]<<"\t";
        }
        std::cout<<std::endl;
    }
    int getSize()
    {
        return arraySize;
    }
    int getLength()
    {
        return arrayLength;
    }
    int search(int key)
    {   
        int index = -1;
        for (int i=0;i<arrayLength;i++)
        {
            if (items[i]==key)
            {
                index = i;
                break;
            }
        }
        return index;
    }
    void append(int newitem) // add item at the end
    {
        if (arrayLength<arraySize)
        {
            items[arrayLength] = newitem;
            arrayLength++;
        }
        else
        {
            std::cout<<"array is full to add items \n";
        }
    }
    void insert(int index,int newitem)
    {
        if (index<arraySize && index>=0)
        {
        for (int i=arrayLength;i>index;i--) //shift values to the right by one place
        {
            items[i]=items[i-1];
        }
        items[index] = newitem;
        arrayLength++;
        }
        else
        {
            std::cout<<"invalid index \n";
        }
    }
    void delet(int index)
    {
        if (index<arraySize && index>=0)
        {
        for (int i=index;i<arrayLength-1;i++) //shift values to the left by one place
        {
            items[i]=items[i+1];
        }
        arrayLength--;
        }
        else
        {
            std::cout<<"invalid index \n";
        }
    }
    void enlarge(int newsize)
    {
        if (newsize <=arraySize)
        {
            std::cout<<"new size must be larger than current size \n";
            return;
        }
        else
        {
        arraySize=newsize;
        int *old = items; // point to old array
        items = new int[newsize]; // create new array where items points to it
        for (int i=0;i<arrayLength;i++)
        {
            items[i]=old[i];
        }
        delete[] old;
        }
        
    }
    void merge(array otherarray)
    {
        int newsize = arraySize+otherarray.getSize();
        arraySize = newsize;
        int * old = items;
        items = new int [newsize];
        int i = 0;
        for (i=0;i<arrayLength;i++)
        {
            items[i]=old[i];
        }
        delete[] old;
        int j = i;
        for (int i=0;i<otherarray.getLength();i++)
        {
            items[j++]=otherarray.items[i];
            arrayLength++;
        }
    }
};

int main()
{
    std::cout<<"Array data structure demo \n";
    int arraySize;
    std::cout<<"enter array size \n";
    std::cin>>arraySize;
    array myarray(arraySize);
    myarray.fill();
    myarray.display();
    std::cout<<"Array size is "<<myarray.getSize()<<" while array length is "<<myarray.getLength()<<"\n";
    int key;
    std::cout<<"enter key \n";
    std::cin>>key;
    int index = myarray.search(key);
    if (index == -1)
    {
        std::cout<<"item not found \n";
    }
    else
    {
    std::cout<<"value of "<<key<<" found at index "<<index<<"\n";
    }
    int newitem;
    std::cout<<"Enter new item to add to the array \n";
    std::cin>>newitem;
    myarray.append(newitem);
    myarray.display();
    std::cout<<"enter index and new item \n";
    std::cin>>index;
    std::cin>>newitem;
    myarray.insert(index,newitem);
    myarray.display();
    std::cout<<"Array size is "<<myarray.getSize()<<" while array length is "<<myarray.getLength()<<"\n";
    std::cout<<"enter index for delete \n";
    std::cin>>index;
    myarray.delet(index);
    myarray.display();
    std::cout<<"Array size is "<<myarray.getSize()<<" while array length is "<<myarray.getLength()<<"\n";
    std::cout<<"enter new size to enlarge \n";
    int newsize;
    std::cin>>newsize;
    myarray.enlarge(newsize);
    myarray.display();
    std::cout<<"Array size is "<<myarray.getSize()<<" while array length is "<<myarray.getLength()<<"\n";
    array otherarray(3);
    otherarray.fill();
    myarray.merge(otherarray);
    myarray.display();
    std::cout<<"Array size is "<<myarray.getSize()<<" while array length is "<<myarray.getLength()<<"\n";

}
    