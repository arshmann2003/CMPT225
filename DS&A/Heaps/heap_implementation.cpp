#include <iostream>
using namespace std;

class Pqueue{
    private:
        int *arr;
        int elements;
        int n;
    public:
        Pqueue(int n): arr(new int[n]), n(n), elements(0){};
        Pqueue(Pqueue &other); 
        Pqueue &operator=(const Pqueue &other);
        ~Pqueue(){delete arr;};
        void enqueue(int val);
        int dequeue();
        void print();
        int peek();
};


void Pqueue::enqueue(int val)
{
    arr[elements++] = val;
    int i=elements-1;
    int temp = arr[i];

    while(i > 0 && temp > arr[(i-1)/2])
    {
        arr[i] = arr[(i-1)/2];
        i=(i-1)/2;
    }
    arr[i] = temp;
}

int Pqueue::dequeue()
{
    int x = arr[0];
    arr[0] = arr[elements-1];

    int i=0;
    int j = 2*i+1;
    // bubble down
    while(j < elements-1)
    {
        if(arr[j] < arr[j+1])
            j++;
        if(arr[i] < arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
            j = 2*i+1;
        }
    }
    arr[elements-1] = x;
    elements--;
    return x;
}

void Pqueue::print()
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    
}

int main()
{
    Pqueue queue(5);
    queue.enqueue(1);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(3);
    queue.enqueue(2);

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.print();  
    return 0;
}




