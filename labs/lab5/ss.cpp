
#include "ss.h"


unsigned searchMin(int a[], unsigned len);


// Desc:  sorts array by finding the min in each sub section
void ss(int a[], unsigned len) {
    if (len <= 1) return;

    unsigned minPos = searchMin(a, len);

    int tmp = a[0];
    a[0] = a[minPos];
    a[minPos] = tmp;

    ss(a + 1, len - 1);

} // ss



// Desc:  Finds the position of the minimum element in a[n]
//  Pre:  len > 0
// Post:  a[] elements are unchanged.
unsigned searchMin(int a[], unsigned len) {
    unsigned ret = --len;

    while (len--) {
        if (a[len] < a[ret]) {
            ret = len;
        }
    }

    return ret;
} // searchMax


