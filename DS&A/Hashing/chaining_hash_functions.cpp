#include <iostream>


class node{
public:
    int data;
    node *next;
};


class hash{
    private:
        node **A;
        int elements;
        int array_size;
    public:
        void insert(int val);
        bool search(int val);
        int remove(int val);
        int function(int key);
        void print();
        hash(const int n);
        ~hash();
};


hash::hash(const int n)
{
    A = new node *[n];
    elements = 0;
    array_size = n;
}

hash::~hash()
{
    for(int i=0; i<array_size; i++)
    {
        node *curr = A[i];
        node *next;

        while(curr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }
}

int hash::function(int key)
{
    return key%10;
}

void hash::print()
{
    for(int i=0; i<array_size; i++)
    {
        if(A[i])
        {
            std::cout << "INDEX " << i << ": ";
            node *curr = A[i];
            while(curr)
            {
                std::cout << curr->data << " "; 
                curr = curr->next;
            }
            std::cout << "\n";
        }

    }
}

void hash::insert(int key)
{
    // find associated linked list
    node *arr = A[function(key)];
    
    // create new node
    node *newNode = new node;
    newNode->next = NULL;
    newNode->data = key;

    // empty linked list associated wih hash value
    // add the new node as the head
    if(arr == NULL)
    {
        newNode->next = NULL;
        A[function(key)] = newNode;
        return;
    }
 
 
    // keep traversing while key is bigger then curr->data
    node *curr = arr;
    node *prev = NULL;
    while(curr && key > curr->data)
    {
        prev = curr;
        curr = curr->next;
    }

    // insertion to the tail
    if(curr == NULL)
    {
        prev->next = newNode;
        return;
    }
    
    //insertion to the head
    if(prev==NULL)
    {
        newNode->next = curr;
        A[function(key)] = newNode;
        return;
    }

    // curr is not NULL so insertion to middle
    prev->next = newNode;
    newNode->next = curr;    
}


int hash::remove(int key)
{
    node *curr =  A[function(key)];

    if(curr->data == key){
        A[function(key)] = curr->next;
        int val = curr->data;
        delete curr;
        curr = NULL;
        return val;
    }

    if(curr==NULL)
        throw std::logic_error("POS IS OUT OF RANGE");
    
    node *prev = NULL;
    while(curr && key != curr->data)
    {
        prev = curr;
        curr = curr->next;
    }

    // curr->data should be equal to the function parameter
    if(curr && curr->data == key)
    {
        node *next_node = curr->next;
        prev->next = next_node;
        delete curr;
    }

    return -1;

}



int main()
{
    hash test(10);
    test.insert(21);
    test.insert(1);
    test.insert(25);
    test.insert(35);
    test.insert(45);

        test.remove(21);
    test.remove(1);
    test.remove(25);
    test.remove(35);
    test.remove(45);

    // for(int i=0; i<10; i++)
    // {
    //     test.insert(i);
    // }
    // std::cout << test.A[5]->data << "\n";
    // std::cout << test.A[1]->data;

    test.print();
    return 0;

}