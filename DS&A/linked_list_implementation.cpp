#include <iostream>
using namespace std;
#include "linked_list.h"

list::list(){
    head = NULL;
    tail = NULL;
}

void list::add_head(int x)
{
    //Create the new_head and set the data of to be be x
    node *new_head = new node;
    new_head->data=x;
    
    //The node after the new head should be the old head
    new_head->next=head;

    //Change the new head the list to be the new node
    head = new_head;
}

void list::remove_head()
{
    //0 elements in list
    if(!head)
        return;

    //More then one element in list
    node *prev_head = head;
    if(head->next)
    {
        head = head->next;
        delete prev_head;
    }
    //1 element in list
    else if(!head->next)
    {
        delete head;
        head = NULL;
    }
}

void list::add_tail(int x)
{
    node *new_tail = new node;
    new_tail->data = x;
    new_tail->next = NULL;

    //No elements
    if(head==NULL || tail==NULL)
    {
        head = new_tail;
        tail = new_tail;
    }
    else{
        //Traverse until curr is the last node in the list 
        //
        node *curr = head;
        while(curr->next)
            curr = curr->next;
        
        curr->next = new_tail;
    }
}

void list::remove_tail()
{
    //List is empty
    if(head==NULL)
        return;

    //1 element
    else if(head->next==NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    } 

    //1> elements in list
    else{
        node *curr = head;
        node *prev = NULL;
        while(curr->next)
        {   
            prev = curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete curr;
        tail = prev;
    }    
}

void list::print()
{
    if(head == NULL)
    {
        return;
    }

    node *curr = head;
    while(curr)
    {
        cout << curr->data << " ";
        curr=curr->next;
    }
}

void list::filter(bool(*func)(int))
{   
    //Empty list
    if(head==NULL)
        return;


    node *curr = head;
    node *prev = NULL;
    node *filtered;
    while(curr)
    {
        if(func(curr->data) && curr==head)
            remove_head();
            
        if(func(curr->data) && curr->next){
            prev->next = curr->next;
            delete curr;
            curr = prev;
        }
        else if(func(curr->data) && !curr->next)
            remove_tail();

        prev = curr;
        curr=curr->next;
    }
}

// int LL_filter(LL_t* list, bool (*pred)(int)) { 
//     if (list==NULL)
//         return 0;
//     int count = 0;
//     node_t* current = list->head;
//     node_t* previous = NULL;
//     while (current!=NULL) {
//         if (!pred(current->data)) { // need to remove the node
//             count++;
//             if (current==list->head) {  // handle the case of cur is the head of the list
//                 LL_remove_from_head(list);
//                 current = list->head;
//             }
//             else {
//                 previous->next = current->next;
//                 LLnode_free(current);
//                 current = previous->next;
//             }
//         }
//         else { 
//             previous = current;
//             current = current->next;
//         }
//     }
//     return count;
// }

bool even(int x){return x%2==0;}

int main()
{
    list LL;
    
    for(int i=1; i<11; i++)
    {
        LL.add_tail(i);
    }
    
    LL.print();
}
