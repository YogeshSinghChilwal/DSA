/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    for(auto row: matrix){
        for(int ele: row){
            cout<<ele<<"    ";
        }
        cout<<endl;
        
    }

    rotate(matrix);
    cout<<endl;

    for(auto row: matrix){
        for(int ele: row){
            cout<<ele<<"    ";
        }
        cout<<endl;
        
    }

    return 0;
}