#include "Stack_dynamic_arr.hpp"
#include <iostream>
using namespace std;

//Dynamic array implementation
Stack_dynamic_arr::Stack_dynamic_arr()
{
    arr = new int[10];
    elements = 0;
    size = 10;
}

void Stack_dynamic_arr::push(int x)
{
    if(elements>=size)
    {
        static const unsigned STACKCAP = size*2;
        size = STACKCAP;
        int *new_arr = new int[STACKCAP];

        for(int i=0; i<elements; i++)
        {
            new_arr[i+1] = arr[i];
        }
        new_arr[0] = x;
        elements++;
        delete arr;
        arr = new_arr;
    }   
    else
    {
        for(int i=size-1; i>0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = x;
    }
    elements++;
}

int Stack_dynamic_arr::pop()
{
    //Shift elements to the left and return the data of peek
    int data = arr[0];
    for(int i=0; i<elements-1; i++)
    {
        arr[i] = arr[i+1];
    }
    elements--;
    return data;
}   

void Stack_dynamic_arr::printStack()
{
    for(int i=0; i<elements; i++)
        cout << arr[i] << " ";
}

int Stack_dynamic_arr::peek()
{
    return arr[0];
}

bool Stack_dynamic_arr::isEmpty()
{
    return elements==0;
}


