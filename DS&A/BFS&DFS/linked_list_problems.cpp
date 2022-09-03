#include <iostream>

using namespace std;

class node
{
    public:
        int data;
        node *next;
        node(int data):data(data), next(NULL){};
        node():next(NULL), data(-1){};
};	

class list{
    public:
        node *head;
    list():head(NULL){};
};


void print(list &list)
{
    node *curr = list.head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}


void insert_sorted_list(int val, list &list)
{
    node *newNode = new node(val);
    
    node *curr = list.head;
    node *prev = NULL;

    if(curr==NULL)
    {
        list.head = newNode;
        return;
    }
 
    // traverse until larger value is found or curr == NULL
    while (curr && curr->data < val)
    {
        prev = curr;
        curr = curr->next;
    }

    if(prev)
        prev->next = newNode;
    else if(prev==NULL)
        list.head = newNode;
    newNode->next = curr;
}


int deleteNode(list &list, int x)  
{
    node *curr = list.head;
    node *prev = NULL;

    // delete from head
    if(curr->data == x)
    {
        node *to_delete = curr;
        list.head = curr->next;
        delete to_delete;
        return 1;
    }

    // delete from middle - end
    while(curr && curr->data!=x)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr)
    {
        node *to_del = curr;
        prev->next = curr->next;
        delete to_del;
        return 1;
    }   
    else
        return -1;

}

bool list_sorted(list &list)
{
    node *curr = list.head;

    if(curr==NULL)
        return true;

    node *prev = NULL;
    while(curr)
    {
        if(prev)
        {
            if(curr->data < prev->data)
                return false;
        }
        prev = curr;
        curr = curr->next;
    }
    return true;
}

void remove_duplicates_sorted(list &list)
{
    node *curr = list.head;
    if(curr==NULL)
        return;
    
    node *prev = NULL;
    while(curr)
    {
        bool iterate = true;
        if(prev)
        {
            if(prev->data == curr->data)
            {
                node *to_dele = curr;
                prev->next = curr->next;
                curr = curr->next;
                iterate = false;
                delete to_dele;
            }
        }
        if(iterate)
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void reverse(list &list1)
{
    node *curr = list1.head;
    node *next = NULL;
    node *prev = NULL;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list1.head = prev;
}

void concatenate(list &list1, list &list2)
{
    node *curr1 = list1.head;
    node *curr2 = list2.head;
    if(!(curr1||curr2))
        return;

    while(curr1->next)
        curr1 = curr1->next;

    while(curr2)
    {
        curr1->next = curr2;
        curr2 = curr2->next;
        curr1 = curr1->next;
    }
}

node * merge(list &list1, list &list2)
{

    node *curr1 = list1.head;
    node *curr2 = list2.head;


    if(curr1==NULL)
        return curr2;
    else if(curr2==NULL)
        return curr1;        


    node *head_final = NULL;
    node *x = head_final;

    if(curr1->data < curr2->data){
        head_final = curr1;
        curr1 = curr1->next;
    }else{
        head_final = curr2;
        curr2 = curr2->next;
    }
    x = head_final;
    while(curr1 && curr2)
    {
        if(curr1->data < curr2->data){
            x->next = curr1;
            curr1 = curr1->next;
        }else{
            x->next = curr2;
            curr2 = curr2->next;
        }
        x = x->next;
    }

    while(curr1)
    {
        x->next = curr1;
        x = x->next;
        curr1 = curr1->next;
    }
    while(curr2)
    {
        x->next = curr2;
        x = x->next;
        curr2 = curr2->next;
    }

    return head_final;
}

int main()
{
    list list1;
    list list2;
    
    insert_sorted_list(1000, list2);
    insert_sorted_list(933, list2);
    insert_sorted_list(5, list1);
    insert_sorted_list(5, list1);
    insert_sorted_list(4, list1);
    insert_sorted_list(4, list1);
    insert_sorted_list(3, list1);
    insert_sorted_list(3, list1);
    insert_sorted_list(2, list1);
    insert_sorted_list(2, list1);
    insert_sorted_list(1, list1);
    insert_sorted_list(1, list1);
    if(list_sorted(list1))
        cout << "LIST IS SORTED\n";
    remove_duplicates_sorted(list1);
    node *head = merge(list1, list2);
    
    node *curr = head;
    while(curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    // insert_sorted_list(1, list1);

    return 0;
}

