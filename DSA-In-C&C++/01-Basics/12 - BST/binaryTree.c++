#include<iostream>
#include<climits>
#include"stack.h"
using namespace std;


class BST
{
    private:
        Node* root;
    
    public:
        BST(){root = nullptr;}
        Node* getRoot(){ return root;}
        void insert(int key);
        void inorder(Node* p);
        Node* search(int key);
        Node* RInsert(Node* p, int key);
        Node* Delete(Node* p, int key);
        int height(Node* p);
        Node* inPre(Node* p);
        Node* inSuc(Node* p);
        Node* create(int* arr, int size);

};

void BST::insert(int key)
{
    Node*t = root;
    Node*p;
    Node*r;
    
    if(root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while(t != nullptr)
    {
        r = t;
        if(t->data > key)
            t = t->lchild;
        else if(t->data < key)
            t = t->rchild;
        else
            return;
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;

    if(r->data > key)
        r->lchild = p;
    else
        r->rchild = p;
}

void BST::inorder(Node* p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" | ";
        inorder(p->rchild);
    }
}

Node* BST::search(int key)
{
    Node* t = root;
    while (t != nullptr)
    {
        if(t->data == key)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else 
            t = t->rchild;
    }
    return nullptr;
}

Node* BST::RInsert(Node* p, int key)
{
    Node* t;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

int BST::height(Node* p)
{
    int x, y;
    if(p == nullptr)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);

    return x > y ? x + 1 : y + 1;
}

Node* BST::inPre(Node* p)
{
    while(p  && p->rchild != nullptr)
        p = p->rchild;
    return p;
}

Node* BST::inSuc(Node* p)
{
    while(p  && p->lchild != nullptr)
        p = p->lchild;
    return p;
}

Node* BST::Delete(Node* p, int key)
{
    Node* q;

    if(p == nullptr)
        return nullptr;

    if(p->lchild == nullptr && p->rchild == nullptr && p->data == key)
    {
        if(p == root)
            root = nullptr;

        delete p;
        return nullptr;
    }

    if(key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = inSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

Node* BST::create(int* arr, int size)
{
    if(size <= 0)
        return nullptr;

    int i = 0, m;
    Stack st(100);
    Node* root;
    Node* p;
    Node* t;

    root = new Node;
    root->data = arr[i++];
    root->lchild = root->rchild = nullptr;
    p = root;

    while(i < size)
    {
        if(arr[i] < p->data)
        {
            st.push(p);
            t = new Node;
            t->data = arr[i++];
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            p = t;
        }
        else{
            if(arr[i] > p->data && arr[i] < (st.isEmptyStack() ? 32767 : st.stackTop()->data))
            {
                t = new Node;
                t->data = arr[i++];
                t->rchild = t->lchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = st.pop();
            }
        }
    }

    return root;

}

int main()
{
    BST bin;
    Node* root;

    // root = bin.RInsert(bin.getRoot(), 40);
    // bin.RInsert(root , 30);
    // bin.RInsert(root , 20);
    // bin.RInsert(root , 10);
    // bin.RInsert(root , 50);
    // bin.RInsert(root , 60);
    // bin.RInsert(root , 70);
    // bin.RInsert(root , 45);
    // bin.RInsert(root , 35);

    // bin.inorder(root);
    // cout<<endl;

    // bin.Delete(root, 50);
    // bin.inorder(root);

    int arr[] = {40, 30, 20, 10, 35, 45, 60, 70};
    int ar[] = {30, 20, 10, 25, 40, 35, 43};

    root = bin.create(ar, 7);

    bin.inorder(root);
    cout<<endl;


}