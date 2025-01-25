/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> generateRow(int row)
{
    vector<int> temp;
    long long ans = 1;
    temp.push_back(1);
    for (int i = 1; i < row; i++)
    {
        ans = ans * (row - i);
        ans = ans / i;
        // temp.push_back(ans);
        temp.push_back(static_cast<int>(ans));
    }
    return temp;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    vector<vector<int>> triangle = generate(6);
    for(auto row: triangle){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}