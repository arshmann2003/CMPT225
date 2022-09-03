
#include <iostream>
#include "profile-ss.h"


using namespace std;

int main () {
    int a[10] = { 4, 6, 10, 5, 1, 3, 8, 7, 2, 9 };
    unsigned counter = 0;

    int worst_arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    unsigned counter_2 = 0;


    ss(a, 10, counter);
    cout << "Operation count: " << counter << endl;

    ss(worst_arr, 10, counter_2);
    cout << "Operation count for worst case: " << counter_2 << endl;

    return 0;
} // main

