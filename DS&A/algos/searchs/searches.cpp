#include "seaches.hpp"
#include <iostream>
#include <time.h>

template <class T>
Search<T>::Search(): size(10)
{
    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        arr.push_back(rand() % 201 + (-100));
    }
}

template <class T>
void Search<T>::print()
{
    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
T Search<T>::get(unsigned pos)
{
    if(pos<size)
        return arr[pos];
    throw std::logic_error("POS value is invalid");
}

template <class T>
int Search<T>::linearSearch(T object)
const{
    for(int i=0; i<size; i++)
    {
        if(object == arr[i])
            return i;
    }
    return -1;
}

template <class T>
void Search<T>::selectionSort()
{
    int min_index;
    for(int i=0; i<size; i++)
    {
        min_index = i;
        for(int i=min_index+1; i<size; i++)
        {
            if(arr[i] < arr[min_index])
                min_index = i;
        }
        T temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

template <class T>
int Search<T>::binarySearch1(T x)
const{   
    int low = 0;
    int high = arr.size()-1;
    int mid;
    while(low<high)
    {
        mid = (low+high)/2;
        if(x == arr[mid])
            return mid;
        else if(x > arr[mid])
            low = mid+1;
        else if(x < arr[mid])
            high = mid-1;
    }
    return -1;    
}

template <class T>
int Search<T>::getSize()
{
    return arr.size();
}

template <class T>
int Search<T>::recurssive_binarySearch(T x, int low, int high)
const{
    std::cout << "\nlow=" << low << "\n";
    std::cout << "mid=" << (low+high)/2 << "\n";
    std::cout << "high=" << high << "\n";
    std::cout << "SUB ARRAY: ";
    for(int i=low; i<=high; i++)
    {
        std::cout<< arr[i] << " ";
    }
    std::cout << "\n"; 
    
    if(low>high)   
        return -1;
    

    int mid = (low+high)/2;

    if(arr[mid]==x)    
        return mid;
    else if(x < arr[mid])
        return recurssive_binarySearch(x, low, mid-1);    
    else
        return recurssive_binarySearch(x, mid+1, high);
    
}


int main()
{
    Search<int> list;
    list.selectionSort();
    list.print();

    int val;
    std::cout << "Enter a value to search for ";
    std::cin >> val;
    int x = list.binarySearch1(val);

    if(x!=-1)
        std::cout << val << " was found at index " << x;
    else
        std::cout << val << " was not found in array";
    return 0;
}

