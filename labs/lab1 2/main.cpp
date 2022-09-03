/***
 *
 * Testing driver for class Triple
 *
 **/


#include <iostream>
#include "Triple.h"

using namespace std;


void print(Triple v) {
    cout << '(' << v.getX() << ',' << v.getY() << ',' << v.getZ() << ')';
} // print


double dotProduct(const Triple v, const Triple w) {
    double ret = 0.0;
    ret = v.getX()*w.getX() + v.getY()*w.getY() + v.getZ()*w.getZ();
    return ret;
} // dotProduct


int main () {
    Triple A(2.0, 5.5, 6.2);
    Triple B(4.2, -3.2, 1.2);

    cout << "A = "; print(A); cout << endl;
    cout << "B = "; print(B); cout << endl;

    Triple C;

    C.setX(4.0);
    C.setY(2.2);
    C.setZ(-1.6);

    cout << "C = "; print(C); cout << endl;

    cout << "A·B = " << dotProduct(A,B) << endl;
    cout << "A·C = " << dotProduct(A,C) << endl;
	cout << "B·C = " << dotProduct(B,C) << endl;


} // main

