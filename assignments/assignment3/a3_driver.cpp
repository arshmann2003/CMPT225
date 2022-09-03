#include <cmath>
#include "a3.h"



void cartesianProductTest()
{
    cout << "CARTESIAN PRODUCT TEST" << endl;
    int arr[9] = {3,5,3,2,1,5,6,4,9};
    int n = 9;
    int cost = 0;
    cout << "Cartesian product = "; 
    cartesianProduct(arr, n, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(cartesianProduct): 4n^2+5n+2 = " << 4*(n*n)+5*n+2;
    cout << endl << "--------------" << endl << endl;
}

void triangleTest()
{
    cout << "TRIANGLE TEST" << endl;
    int n = 10;
    int cost = 0;
    cout << "TRIANGLE = "; 
    triangle(n, cost);
    cout << endl << "cost = " << cost;
    cout << endl << "t(triangle): ((6n^2+6n)/2)+10n+3 = " << ((6*(n*n)+6*n)/2)+10*n+3;
    cout << endl << "--------------" << endl << endl;
}

void matrixSelfMultiplyTest(const int rows)
{
    cout << "MATRIX_SELF_MULTIPLY TEST" << endl;
    int *m = new int[rows*rows];
    
    int i=0;
    int j;
    while(i<rows*rows)
    {
        j=0;
        while(j<rows) 
        {
            m[i] = j+1; 
            i++;
            j++;
        }
    }
    int cost;
    int *x = matrixSelfMultiply(m, rows, cost);
    i=0;
    cout << "MATRIX = "; 
    while(i<rows*rows)
    {
        j=0;
        while(j<rows)
        {
            cout << x[i] << " ";
            i++;
            j++;
        }
        cout << "\n";
    }
    int n = rows;
    cout << "COST = " << cost << "\n"; 
    cout << "t(matrix_multiply): 5n^3+7n^2+4n+4 = " << 5*(n*n*n)+7*(n*n)+4*n+4;
    cout << endl << "--------------" << endl << endl;
}

void ssortTest()
{
    cout << endl << "--------------" << endl;
    cout << "SSORT TEST" << endl;
    int cost = 0;
    int n=29;
    int arr[30] = {30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    ssort(arr, n, 0, cost);

    int solution;
    if(n%2==0)
        solution =  (3*((n-1)*n))/2 + 7*n-6 + (n/2)*(n/2);
    else
        solution = (3*((n-1)*n))/2 + 7*n-6 + floor(n/2)*(floor(n/2)+1);
    cout << "\n| cost: " << cost;    
    cout << "\t| t(function): " << solution;
    if (cost==solution) {
        cout << "\t**MATCH**";
    } else {
        cout << "\t**MISMATCH**";
    } 
    cout << endl << "--------------" << endl;    
}

void patternTest()
{
    cout << "PATTERN TEST" << endl;
    
    for(int n=2; n<=16; n=n*2)
    {
        int cost = 0;
        cout << "PATTERN = "<< n << "\n";  
        pattern(n,0,cost);
        cout << endl << "cost = " << cost;

        int sol =  3*n*(log2(n)) + 23*n - 9;
        cout << endl << "t(pattern): 3nlogn+23n-9 = " << sol;
        // cout << endl << "--------------" << endl << endl;
        cout << "\n\n\n";
    }
}

void lsearchTest()
{
    int cost = 0;
    const int n = 12;
    int arr[n] = {7,8,9,10,11,12,13,96,97,98, 99,100};
    int x = lsearch(arr, n, 100, cost);
    cout << "FOUND at index " << x << "\n";
    cout << "cost = " << cost << "\n";
    cout << "t(lsearch): 2(2^n) + 2^n - 4 = " << 2*pow(2,n)+pow(2,n)-4 << "\n";
}

void powTest()
{
    
    cout << "POW TEST" << endl;
    int cost=0;

    int base = 1;
    int exp = 15;
    unsigned sol = pow(base,exp, cost);
    cout << "value = " << sol; 
    cout << endl << "cost = " << cost;
    cout << endl << "t(pow):  = ceil(log(exp)) " << 5*(ceil(log2(exp+1))) + 2;
    cout << endl << "--------------" << endl << endl;

}



int main()
{
    // cartesianProductTest();
    // triangleTest();
    // matrixSelfMultiplyTest(7);
    // ssortTest();
    // patternTest();
    // lsearchTest();
    // powTest();
 
    return 0;
}