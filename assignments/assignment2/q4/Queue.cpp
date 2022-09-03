#include "Queue.h"
#include <iostream>
using namespace std;
// Desc:  Constructor
Queue::Queue() : size(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
    arr = new int[capacity];
} // constructor


// Desc:  Destructor
Queue::~Queue() {
    delete []arr;
} // destructor

Queue::Queue(const Queue &other) {
    if (this != &other) 
    {
        this->arr = new int[other.capacity];
        size = other.size;
        capacity = other.capacity;
        frontindex = other.frontindex;
        backindex = other.backindex;

        for (unsigned i = 0; i < capacity; i++) 
        {
            arr[i] = other.arr[i];
        }
    }    
}// Desc:  Copy Constructor


// Desc:  Assignment operator
Queue & Queue::operator=(const Queue &rhs) {

    if (this != &rhs) {
        size = rhs.size;

        if(size<=capacity)
        {
            frontindex = rhs.frontindex;
            backindex = rhs.backindex;
    
            for(int i=0; i<capacity; i++)
            {
                arr[i] = rhs.arr[i];
            }
        }
        else if (size>capacity)
        {
            capacity = rhs.capacity;
            frontindex = rhs.frontindex;
            backindex = rhs.backindex;

            int *new_arr = new int[capacity];
            for(int i=0; i<capacity; i++)
            {
                new_arr[i] = rhs.arr[i];
            }
            delete []arr;
            arr = new_arr;
        }
    }
    return *this;
} // lhs = rhs


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {

    //Queue is full
    if(size==capacity)
    {   
        int *new_arr = new int[capacity*2];
        
        int j=0;
        for(int i=frontindex; i<capacity; i++)
        {
            new_arr[j] = arr[i];
            j++;
        }
        if(frontindex!=0)
        {
            for(int i=0; i<backindex; i++)
            {
                new_arr[j] = arr[i];
                j++;
            }
        }
        frontindex = 0;
        new_arr[capacity] = x;
        backindex = capacity+1;
        capacity = capacity*2;
       
        delete []arr;
        arr = new_arr;
        size++;
    }
    else
    {
        arr[backindex] = x;
        backindex = (backindex+1)%capacity;
        size++;
    }
    
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    if(size==0)
        throw std::logic_error("Queue is empty");

    arr[frontindex] = -1;
    size--;
    frontindex = (frontindex + 1) % capacity;

    if(((size*1.0/capacity*1.0)<=1.0/4.0 && (capacity/2)>=6))
    {          
        int *new_arr = new int[capacity/2];    
       
        int j=0;
        if(backindex<frontindex)
        {
            for(int i=frontindex; i<capacity; i++)
            {
                new_arr[j] = arr[i];
                j++;         
            }
        
            for(int i=0; i<=backindex; i++)
            {
                new_arr[j] = arr[i];
                j++;
            }
        }
        else
        {
            for(int i=frontindex; i<capacity; i++)
            {
                new_arr[j] = arr[i];
                j++;
            }
        }
        frontindex = 0;
        backindex = size;
        capacity = capacity/2;
        delete []arr;
        arr = new_arr;
    }
}

       
// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    if(size>0)
        return arr[frontindex];
    else
        throw logic_error("QUEUE IS EMPTY");
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return size == 0;
} // isempty



