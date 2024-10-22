#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "Car";
    m[5] = "toys";
    m[2] = "Bikes";

    m.insert({3, "Plane"});

    for(auto i : m)
        cout<<i.first<<"    "<<i.second<<endl;

    cout<<"Find 5: "<<m.count(5)<<endl;
    
    m.erase(2);

     for(auto i : m)
        cout<<i.first<<"    "<<i.second<<endl;

    auto it = m.find(1); //iterator map<int, string>::iterator it = m.find(1);

    for(auto i = it; i != m.end(); i++)
        cout<<(*i).first<<"     "<<(*i).second<<endl;




}