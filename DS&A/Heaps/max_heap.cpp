#include <iostream>
#include <vector>
using namespace std;

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

class maxHeap{
    public:
        int *arr;
        int elements;
        
    public:
        int n;
        void insert(int index);
        void heapify();
        void remove();
        void print();
        maxHeap(int *arr, int n):elements(0), arr(arr), n(n){};
        ~maxHeap(){elements = 0;}
};

void maxHeap::print()
{
    for(int i=0; i<elements; i++)
        cout << arr[i] << " ";
    
}

void maxHeap::insert(int index)
{
    arr[elements++] = arr[index];
    int i = elements-1;
    int temp = arr[i];
                                      
    while(i>0 && temp>arr[(i-1)/2])
    {  
        arr[i] = arr[(i-1)/2];
        i = (i-1)/2;
    }
    arr[i] = temp;
}

void maxHeap::remove()
{
    int x,i,j;
    x = arr[elements-1];
    int val = arr[0];
    arr[0] = x;

    i = 0; j= 2*i +1;
    while(j<elements-1)
    {
        if(arr[2*i+2] > arr[j])
            j = j+1;
        if(arr[i] < arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i=j;
            j=2*j+1;
        }
        else
            break;
    }
    arr[elements-1] = val;
    elements--;
}

 


 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n-2/2); i>=0; i--){     // n-1/2 
        int j = 2*i + 1;  // Left child for current i
 
        while(j < n-1){     // check for j is not NULL
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2*i + 1;
            } else {
                break;
            }
        }
    }
}
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int main() {
 
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A)/sizeof(A[0]), "A");
 
    Heapify(A, sizeof(A)/sizeof(A[0]));
    Print(A, sizeof(A)/sizeof(A[0]), "Heapified A");
    cout << endl;
 
    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B)/sizeof(B[0]), "B");
 
    Heapify(B, sizeof(B)/sizeof(B[0]));
    Print(B, sizeof(B)/sizeof(B[0]), "Heapified B");
 
    return 0;
}