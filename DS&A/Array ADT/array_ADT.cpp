#include <iostream>
using namespace std;


template <class T>
class Array_functions{
    private:
        T *arr;
        int len;
        bool sorted;

    public: 
        Array_functions(){
            arr = new T[0];
            len = 0;
            sorted = false;
        }
        
        void display()
        {
            for(int i=0; i<len; i++){
                cout << arr[i] << " ";
            }
        }

        void append(T element)
        {
            //create new array and increase length by 1
            T *new_arr = new T[len+1];
            
            //Copy all values from original array to new_arr
            for(int i=0; i<len; i++){
                new_arr[i] = arr[i];
            }

            //Add the element to the last position of the new_arr;
            new_arr[len] = element;

            len++;
            delete arr;
            arr = new_arr;
        }        

        void insert(int index, T element)
        {

            if(index>len || index<0)
                return;
            

            T *new_arr = new T[len+1];
            
            for(int i=0; i<len; i++){
                new_arr[i] = arr[i]; 
            }
            new_arr[len] = new_arr[len-1];
            
            //Shift all elements starting from arr[index] to arr[len-1] to the right
            for(int i=len-1; i>index; i--)
            {
                new_arr[i] = new_arr[i-1];
            }
            new_arr[index] = element;
            
            len++;
            delete arr;
            arr = new_arr;            
        }

        void swap(T &x, T &y)
        {   
            T temp = x;
            x = y;
            y = temp;
        }

        void sort()
        {
            //insetion sort
            for(int i=0; i<len; i++)
            {
                int minIndex = i;
                for(int j=i+1; j<len; j++)
                {
                    if(arr[j]<arr[minIndex])
                        minIndex = j;
                }
                swap(arr[i], arr[minIndex]);
            }
            sorted = true; 
        }    
    
        int search(T element)
        {   
            //If not sorted use linear search
            if(!sorted)
            {
                for(int i=0; i<len; i++)
                {
                    if(arr[i]==element)
                    {
                        return i;
                    }
                }
            }
            else if(sorted)
            {
                //Use binary search
                int l,mid,h;
                l=0;
                h=len-1;

                while(l<=h)
                {
                    mid=(l+h)/2;
                    if(element==arr[mid])
                        return mid;
                    else if(element<arr[mid])
                        h=mid-1;
                    else 
                        l=mid+1;
                } 
            }
            return -1;
        }

        void delete_element(int index)
        {
            for(int i=index; i<len-1; i++)
            {
                arr[i] = arr[i+1];
            }
            len--;
        }

        T max()
        {
            if(sorted)
            {
                return arr[len-1];
            }
            else
            {
                T max = arr[0];
                for(int i=0; i<len; i++)
                {
                    if(arr[i]>max)
                    {
                        max = arr[i];
                    }
                }
                return max;
            }
            
        }
        
        T min()
        {
            if(sorted)
            {
                return arr[0];
            }
            else
            {
                T min = arr[0];
                for(int i=0; i<len; i++)
                {
                    if(arr[i]<min)
                    {
                        min = arr[i];
                    }
                }
                return min;
            }
            
        }

};

int main(){
    
    Array_functions<int> x;
    x.append(0);
    x.append(1);
    x.append(2);
    x.append(3);
    x.append(4);

    int arr[5] = {1,2,3,4};

    //insert 95 in position 2
    int n = 5;
    int index = 2;
    for(int i=n-1; i>index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = 95;

    for(int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}