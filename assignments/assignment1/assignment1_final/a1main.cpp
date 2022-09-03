// Author: Arshdeep Mann #301461759
// Date: May 2022

/* Running time analysis
---------------------------------------------PLAYLIST METHODS---------------------------------------------
Playlist(): The constructor only has two operations and does not change 
therefore it has a constant running time - O(1)

PlayList(const PlayList& pl): The copy constructor goes through the entire pl list 
and allocates new nodes with the data coming from pl. No matter the length of the list each element 
of the list in pl is traversed once. Therefore, the running time of this function is linear - O(N)

~PlayList: The destructor requires to loop the entire linked list while keeping track of next and
previous in order to delete each node, therefore the running time of this function is linear - O(N)

PlayList& operator=(const PlayList & pl): The overloaded assignment operator copies all data of pl into
it's own linked list. It goes through each element in the list in pl and there are N + c operations 
(c is the other constant operations). Therfore, the running time of this function is linear. - O(N)

void insert(Song sng, unsigned int pos): The insert function goes through the list until the pos is in the 
right place. At the worst case pos could be N(len of list) so traversal through the entire list is required.
Therefore, the running time of this method is linear in the worst case. - O(N)

Song remove(unsigned int pos): The running time of the remove method is similar to insert, being that
in the worst case pos could be equal to the length of the list. Therefore, the entire list would be
traversed so in the worst case in the running time is linear. - O(N)

void swap(unsigned int pos1, unsigned int pos2): The swap method would go through the entire list when either
position is the last element in the list. Therfore, in the worst case the entire list would be traversed
so the running time would be linear. - O(N)
        
Song get(unsigned int pos) const: Linked lists do not allow for direct access to list elements. So traversal is
required, until the right position is reached. The worst case would be that pos is equal to the len of the list.
So in the worst case the running time is linear. - O(N)

unsigned int size() const: This method is constant because the implementation of the linked list keeps track of
it's size. So this function is constant as it only returns an unsigned integer. - O(1)

---------------------------------------------MAIN METHODS---------------------------------------------
Enter a song: The enter song option has several operations that cost constant time but when the 
insert method is called the running time becomes linear. The while loop terminates whenever the valid  
input is provided. - O(N)

Remove a song: The remove a song section validates for valid input before calling the remove function.
Therefore the running time is (N+c) because main calls remove and the running time of remove is
linear in the worst case. - O(N)

Swap two songs: The swap section in the main file validates for two positions and then calls the 
swap method. Therefore, the running time of the swap process are all the constant operations in 
main + the running time of swap method. - O(N)

Print all the songs: The print method costs quadratic time because for each element the get method is
called. With the get method traversing the entire list in the worst case, the overall running 
time is quadratic. - O(N^2)

*/

#include "PlayList.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
    //Menu
    cout << "Menu: " << endl;
    cout << "1 - Enter a song in the play list at a given position" << endl;
    cout << "2 - Remove a song from the play list at a given position" << endl;
    cout << "3 - Swap two songs in the play list" << endl;
    cout << "4 - Print all the songs in the play list" << endl;
    cout << "5 - Quit" << endl;

    //Object allocated on the stack
    PlayList list;

    bool check = true;
    while(check)
    {
        cout << "\n";
        bool valid_menu_num = false;
        unsigned int choice;
        while(!valid_menu_num)
        {
            cout << "Enter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";
            if(cin >> choice && choice>=1 && choice<=5)
                valid_menu_num = true;
            else{
                cout << "Enter a valid integer value!\n\n";
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        if(choice==1)
        {    
            string artist;
            string name;
            int length;
            unsigned int pos;

            cin.ignore();
            cout << "Song name: "; getline(cin,name);
            cout << "Artist: "; getline(cin, artist);
            
            bool valid_len = false;
            while(!valid_len)
            {
                cout << "Length: "; 
                if(cin >> length && length>0)
                    valid_len=true;
                else{
                    cout << "Enter a valid integer value!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }                
            }
            cin.clear();
            cin.ignore();

            unsigned int end_index;
            if(list.size()==0)
                end_index = 1;
            else
                end_index = list.size()+1;

            bool valid_pos = false;
            while(valid_pos==false)
            {
                if(list.size()==0)
                    cout << "Posistion(1): ";
                else
                    cout << "Position(1 to " << end_index << "): ";
                if(cin>>pos && pos<=end_index && pos>=1)
                    valid_pos = true;
                else{
                    cout << "Enter a valid integer value!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            Song sng(name, artist, length);
            list.insert(sng, pos-1);
        }
        else if(choice==2)
        {
            if(list.size()==0)
                cout << "EMPTY LIST\n";
            else{
                unsigned int position;
                bool valid_position = false;
                unsigned int length = list.size();
                while(!valid_position)
                {
                    if(length==1)
                        cout << "Position(1): ";
                    else if(list.size()>1)
                        cout << "Position(1 to " << length << "): ";
                    if(cin>>position && position>=1 && length<=list.size())
                        valid_position = true;
                    else{
                        cout << "Invalid position try again!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
                    }
                }
                list.remove(position-1);
            }    
        }
        else if(choice==3)
        {
            if(list.size()>1)
            {                
                unsigned int end_index = list.size();
                
                unsigned int pos_1;
                unsigned int pos_2;

                bool valid_1 = false;
                bool valid_2 = false;
                while(!valid_1)
                {
                    cout << "Swap song at position (1 to " << end_index << "): ";
                    if(cin>>pos_1 && pos_1>=1 && pos_1<=end_index)
                        valid_1 = true;
                    else{
                        cout << "Invalid position!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    }
                }
                while(!valid_2)
                {
                    cout << "Swap song at position (1 to " << end_index << "): ";
                    if(cin>>pos_2 && pos_2>=1 && pos_2<=end_index)
                        valid_2 = true;
                    else{
                        cout << "Invalid position!\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    }
                }
                list.swap(pos_1-1, pos_2-1);
            }
            else
                cout << "EMPTY LIST OR 1 ELEMENT" << endl;
        }
        else if(choice==4)
        {
            if(list.size()==0)
            {   
                cout << "EMPTY LIST\n";
            }
            else
            {
                for(int i=0; i<list.size(); i++)
                {
                    cout << i+1 << " " << list.get(i).getName() << endl;
                }
            }
        }
        else if(choice==5)
        {
            check = false;
        }
    }
    return 0;
}