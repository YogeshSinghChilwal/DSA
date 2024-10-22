#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<string> st;

    st.push("Jon");
    st.push("Ram");
    st.push("Sham");

    cout<<st.top()<<endl;

    cout<<"Size->"<<st.size()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    st.pop();
    cout<<st.top()<<endl;

    cout<<"empty or not "<<st.empty()<<endl;



}