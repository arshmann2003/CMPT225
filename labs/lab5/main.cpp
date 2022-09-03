
#include <iostream>
#include "ss.h"


using namespace std;

int main () {
    int a[10] = { 4, 6, 10, 5, 1, 3, 8, 7, 2, 9 };

    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    } // for
    cout << endl;

    ss(a, 10);

    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    } // for
    cout << endl;

    return 0;
} // main

