#include<iostream>
#include<deque>

using namespace std;


int main()
{
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);

    q.push_front(4);
    q.push_front(5);

    for(int i : q)
        cout<<i<<"  ";
        cout<<endl;

    q.pop_back();
    q.pop_front();

    for(int i : q)
        cout<<i<<"  ";
        cout<<endl;

    cout<<q.at(2)<<endl;

    cout<<q.front()<<"  "<<q.back()<<endl;

    cout<<q.empty()<<endl;

    cout<<q.size()<<endl;

    q.erase(q.begin(), q.begin() + 1);

    for(int i : q)
        cout<<i<<"  ";
        cout<<endl;

    cout<<q.size()<<endl;

}