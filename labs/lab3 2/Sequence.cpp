
#include <iostream>
#include "Sequence.h"
using namespace std;



Sequence::Sequence(unsigned size) {
    this->size = size;
    arr = new int[size];
} // constructor



void Sequence::set(unsigned index, int x) {
    if (index < size) {
        arr[index] = x;
    }
} // set

    // Desc: The get method takes in a positive integer index
    // and returns the array value at such index
    //  Pre: To check whether the index < size and that the index is valid
    // Post: If the pre condition is not met, then we can throw an out of range exception
    //This is the post because it only gets called if the pre condition is not met
int Sequence::get(unsigned index) {
    if (index < size) {
        return arr[index];
    }
    // return 0;
    // assert(false);
    throw out_of_range("get(i): index out of range");
} // get



void Sequence::append(int x) {
    int * newArr = new int[size + 1];
    
    for (unsigned i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size++] = x;

    if (arr) {
        delete [ ] arr;
    }
    arr = newArr;
} // append



void Sequence::trunc(unsigned newSize) {
    if (newSize < size) {
        size = newSize;
    }
} // trunc



unsigned Sequence::getSize() {
    return size;
} // getSize



void Sequence::print(ostream& os) {
    for (unsigned i = 0; i < size; i++) {
        os << arr[i] << ' ';
    }
    os << endl;
} // print

