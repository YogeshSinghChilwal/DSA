#include<iostream>
using namespace std;

class Node
{
    public:
        int col;
        int val;
        Node *next;
};

class Sparse
{
    private:
        int row;
        int col;
        Node** rowArray;
    
    public:
        Sparse(int m, int n);
        void addElement(int m, int n, int v);
        void display();
};


Sparse::Sparse(int m, int n)
{
    row = m;
    col = n;
    rowArray = new Node *[row];

    for(int i = 0; i < row; i++)
        rowArray[i] = nullptr;
}

void Sparse::addElement(int m, int n, int v)
{
    if(m >= row || n >= col || m < 0 || n < 0)
    {
        cout<<"Invalid Position!!"<<endl;
        return;
    }
    
    Node* newNode = new Node;
    newNode->col = n;
    newNode->val = v;
    newNode->next = nullptr;

    if(rowArray[m] == nullptr)
    {
        rowArray[m] = newNode;
    }
    else
    {
        Node* temp = rowArray[m];
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Sparse::display()
{
    Node* p;
    for(int i = 0; i < row; i++)
    {
        p = rowArray[i];
        for(int j = 0; j < col; j++)
        {
            if(p)
            {
                if(j == p->col)
                    {
                        cout<<p->val<<" ";
                        p = p->next;
                    }
                else
                    {
                        cout<<"0 ";
                    }
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int r, c, num;
    cout<<"Enter rows: ";
    cin>>r;
    cout<<"Enter columns: ";
    cin>>c;
    cout<<"Enter number of non-zero elements: ";
    cin>>num;

    Sparse sparseMatrix(r, c);

    for(int i = 0; i < num; i++)
    {
        int m, n, v;
        cout<<"Enter row, column and value of element "<<i + 1<<": ";
        cin>>m>>n>>v;
        sparseMatrix.addElement(m, n, v);
    }

    sparseMatrix.display();

    return 0;
}