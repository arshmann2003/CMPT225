#include <vector>
#include <iostream>
using namespace std;



//[1,1,2,2] --> [1,2,_,_]
//Go through array and shift elements one to the left if element is repeated

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            //Same element is found shift array 1 to the left
            if(nums[i]==nums[i-1])
            {
    
                for(int j=i; i<n; i++)
                {
                    nums[j] = nums[j+1];
                }
            }
            cout << "\n";
            for(int i=0; i<nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
        }
        return count;
    }
};


int main()
{


    vector<int> x;

    x.push_back(0);
    x.push_back(0);
    x.push_back(1);
    x.push_back(1);
    x.push_back(2);
    x.push_back(2);



    Solution test;

    test.removeDuplicates(x);


    return 0;
}