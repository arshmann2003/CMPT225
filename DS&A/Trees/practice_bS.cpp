#include <iostream>
using namespace std;

int iterativeBS(int arr[], int low, int high, int target)
{
    if(arr==NULL)
        return -1;

    int mid;
    while(low < high)
    {
        mid = (low+high)/2;
        if(arr[mid]==target)
            return mid;

        else if(target < arr[mid])
        {
            high = mid-1;
        } 
        else
            low = mid+1;
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int target)
{

    if(low>high)
        return -1;
    
    int mid = (low+high)/2;
    if(target==arr[mid])
        return mid;
 
    else if(target < arr[mid])
        return binarySearch(arr, low, mid-1, target);
    else
        return binarySearch(arr, mid+1, high, target);

}

 


int main()
{
    int arr[6] = {1,2,3,4,5,6};
    cout << iterativeBS(arr, 0, 5, 3);
 
    return 0;
}