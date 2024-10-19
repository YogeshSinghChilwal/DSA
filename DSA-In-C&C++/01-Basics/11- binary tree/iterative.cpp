#include<iostream>

#include"stack.h"

using namespace std;

class Tree
{
    public:
        Node* root;
        Tree() {root = nullptr;}
        void createTree();
        void preorder(Node* r);
        void inorder(Node* r);
        void postorder(Node* r);
        void leverorder(Node* r);
        Node* getRoot();
        int Height(Node* r);
        
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(20);
    cout<<"Enter root value: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while( !q.isEmpty())
    {
        p = q.dequeue();

        cout<<"Enter left child value of "<<p->data<<" : ";
        cin>>x;
        if( x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter right child value of "<<p->data<<" : ";
        cin>>x;
        if( x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node* r)
{
    Stack st(20);
    while(r != nullptr || !st.isEmptyStack())
    {
        if(r != nullptr)
        {
            cout<<r->data<<" | ";
            st.push(r);
            r = r->lchild;
        }
        else
        {
            r = st.pop();
            r = r->rchild;
        }
    }
}

void Tree::inorder(Node *r)
{
    Stack st(20);
    while(r != nullptr || !st.isEmptyStack())
    {
        if(r != nullptr)
        {
            st.push(r);
            r = r->lchild;
        }
        else
        {
            r = st.pop();
            cout<<r->data<<" | ";
            r = r->rchild;
        }
    }
}

void Tree::postorder(Node *r)
{
    Stack st(20);
    long int temp;
    while(r != nullptr || !st.isEmptyStack())
    {
        if(r != nullptr)
        {
            st.push(r);
            r = r->lchild;
        }
        else
        {
            temp = (long int)st.pop();
            if(temp > 0)
            {
                st.push((Node*)-temp);
                r = ((Node*)temp)->rchild;
            }
            else
            {
                cout<<((Node*)-temp)->data<<" | ";
                r = nullptr;
            }
        }
    }
}

void Tree::leverorder(Node *p) {
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
        if (p->lchild){
            cout << p->lchild->data << " | " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild){
            cout << p->rchild->data << " | " << flush;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node* r)
{
    int x = 0;
    int y = 0;
    if(r == 0)
        return 0;
    x = Height(r->lchild);
    y = Height(r->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}


Node* Tree::getRoot()
{
    return root;
}

int main()
{

    Tree t;
    t.createTree();
    t.preorder(t.getRoot());
    cout<<endl;
    t.postorder(t.getRoot());
    cout<<endl;
    // cout<<t.Height(t.getRoot());
    return 0;
}