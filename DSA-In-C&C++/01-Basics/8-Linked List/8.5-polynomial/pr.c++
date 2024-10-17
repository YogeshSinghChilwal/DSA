#include<iostream>
#include<cmath>
using namespace std;

class Node
{
    public:
        int coeff;
        int exp;
        Node* next;
};

class Polynomial
{
    private:
        Node* polly = nullptr;

    public:
        Polynomial(int num);
        void Display();
        double Exponent(int x);
};

Polynomial::Polynomial(int num)
{
    Node *last = nullptr, *t;
    for(int i = 0; i < num; i++)
    {
        t = new Node;

        cout<<"Enter coefficient and exponent "<<i + 1<<": ";

        cin>>t->coeff>>t->exp;
        t->next = nullptr;

        if(polly == nullptr)
        {
            polly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Polynomial::Display()
{
    Node *p = polly;
    while(p)
    {
        if(p->next != nullptr)
            cout<<p->coeff<<"x^"<<p->exp<<" + ";
        else
            cout<<p->coeff<<"x^"<<p->exp;
        p = p->next;
    }
    cout<<endl;
}

double Polynomial::Exponent(int x)
{
    Node *p = polly;
    double sum = 0;
    while(p)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;
    Polynomial poly(n);
    poly.Display();

    cout<<"\n Enter value of x: ";
    int x;
    cin>>x;

    cout<<"\n Exponent is: "<<poly.Exponent(x)<<endl;

    return 0;
}