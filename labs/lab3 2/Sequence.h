
#include <iostream>

class Sequence {
    public:
        Sequence(unsigned size);
        void set(unsigned index, int x);

        // Desc: The get method takes in a positive integer index
        // and returns the array value at such index
        //  Pre: To check whether the index < size and that the index is valid
        // Post: If the pre condition is not met, then we can throw an out of range exception
        //This is the post because it only gets called if the pre condition is not met
        int get(unsigned index);
        void append(int x);
        void trunc(unsigned newSize);
        unsigned getSize();

        void print(std::ostream& os);

    private:
        int * arr;
        unsigned size;
};

