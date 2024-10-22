#include<iostream>
#include<list>

using namespace std;

int main()
{
    list<int> li;

    li.push_front(1);
    li.push_back(2);

    list<int> c(li);

    list<int> n(5, 100);

    for(int i : n)
        cout<<i<<"  ";
        cout<<endl;
    
    cout<<li.size()<<endl;

    li.erase(li.begin());

    for(int i : li)
        cout<<i<<"  ";
        cout<<endl;
}