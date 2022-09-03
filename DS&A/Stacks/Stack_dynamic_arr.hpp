class Stack_dynamic_arr
{
    private:
        int *arr;
        int size;
        int elements;
    
    public:
        Stack_dynamic_arr();
        int pop();
        void push(int x);
        int peek();
        bool isEmpty();
        void printStack();
};