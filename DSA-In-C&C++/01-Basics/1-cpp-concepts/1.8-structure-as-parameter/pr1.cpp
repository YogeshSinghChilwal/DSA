#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breath;
};

void fun1(Rectangle r){
    r.length = 20;
    cout<<"Length "<<r.length<<endl<<"Breadth "<<r.breath<<endl;
};

void fun2(Rectangle *p){
    (*p).length = 20;
    cout<<"Length "<<(*p).length<<endl<<"Breadth "<<p->breath<<endl;
};

struct Rectangle *fun(){
    struct Rectangle *p;
    p = new Rectangle;

    p->length = 30;
    p->breath = 5;
}

struct Test
{
    int a[5];
    int n;
};


void fun3(Test t1){
    t1.a[0] = 20;
    t1.a[2] = 30;
    cout<<t1.a[0]<<endl;
}
int main(){
    Rectangle r = {10, 5};

    cout<<r.length<<" "<<r.breath<<endl;

    // fun(r);
    // fun2(&r);

    // cout<<r.length<<" "<<r.breath<<endl;

    // Rectangle *ptr = fun();

    // cout<<"length "<<ptr->length<<endl<<"breath "<<ptr->breath<<endl;
    // cout<<r.length<<" "<<r.breath<<endl;

    Test t = {{1,2,3,4,5}, 99};
    fun3(t);
    cout<<t.a[0]<<endl;
    return 0;
}