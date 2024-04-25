#include <iostream>
#include <array>

void swap(int * one,int * two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}

void selection_sort(int arr[],int size)
{
    int i, j, min_index;
    for (i=0;i<size-1;i++)
    {
        min_index = i;
        for (j=i+1;j<size;j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index],&arr[i]);
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
    selection_sort(arr,size);
    printarray(arr,size);
    return 0;
}
