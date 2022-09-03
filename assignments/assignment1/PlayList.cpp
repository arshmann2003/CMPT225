// Author: Arshdeep Mann #301461759
// Date: May 2022

#include "PlayList.h"
#include <iostream>
using namespace std;

// PlayList method implementations go here

PlayList::PlayList(): head(nullptr), num_songs(0) {}

PlayList::PlayList(const PlayList& pl)
{
    if(pl.head)
    {
        //Copy head of list of pl
        head = new PlayListNode(pl.head->song);
        PlayListNode *this_curr = head;
        PlayListNode *curr_pl = pl.head->next;
        num_songs = pl.size();

        //Copy rest of the list of pl
        //this_curr is only moved to the next node after a new node is created in set position
        while(curr_pl)
        {
            this_curr->next = new PlayListNode(curr_pl->song);
            this_curr = this_curr->next;
            curr_pl = curr_pl->next;
        }
        //this_curr acts as a prev pointer as it is always one node behind of curr_pl
        this_curr->next = nullptr;
    }
}

PlayList::~PlayList()
{
    if(head){
        PlayListNode *curr = head;
        PlayListNode *prev = nullptr;

        while(curr)
        {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }
}

PlayList& PlayList::operator=(const PlayList & pl)
{   
    if(pl.head)
    {
        //Copy head of list of pl
        head = new PlayListNode(pl.head->song);
        PlayListNode *this_curr = head;
        PlayListNode *curr_pl = pl.head->next;
        num_songs = pl.size();
        //Copy rest of the list of pl
        //this_curr is only moved to the next node after a new node is created in set position
        while(curr_pl)
        {
            this_curr->next = new PlayListNode(curr_pl->song);
            this_curr = this_curr->next;
            curr_pl = curr_pl->next;
        }
        //this_curr acts as a prev pointer as it is always one node behind of curr_pl
        this_curr->next = nullptr;
    }
    return *this;
}

void PlayList::insert(Song sng, unsigned int pos)
{   
    //add to head of list if index position is 0, also takes care of the case where
    //list is empty because a new head is created with the next node being nullptr
    if(pos==0)
        head = new PlayListNode(sng, head);

    else if(pos >= 1)
    {
        PlayListNode *curr = head;
        PlayListNode *prev = nullptr;
        int i=0;
        while(curr && i!=pos)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if(i==pos)
        {
            PlayListNode *newNode = new PlayListNode(sng, curr);
            prev->next = newNode;
        }
    }
    num_songs++;
}

Song PlayList::remove(unsigned int pos)
{
    if(head)
    {
        num_songs--;
        if(pos==0)
        {
            PlayListNode *old_head = head;
            head = head->next;
            return old_head->song;   
        }
        PlayListNode *removed_node;
        PlayListNode *curr = head;
        PlayListNode *prev = nullptr;

        while(curr && pos)
        {  
            prev = curr;
            curr = curr->next;
            pos--;
        }

        removed_node = curr;
        if(prev && curr)
        {
            prev->next = curr->next;
            return removed_node->song;
        }  
        throw out_of_range("pos value is out of the scope");
    }
    throw out_of_range("List is empty");
}

void PlayList::swap(unsigned int pos_1, unsigned int pos_2)
{
    // positions are the same nothing to swap
    if (pos_1 == pos_2)
        return;
    
    // Find the node in the position pos_1 of the list, keep track of its prev
    int i=0;
    PlayListNode *prev_pos1 = nullptr;
    PlayListNode *curr_pos1 = head;
    while (curr_pos1 && i!=pos_1) {
        prev_pos1 = curr_pos1;
        curr_pos1 = curr_pos1->next;
        i++;
    }
    // Find the node in the position pos_2 of the list, keep track of its prev
    int j=0;
    PlayListNode *prev_pos2 = nullptr;
    PlayListNode *curr_pos2 = head;
    while (curr_pos2 && j!=pos_2) {
        prev_pos2 = curr_pos2;
        curr_pos2 = curr_pos2->next;
        j++;
    }
    if (curr_pos1 && curr_pos2)
    {
        //case where prev pointer is NULL, which then means function 
        //is swapping with a node in the head position of the list
        if (prev_pos1){
            prev_pos1->next = curr_pos2;
        }else{
            head = curr_pos2;
        }
        if (prev_pos2){
            prev_pos2->next = curr_pos1;
        }else{ 
            head = curr_pos1;
        }
        PlayListNode *temp = curr_pos1->next;
        curr_pos1->next = curr_pos2->next;
        curr_pos2->next = temp;
    }
}   

Song PlayList::get(unsigned int pos)
const{    
    if(pos<size())
    {
        int i=0;
        PlayListNode *curr = head;
        while(curr)
        {   
            if(i==pos)
                return curr->song; 
            i++;
            curr = curr->next;
        }     
    }
    throw out_of_range("pos is out of range");
}

unsigned int PlayList::size()
const{
    return num_songs;
}

int main()
{
    PlayList x;
    x.insert(Song("Ad", "sad", 300), 0);
    cout << x.get(0).getArtist();

    PlayList y = x;
    
    return 0;
}