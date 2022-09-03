#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = "";
        
        
        char sub_letter;
        bool cond = true;
        int j=0;
        while(cond)
        {
            sub_letter = strs[0][j];
            for(int i=0; i<strs.size(); i++)
            {
                // if(strs[i]=="")
                //     return "";
                if(j > strs[i].size())
                    return prefix;
                if(strs[i][j]!=sub_letter)
                {
                    cond = false;
                }
            }
            if(cond)
            {
                prefix+=strs[0][j];
            }
            j++;
            
        }
        return prefix;
            
        
    }
};
    

int main()
{
    Solution test;
    vector<string> list;
    
    list.push_back("arsh");
    list.push_back("ars");
    list.push_back("ars");

    string x = test.longestCommonPrefix(list);
    cout << x;

}