#include "profile-ss.h"



unsigned searchMin(int a[], unsigned len, unsigned &cout);


// Desc:  sorts array by finding the min in each sub section
void ss(int a[], unsigned len, unsigned &count) {
    count++;
    if (len <= 1) return;
    
    unsigned minPos = searchMin(a, len, count);
    int tmp = a[0];
    a[0] = a[minPos];
    a[minPos] = tmp;
    ss(a + 1, len - 1, count);

    count = count+5;

} // ss



// Desc:  Finds the position of the minimum element in a[n]
//  Pre:  len > 0
// Post:  a[] elements are unchanged.
unsigned searchMin(int a[], unsigned len, unsigned &count) {
    unsigned ret = --len;
    count++;

    while (len--) {
        count = count+2;
        if (a[len] < a[ret]) {
            ret = len;
            count++;
        }
    }

    return ret;
} // searchMax
