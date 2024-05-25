#include <iostream>
#include <array>

void swap(int * one,int * two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}

void bubble_sort(int arr[],int size)
{
    for (int i= 0;i<size-1;i++)
    {
        for (int j = 0;j < size-i-1;j++)
        {
            //compare adjacent elements
            if (arr[j]>arr[j+1])
            {

            }
        }
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

int main()
{
    int arr[] = {10,5,3,8,30,4,5,2,30,9};
    int size = sizeof(arr)/sizeof(int);
    bubble_sort(arr,size);
    printarray(arr,size);
    return 0;
}
