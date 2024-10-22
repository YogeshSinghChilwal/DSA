#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(9);
    s.insert(12);
    s.insert(5);
    s.insert(5);

    for(auto i : s)
        cout<<i<<"  ";
        cout<<endl;

    

    set<int>::iterator it = s.begin();

    it++;
    it++;

    s.erase(it);

    for(auto i : s)
        cout<<i<<"  ";
        cout<<endl;

    cout<<s.count(50)<<endl;

    set<int>::iterator itr = s.find(5);

    cout<<*(++itr)<<endl;

}