#include <iostream>
#include <time.h>

void merge(int arr[], int first, int mid, int last)
{
    int newArr[last+1];
    int i = first;
    int j = mid+1;
    int k = first;

    while(i <= mid && j <= last)
    {
        if(arr[i] <= arr[j]){
            newArr[k++] = arr[i++];
        }
        else{
            newArr[k++] = arr[j++];
        }
    }
    while(i<=mid){
        newArr[k++] = arr[i++];
    }
    while(j<=last){
        newArr[k++] = arr[j++];
    }
    for(int q=first; q<=last; q++){
        arr[q] = newArr[q];
    }
}

void mergeSort(int arr[], int first, int last)
{
    if(first < last)
    {
        //split array
        int mid = (first+last)/2;

        //recursively sort
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, last);
    }
}

void array()
{
    int *newArr = new int[5];
    delete []newArr;
}

int main()
{
    srand(time(NULL));
    int A[14];
    for(int i=0; i<14; i++)
    {
        A[i] = rand() % 100 + (-20);
    }
    
    mergeSort(A, 0, 13);
    for(int i=0; i<14; i++)
    {
        std::cout << A[i] << " ";
    }
    array();
    array();
    array();
    array();

    
    return 0;
}