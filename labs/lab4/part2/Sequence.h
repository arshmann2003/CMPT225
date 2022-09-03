#include <iostream>
using namespace std;

template <class T>
class Sequence {
    public:
        Sequence(unsigned size);
        void set(unsigned index, T x);
        T get(unsigned index);
        void append(T x);
        void trunc(unsigned newSize);
        unsigned getSize();

    private:
        T * arr;
        unsigned size;
};

template <class T>
Sequence<T>::Sequence(unsigned size) {
    this->size = size;
    arr = new T[size];
} // constructor


template <class T>
void Sequence<T>::set(unsigned index, T x) {
    if (index < size) {
        arr[index] = x;
    }
} // set


template <class T>
T Sequence<T>::get(unsigned index) {
    if (index < size) {
        return arr[index];
    }
    else
        throw logic_error("index value is not within range");
} // get


template <class T>
void Sequence<T>::append(T x) {
    T * newArr = new T[size + 1];
    
    for (unsigned i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size++] = x;

    if (arr) {
        delete [ ] arr;
    }
    arr = newArr;
} // append

template <class T>
void Sequence<T>::trunc(unsigned newSize) {
    if (newSize < size) {
        size = newSize;
    }
    
} // trunc

template <class T>
unsigned Sequence<T>::getSize() {
    return size;
} // getSize

