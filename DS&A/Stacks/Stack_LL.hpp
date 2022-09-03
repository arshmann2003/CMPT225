

template <class T> 
class node{
    public:
        node<T> *next;
        T data;
};


template <class T> 
class Stack_LL
{
    private:
        node<T> *head;
        T size;
    public:
        Stack_LL();
        ~Stack_LL();
        T pop();
        void push(T x); 
        T peek();
        bool isEmpty();
        void printStack();
};

template <class T>
Stack_LL<T>::Stack_LL(): head(NULL), size(0){}


template <class T>
Stack_LL<T>::~Stack_LL()
{
    node<T> *curr = head;
    node<T> *prev = nullptr;

    while(curr)
    {   
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}


template <class T>
void Stack_LL<T>::push(T x)
{
    node<T> *new_node = new node<T>;
    new_node->next = head;
    new_node->data = x;
    head = new_node;
    size++;
}


template <class T>
T Stack_LL<T>::pop()
{
    if(head)
    {
        int val = head->data;
        node<T> *prev_head = head;
        head = head->next;
        size--;
        delete prev_head;
        return val;
    }
    throw std::logic_error("EMPTY LIST");
}


template <class T>
T Stack_LL<T>::peek()
{
    if(head)
        return head->data;
    throw std::logic_error("EMPTY LIST");
}


template <class T>
bool Stack_LL<T>::isEmpty()
{
    return size==0;
}


template <class T>
void Stack_LL<T>::printStack()
{
    if(!head)
        return;
    node<T> *curr = head;
    while(curr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}