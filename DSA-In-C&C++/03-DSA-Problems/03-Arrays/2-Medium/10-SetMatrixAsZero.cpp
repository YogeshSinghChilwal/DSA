/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/

#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if(j != 0)
                    {
                        matrix[0][j] = 0;
                    } else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(matrix[i][j] != 0)
                {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0)
        {
            for(int j = 0; j < m; j++) matrix[0][j] = 0;
        }

        if(col0 == 0)
        {
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
    }

    class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1; // Flag to track if the first column should be set to zero
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Mark rows and columns for zeroing
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0; // Mark first column for zeroing
            }
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark row for zeroing
                    matrix[0][j] = 0; // Mark column for zeroing
                }
            }
        }

        // Step 2: Set matrix cells to zero based on markers, excluding the first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main(){
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    Solution solution;
    solution.setZeroes(matrix);

    cout << "\nModified Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}