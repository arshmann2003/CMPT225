#include <iostream>
#include <cmath>
using namespace std;

void cartesianProduct(int arr[], int n, int &ops)
{
    int i = 0;
    ops = 1;    // intialize count    // +1

    while (i < n)    //n+1
    {                 
        int j = 0;     //n
        ops += 2;

        while (j < n)     // n(n+1)
        {                                                     
            cout << "{" << arr[i] << "," << arr[j] << "}"; // n(n)
            j++;                                           // n(n)
            cout << " ";                                   // n(n)
            ops += 4;
        }
        cout << endl; // n
        i++;          // n
        ops += 3;
    }
    ops++;
} // f(n) = n^2 + n + 3n^2 + 2n +  2n + 2 = 4n^2 + 5n + 2  --> O(n^2)

void triangle(int n, int &ops)
{
    int i = 0; // 1
    ops = 1;

    while (i < n)    // n+1
    {                 
        int j = 0;  // n
        ops += 2;

        while (j <= i)      // n(n+1)/2 + n
        {                       
            cout << j << " "; // n(n+1)/2
            j++;              // n(n+1)/2
            ops += 3;
        }
        cout << endl; // n
        i++;          // n
        ops += 3;
    }
    ops++; // terminating condition

    while (i > 0)    // n+1
    {                
        i--;       // n
        int j = 0; // n
        ops += 3;

        while (j <= i)       // n(n+1)/2 + n
        {                       
            cout << j << " "; // n(n+1)/2
            j++;              // n(n+1)/2
            ops += 3;
        }
        cout << endl; // n
        ops += 2;
    }
    ops++;
} // equation = 3n^2 + 13n + 3   --> O(n^2)

// Returns the index of a 1d array representing a matrix
// given row (r) and column (c) values
int rcIndex(int r, int c, int columns)
{ 
    return r * columns + c;
}

// PRE: m represents a square matrix of size rows * rows
// PARAM: rows represents the number of both rows and columns
// POST: Returns a pointer to an array (matrix) of the same size as m
// NOTE: values are indexed r0c0,r0c1,…,r0cn-1,r1c0,…
int* matrixSelfMultiply(int* m, int rows, int &ops)
{
    // let n = rows
    // Create result array
    ops=0;
    int columns = rows;                     //1
    int* result = new int[rows * columns];      //1
    int r = 0;                              //1
    ops += 3;

    while (r < rows) {           //n+1
        int c = 0;            //n
        ops+=2;
        while (c < columns) { //columns = rows     n(n+1)
            int next = 0;                       // n(n)
            int iNext = 0;                      // n(n)
            ops+=3;

            while (iNext < rows) {     // n(n(n+1))
                next += m[rcIndex(r, iNext, columns)] * m[rcIndex(iNext, c, columns)];   // 3n^3
                iNext++;        // n^3
                ops+= 5;
            }
            ops++;

            result[rcIndex(r, c, columns)] = next;   // 2n^2
            c++;                                    // n^2
            ops+=3;
        }
        r++;    // n
        ops+=2;               
    }
    ops++;                  
    return result;
}       // equation = 5n^3 + 7n^2 + 4n + 4 --> O(n^3)



// PARAM: arr is array to be sorted, n is size of array, i should initially = 0
void ssort(int arr[], int n, int i, int &ops)
{
    ops++;
    if (i < n-1) { // n.    one for terminating conidtion
        // Find and swap smallest remaining
        int next = i + 1;   //n-1 .
        int smallest = i;   //n-1 .
        ops+=2;

        while (next < n) {    //(n-1)(n)/2 + n-1 .
            if (arr[next] < arr[smallest]) {  // (n-1)(n)/2 .
                smallest = next;    // n/2(n/2+1) or (n/2)^2
                ops++;
            }
            next++;     //(n-1)(n)/2 
            ops+=3;
        }
        ops++; 

        // Swap i with smallest
        int temp = arr[i];          // n-1 .
        arr[i] = arr[smallest];     // n-1 .
        arr[smallest] = temp;        // n-1 .
        ops+=3;
        
        ssort(arr, n, i + 1, ops);      
    }
   

} // equation when n is odd = ((3n^2-3n)/2)+7n-6 + floor(n/2)*(floor(n/2)+1)   --> o(n^2)
                // n is even = ((3n^2-3n)/2)+7n-6 + (n/2)^2



// all log functions are to the base 2
// PRE: n is a power of 2 greater than zero.
// PRE: Initial call should be to i = 0
// e.g. pattern(8, 0)
void pattern(int n, int i, int &ops)
{
    ops++;
    if (n > 0) {    // (2^(logn+1)-1) + (2^(logn+1))
        ops++;  
        pattern(n/2, i, ops);
        // Print i spaces
        cout << string(i, ' ');  // 4(2^(logn+1)-1) .
        ops+=4;

        // A loop to print n asterisks, each one followed by a space
        int ast = 0;
        ops++;              // 2^(logn+1)-1 .
        while (ast < n) {   // n(logn+1)
            cout << "* ";        // n(logn+1)
            ast++;               // n(logn+1)
            ops+=3;
        }
        ops++;              // 2^(logn+1)-1
 
        cout << endl;
        i += n;
        ops+=2;         //2(2^(logn+1)-1)
        pattern(n / 2, i, ops);
    }   
} // equation = 3nlogn + 23n - 9    -->   O(nlogn)

// Desc: Linear search.  Reports position if found, else -1
// Post:  Elements unchanged
int lsearch(int arr[], unsigned int len, int target, int &ops) {
   
    ops++; 
    if (len == 0) return -1;          // 2^n - 1
    ops++;
    if (arr[0] == target) return 0;     // 2^n - 1
    ops++;
    if (lsearch(arr+1, len-1, target, ops) == -1) {         // 2^(n-1)-1 
        return -1;
    } else {
        ops++;
        return 1 + lsearch(arr+1, len-1, target, ops);          // 2^(n-1)-1
    }
} // lsearch equation = 3(2^n) - 4    --> O(2^n)



unsigned pow(unsigned int base, unsigned int exp, int &ops) {
    
    // let n = exp
    unsigned int ret = 1;           // 1
    ops=1;
    while (exp > 0) {   // ceil(log(n+1)) + 1(termination)
        if (exp & 1) {  
            ops++;    // ceil(log(n+1))    // not  
            ret *= base;        // ceil(log(n+1)) executed every time in worst case binary of exp = 1111...
        }
        exp >>= 1;      // ceil(log(n+1))
        base = base * base;     // ceil(log(n+1))
        ops+=4;
    }
    ops++;                  // 1
    return ret;
} // pow equation = 5*(ceil(log(exp+1))) + 2        -->    O(logn)