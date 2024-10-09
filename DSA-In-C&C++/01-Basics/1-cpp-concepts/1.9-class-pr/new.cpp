#include<iostream>
using namespace std;

class Rectangle{
private:
    int length;
    int breadth;

public:
    Rectangle(){
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
    int area(){
        return length * breadth;
    }
    int perimeter(){
        return 2 * (length + breadth); // corrected the formula for perimeter
    }
    void setLength(int l){
        length = l;
    }
    void setBreadth(int b){
        breadth = b;
    }
    int getLength(){ // corrected the member function name
        return length;
    }
    int getBreadth(){
        return breadth;
    }
    ~Rectangle(){
        cout<<"Destructor";
    }
};

int main(){

    Rectangle r;

    cout<<r.getLength();

    return 0;
}
