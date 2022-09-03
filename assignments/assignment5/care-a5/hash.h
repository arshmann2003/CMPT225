
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const unsigned scale = 225;


// * * * replace with your own personal modulus * * * //
// 301461759
// 3759  --> 3739
const unsigned M = 3011;


// Desc:  Dynamic Set of strings using a Hash Table (generic version)
//  Pre:  class T must have an attribute key of type string
template <class T>
class Set {
    private:
        T * A[M];
        int hashFunction(string data)const;
        int bValue(char x)const;
        int horner(int arr[], int n, int x)
        const{
            int result = arr[0]; 
            for (int i=1; i<n; i++){
                result = result*x + arr[i];
                result = result%M;
            }
            result *= 225;
            result %= M;
            return result;
        };
            

    public:
        // Desc:  Default constructor.  Initialize table to NULL.
        Set() { 
            memset(A, 0, sizeof(T *)*M); 
        }

        // Desc:  Insert x into the Set, according to its ->key.
        //        If ->key is already present, then replace it by x.
        //        Collisions are resolved via quadratic probing sequence.
        // Post:  returns the table index where x was inserted
        //        returns -1 if x was not inserted
        int insert(T * x);

        // Desc:  Returns T * x such that x->key == key, if and only if 
        //        key is in the Set.
        //        Returns NULL if and only if key is not in the Set.
        // Post:  Set is unchanged
        T * search(string key) const;
};



template <class T>
int Set<T>::bValue(char x)
const{
    char array[63] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j',
        'k','l','m','n','o','p','q','r','s','t',
        'u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J',
        'K','L','M','N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','-'
    };

    for(int i=0; i<63; i++)
    {
        if(x==array[i])
            return i;
    }
    return 0;
}

template <class T>
int Set<T>::hashFunction(string data)
const{   
    int n = data.size(); // n = 5
    int arr[n];

    for(int i=0; i<n; i++)
        arr[i] = bValue(data[i]);

    return horner(arr, n, 64);    
}


// Desc:  Insert x into the Set, according to its ->key.
//        If ->key is already present, then replace it by x.
//        Collisions are resolved via quadratic probing sequence.
// Post:  returns the table index where x was inserted
//        returns -1 if x was not inserted

template <class T>
int Set<T>::insert(T * x) {

    int hash_index = hashFunction(x->key);

    if(A[hash_index]==NULL || A[hash_index]->key==x->key)
    {
        A[hash_index] = x;
        return hash_index;
    }
    
    // Use quadratic probing if no free space at hash_index
    for(int i=1; i<=(M/2 + 1); i++)
    {
        int new_index = (hash_index + i*i) % M;
        if(A[new_index]==NULL || A[new_index]->key==x->key)
        {
            A[new_index]=x;
            return new_index;
        }
    } 

    // no free space because loading factor is approximately half of M
    return -1;
}


// Desc:  Returns T * x such that x->key == key, if and only if 
//        key is in the Set.
//        Returns NULL if and only if key is not in the Set.
// Post:  Set is unchanged
template <class T>
T * Set<T>::search(string data) const {
    int index = hashFunction(data);
    
    if(A[index]!=NULL && A[index]->key==data)
        return A[index];

    for(int i=1; i<(M/2 + 1); i++)
    {
        int temp_index = (index + i*i)%M;

        if(A[temp_index]==NULL)
            return NULL;
        if(A[temp_index]->key==data)
            return A[temp_index];
    }
    return NULL;
}

