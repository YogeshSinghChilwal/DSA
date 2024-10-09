#include<iostream>
using namespace std;

int main(){
    //^ Multidimensional Arrays

    int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };

    cout << "2D Array elements: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

//& Limitations
// Fixed Size: Once declared, the size of an array cannot be changed.
// Memory: Arrays allocate memory in contiguous locations, which can lead to inefficiencies with larger datasets.