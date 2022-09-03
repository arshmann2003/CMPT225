
template <class T> 
class stack_node{
    public:
        stack_node<T> *next;
        T data;
};

template <class T> 
class Stack
{
    private:
        stack_node<T> *head;
        T size;
    public:
        Stack();
        ~Stack();
        T pop();
        void push(T x); 
        T peek();
        bool isEmpty();
};



template <class T>
Stack<T>::Stack(): head(NULL), size(0){}


template <class T>
Stack<T>::~Stack()
{
    stack_node<T> *curr = head;
    stack_node<T> *prev = nullptr;

    while(curr)
    {   
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}


template <class T>
void Stack<T>::push(T x)
{
    stack_node<T> *new_stack_node = new stack_node<T>;
    new_stack_node->next = head;
    new_stack_node->data = x;
    head = new_stack_node;
    size++;
}


template <class T>
T Stack<T>::pop()
{
    if(head)
    {
        T val = head->data;
        stack_node<T> *prev_head = head;
        head = head->next;
        size--;
        delete prev_head;
        return val;
    }
    throw std::logic_error("EMPTY LIST");
}


template <class T>
T Stack<T>::peek()
{
    if(head)
        return head->data;
    throw std::logic_error("EMPTY LIST");
}


template <class T>
bool Stack<T>::isEmpty()
{
    return size==0;
}

