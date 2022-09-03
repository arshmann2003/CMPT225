
#include <vector>

template <class T>
class Search
{
    private: 
        std::vector<T> arr;
        int size;
    public:
        Search();
        void print();
        T get(unsigned pos);
        int getSize();
        void selectionSort();
        int binarySearch1(T object) const;
        int recurssive_binarySearch(T object, int low, int high) const;
        int linearSearch(T object) const;

};


