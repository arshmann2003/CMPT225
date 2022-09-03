#include <iostream>
using namespace std;
#include "Queues.hpp"

//Queue with a linked list
queue_LL::queue_LL(): tail(NULL), head(NULL), size(0){}

queue_LL::~queue_LL()
{
    node *curr = head;
    node *prev = NULL;

    while(curr!=NULL)
    {
        prev = curr;
        curr=curr->next;
        delete prev;
    }
    size=0;
}

void queue_LL::enqueue(int x)
{
    //add to the tail of the list
    node *new_node = new node;
    new_node->data = x;
    new_node->next = NULL;

    if(tail)
    {
        tail->next = new_node;    
        tail = new_node;   
    }
    else   
    {
        tail = new_node;
        head = new_node;
    }
    size++;
}

int queue_LL::dequeue()
{
    if(head)
    {
        //Remove the head of the list
        node *prev_head = head;
        int data = prev_head->data;
        head = head->next;
        delete prev_head;
        size--;
        return data;
    }
    throw logic_error("EMPTY LIST");
}

bool queue_LL::isEmpty()
{
    return size==0;
}

int queue_LL::peek()
{
    return head->data;
}

void queue_LL::printQueue()
{
    node *curr = head;
    while(curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}


//Queue with a dynamic array
dynamic_queue::dynamic_queue()
{
    arr = new int[10];
    size = 10;
    elements = 0;
}

void dynamic_queue::enqueue(int x)
{
    if(elements-1>=size)
    {
        //new arr required
        static const unsigned CAP = size*2;
        int *new_arr = new int[CAP];

        for(int i=0; i<elements; i++)
        {
            new_arr[i+1] = arr[i];
        }
        new_arr[0] = x;
        delete arr;
        
        arr = new_arr;
        size = size*2;
    }   
    else
    {
        //shift all elements to the right
        for(int i=elements-1; i>0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = x;
    }
    elements++;
}

int dynamic_queue::dequeue()
{
    if(elements>0)
    {
        int data = arr[elements-1];
        elements--;
        return data;
    }
    throw logic_error("ERROR");
}

void dynamic_queue::printQueue()
{
    for(int i=0; i<elements; i++)
    {
        cout << arr[i] << " ";
    }
}

int dynamic_queue::peek()
{
    if(elements>0)
        return arr[elements-1];
    else
        throw logic_error("EMPTY QUEUE");
}   

bool dynamic_queue::isEmpty()
{
    return elements==0;
}

int main()
{
    dynamic_queue queue;
    
    for(int i=0; i<=50; i++)
        queue.enqueue(i);

    queue.printQueue();

    
    return 0;
}   




