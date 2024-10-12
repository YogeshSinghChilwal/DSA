#include<iostream>
using namespace std;

int main(){
    int A[3][4] = {{1,2,3,4}, {2,4,5,6}, {2,5,6,8}};

    int *B[3];

    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    int **C;

    C = new int *[3];

    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}