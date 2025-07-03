#include <iostream>
#include <vector>
#include<climits>
using namespace std;

pair<int, int> getMinMax(vector<int> arr)
{
    // code here
    int min = INT_MAX;
    int max = INT_MIN;

    pair<int, int> result;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < min){
            min = arr[i];
            result.first = min;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            result.second = max;
        }
        
    }

    return result;
}

int main()
{
    vector<int> vect = {3,2,1,56,10000,167};
    pair<int, int> res = getMinMax(vect);

     cout << "Min: " << res.first << endl;
    cout << "Max: " << res.second << endl;

    return 0;
}