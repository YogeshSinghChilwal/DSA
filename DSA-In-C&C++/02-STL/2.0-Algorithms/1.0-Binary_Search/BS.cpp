#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);

    cout<<"Finding 5 -> " <<((binary_search(v.begin(), v.end(), 5)) ? 5 : -1)<<endl;

    cout<<"Lower Bound: "<<lower_bound(v.begin(), v.end(), 4) - v.begin()<<endl;

    cout<<"Upper Bound: "<<upper_bound(v.begin(), v.end(), 5) - v.begin()<<endl;

    cout<<"Max: "<<max(v.at(2), v.at(3))<<endl;

    cout<<"Min: "<<min(v.at(2), v.at(3))<<endl;

    int a = 4;
    int b = 5;

    swap(a, b);
    cout<<"a = "<<a<<endl;

    string s = "ABCDEF";

    reverse(s.begin(), s.end());

    cout<<s<<endl;

    rotate(v.begin(), v.begin() + 2, v.end());
    for(int i : v)
        cout<<i<<"  ";
        cout<<endl;



}