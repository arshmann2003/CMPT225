
#include "Stack.h"
#include <stdexcept>
using namespace std;
#include <iostream>

Stack::Stack():size(0){}

void Stack::push(int x)
{
    if(size<8)
    {
        size++; 
        for(int i=size-1; i>0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = x;    
    }
    else
        throw std::logic_error("pop an element, stack is full");
}

int Stack::pop()
{
    if(size>0)
    {
        int popped_element = arr[0];

        for(int i=0; i<size; i++)
        {
            arr[i] = arr[i+1];
        }
        size--;
        return popped_element;
    }
    throw logic_error("EMPTY STACK");
}


int Stack::peek()
const{
    if(size>0)
        return arr[0];
    
    throw logic_error("EMPTY STACK");
}

bool Stack::isEmpty()
const{
    return size==0;
}







    

    

    

    





