#include <iostream>

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}



int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i=l, j=h; 

    do
    {
        do{i++;} while(A[i]<=pivot);
        do{j--;} while(A[j]>pivot);

        if(i<j)swap(A[i], A[j]);
    }while(i<j);
    swap(A[l], A[j]);
    return j; 
}


void qsort(int A[],int l,int h)
{
    int j;

    if(l<h)
    {
        j=partition(A,l,h);
        qsort(A,l,j);
        qsort(A,j+1,h);
    }
}

int main()
{
    int arr[9] = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    int x = partition(arr, 0, 8);
    std::cout << x << "\n";
    
    qsort(arr, 0, 9);
   
    for (int i = 0; i < 9; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}

