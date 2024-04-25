#include <iostream>
#include <array>

void insertion_sort(int arr[],int siz);
void printarray(int arr[],int size);



int main()
{
    int array[] = {10,5,3,8,30,4,5,2,30,9};
    int size = sizeof(array)/sizeof(int);
    std::cout<<"array before sort : \n";
    printarray(array,size);    
    insertion_sort(array,size);
    std::cout<<"array after sort : \n";
    printarray(array,size);    
    return 0;
}

void insertion_sort(int arr[],int siz)
{
    int key = 0;
    int j   = 0;
    int i   = 0;
    for (i=1; i<siz;i++)
    {
        key = arr[i];
        j = i -1;
        while (j>=0 && arr[j]> key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printarray(int arr[],int size)
{
    for (int i = 0;i<size;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
