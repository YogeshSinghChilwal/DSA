#include<iostream>
#include<vector>
using namespace std;

int main(){

//! variable-length array
/*
This code snippet demonstrates the use of a variable-length array in C++.
However, it's important to note that variable-length arrays (VLAs) are not part of the standard C++ language;
they are a feature of C99 (the C programming language) but are not guaranteed to be supported in all C++ compilers.
*/

    int n; 
    cout<<"enter a number: ";
    cin>>n;
    int number[n] = {1,2,3,4};

    for(int x : number){    //* range-based for loop
        cout<<x<<"  ";
    }

//! using heap memory

    int x;
    cout << "Enter a number: ";
    cin >> x;

    // Dynamically allocate an array of size x
    int* num = new int[x]; // Allocate memory on the heap

    // Initialize the array with specific values
    // Here we're setting the first four elements if x >= 4
    if (x >= 4) {
        num[0] = 1;
        num[1] = 2;
        num[2] = 3;
        num[3] = 4;
    }

    // Initialize remaining elements to zero or another default value
    for (int i = 4; i < x; i++) {
        num[i] = 0; // or some other default value
    }

    // Print the elements of the array
    for (int i = 0; i < x; i++) {
        cout << num[i] << "  ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] num; // Deallocate memory

    //!using vector


    int y;
    cout << "Enter a number: ";
    cin >> y;

    // Create a vector with size y and initialize it with 1, 2, 3, 4 if y >= 4
    vector<int> vect(y); // Declare a vector of size y

    // Initialize the first 4 elements if y >= 4
    if (y >= 4) {
        vect[0] = 1;
        vect[1] = 2;
        vect[2] = 3;
        vect[3] = 4;
    }

    // Fill the rest of the vector with 0 or some default value
    for (int i = 4; i < y; i++) {
        vect[i] = 0; // or some other default value
    }

    // Print the elements of the vector
    for (int x : vect) {
        cout << x << "  ";
    }
    



}