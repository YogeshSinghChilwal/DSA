#include<iostream>
#include<vector>

using namespace std;


int main()
{
    vector<int> v;

    cout<<"Capacity-> "<<v.capacity()<<endl;    //0     space assigned for elements
    cout<<"Size->"<<v.size()<<endl;     //how may elements are in there

    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl;    //1
    cout<<"Size->"<<v.size()<<endl;

    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;    //2
    cout<<"Size->"<<v.size()<<endl;

    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;    //4
    cout<<"Size->"<<v.size()<<endl;

    v.push_back(4);
    cout<<"Capacity-> "<<v.capacity()<<endl;    //4
    cout<<"Size->"<<v.size()<<endl;

    v.push_back(5);
    cout<<"Capacity-> "<<v.capacity()<<endl;    //8
    cout<<"Size->"<<v.size()<<endl;

    vector<int> a(5, 1);

    vector<int> copyed(a);



    for(int i = 0; i < v.size(); i++)
        cout<<copyed[i]<<"   ";
        cout<<endl;

    cout<<v.at(2)<<endl;

    cout<<v.front()<<"  "<<v.back()<<endl;

    v.pop_back();

    cout<<v.front()<<"  "<<v.back()<<endl;

    v.begin();

    cout<<"Capacity-> "<<v.capacity()<<endl;    
    cout<<"Size->"<<v.size()<<endl;

    v.clear();

    cout<<"Capacity-> "<<v.capacity()<<endl;    
    cout<<"Size->"<<v.size()<<endl;

    

}