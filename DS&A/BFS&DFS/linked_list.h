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


class list
{
    private:
        node *head, *tail;
    
    public:    
        list()
        {
            head=NULL;
            tail=NULL;
        }
        
        node *getHead()
        {
            return head;
        }
        void add_head(int val)
        {
            node *new_head = new node;
            new_head->data = val;

            new_head->next = head;
            head = new_head;
        }

        void remove_head()
        {
            //Check if list is already empty
            if(head==NULL)
                return;
            
            //Store the previous head
            node *prev = head;
            
            //If the next element is not NULL just increment the head and delete the previous
            if(head->next){
                head = head->next;
                delete prev;  
            }
            //Last element in list so delete it and set head to NULL
            else{
                delete head;
                head = NULL;
            }
           
             
        }

        void add_tail(int val)
        {   
            node *new_tail = new node;
            new_tail->data = val;
            new_tail->next = NULL;
            tail = new_tail;

            //List is empty
            if(!head)
                head = new_tail;
            else{
                node *curr = head;
                while(curr->next)
                    curr = curr->next;
                curr->next = new_tail;
            }
        }
        
        void remove_tail()
        {
            if(!tail || !head)
                return;

            node *curr = head;

            //Last element in the array delete the head and set both tail, head to NULL
            
            if(!curr->next)
            {
                delete curr;
                head = NULL;
                tail = NULL;
            }
            else{
                //Traverse until the last element, while keeping track of previous
                //Set the next of previous to NULL and delete the last element
                node *prev = NULL;
                while(curr->next)
                {
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = NULL;
                tail = prev;

                delete curr;
                curr = NULL;
            }
        }

        void reverse()
        {
            // Initialize current, previous and next pointers
            node* current = head;
            node *prev = NULL, *next = NULL;

            while (current != NULL) {
                // Store next
                next = current->next;
                // Reverse current node's pointer
                current->next = prev;
                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            head = prev;
        }

        bool is_empty()
        {
            return head==NULL;
        }
        
        void print()
        {
            node *curr = head;
            if(curr==NULL)
                return;
            while(curr)
            {
                cout << curr->data << " "; 
                curr = curr->next;
            }
        }


};	

