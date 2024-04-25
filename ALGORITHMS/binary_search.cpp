#include <iostream>
#include <array>

int binarysearch(int arr[],int left,int right, int key) //normal binary
{
    int middle = (left+right)/2;
    while (left <=right)
    {
        if (arr[middle]==key)
        {
            return middle;
        }
        if (key < arr[middle])
        {
            right = middle - 1;
            middle = (left+right)/2;
        }
        else
        {
            left = middle + 1;
            middle = (left+right)/2;
        }
        
    }
    return -1;

}

int binarysearch_recur(int arr[],int left,int right, int key) //recursive binary
{
    int middle = (left+right)/2;
    while (left <=right)
    {
        if (arr[middle]==key)
        {
            return middle;
        }
        if (key < arr[middle])
        {
            return binarysearch_recur(arr,left,middle-1,key);
        }
        else
        {
            return binarysearch_recur(arr,middle+1,left,key);
        }   
    }
    return -1; 

}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,20,30,40};
    int size = sizeof(arr)/sizeof(int);
    int left = 0;
    int right = size-1;
    int key;
    std::cout<<"enter key :"<<"\n";
    std::cin>>key;
    int result = binarysearch(arr,left,right,key);

    if (result == -1)
    {
        std::cout<<"key not found "<<"\n";
    }
    else
    {
        std::cout<<"key "<<arr[result]<<" found at index "<<result; //see record
        //see also for recursion method
    }
    return 0;
}