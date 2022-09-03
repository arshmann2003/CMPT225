
#include <iostream>
#include "Sequence.h"
#include <stdexcept>

using namespace std;

int main () {
    Sequence S(5);

    S.print(cout);

    for (int i = 0; i < 5; i++) {
        S.set(i, (i+1)*3);
    } // for

    S.print(cout);

    for (int i = 0; i < 7; i++) {
        try{
            cout << S.get(i) << ' ';
        }
        catch(exception &e){
            cout << "Exception occurred: " << e.what() << endl;
        }
    } // for
    cout << endl;

    return 0;
} // main

