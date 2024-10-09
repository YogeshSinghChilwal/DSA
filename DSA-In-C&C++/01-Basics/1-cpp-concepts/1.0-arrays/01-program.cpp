//^ In C++, arrays are used to store multiple values of the same type in a single variable.

#include<iostream>
using namespace std;

int main(){

    int A[5];    // Declaration of an integer array with 5 elements

    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    int numbers[5] = {1, 2, 3, 4, 5}; // Initialized with 5 elements

    cout << "Numbers: "<< numbers[0]<<endl; // Accesses the first element (1)


    int B[] = {1,2,3,4,5,6};

    cout<<"Sise of A: "<<sizeof(A)<<endl;

    cout<<A[1]<<" ";

    cout<<A[3]<<" "<<endl;

    printf("%d", A[2]);

    for(int i = 0; i < 5; i++){
        cout<<A[i]<<endl;
    }



    return 0;
}