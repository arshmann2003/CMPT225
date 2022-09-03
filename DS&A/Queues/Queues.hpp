
class node
{
    public:
        node *next;
        int data;
};

//Tail is the back of the queue and head is front
//because deletion at the front of the array is O(1)
//while deletion at the back is O(N)
//So add to the back and remove from front
class queue_LL
{
    private:
        node *head;
        node *tail;
        int size;
    public:
        queue_LL();
        ~queue_LL();
        void enqueue(int x);
        int dequeue();
        bool isEmpty();
        void printQueue();
        int peek();
};

class dynamic_queue
{
    private:
        int *arr;
        int size;
        int elements;
    public:
        dynamic_queue();
        void enqueue(int x);
        int dequeue();
        bool isEmpty();
        void printQueue();
        int peek();        

};