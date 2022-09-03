
#include <iostream>
#include "Sequence.h"
#include <vector>

using namespace std;


void print(vector<int> &S, ostream& os) {
    unsigned n = S.size();
    os << '[';
    for (unsigned i = 0; i < n; i++) {
        os << (i ? ", ": "") << S[i];
    }
    os << ']' << endl;
} // print


int main () {

    vector<int> S(5);
    
    print(S, cout);

    for (int i = 0; i < 5; i++) {
        S[i] = (i+1)*3;
    } // for

    print(S, cout);

    for (int i = 0; i < 5; i++) {
        S.push_back(i);
    } // for

    print(S, cout);

    S.erase(S.begin()+3, S.begin()+S.size());

    print(S, cout);

    return 0;
} // main

