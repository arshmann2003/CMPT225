#include <iostream>
using namespace std;



int **initializing_2d_array(int rows, int column){

    //Create a 2d array within stack
    int A[3][4] = {{1,2,3,4}, {2,4,6,8}, {1,3, 5, 7}};
    
    //Partial stack 2d array
    //Rows of array created in stack, columns of array created in heap
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    //2d array fully stored in heap 
    //Any function can access such array with its pointer
    int **c;

    c = new int *[rows];
    for(int i=0; i<rows; i++){
        c[i] = new int[column];
    }
    
    return c;
}





int main(){


    return 0;


}