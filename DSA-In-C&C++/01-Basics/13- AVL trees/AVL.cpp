#include<iostream>
using namespace std;


class Node
{
    public:
        Node* lchild;
        int data;
        int height;
        Node* rchild;
};


class AVL
{
    private:
        Node* root;

    public:
        AVL(){root = nullptr;}
        Node* RInsert(Node* p, int key);
        int NodeHeight(Node* p);
        int BalanceFactor(Node* p);
        Node* LLRotation(Node* p);
        Node* LRRotation(Node* p);
        Node* RRRotation(Node* p);
        Node* RLRotation(Node* p);
        void Inorder(Node* p);
};

int AVL::NodeHeight(Node* p)
{
    int h1, h2;

    h1 = (p && p->lchild) ? p->lchild->height : 0;
    h2 = (p && p->rchild) ? p->rchild->height : 0;

    return h1 > h2 ? h1 + 1 : h2 + 1;
}

int AVL::BalanceFactor(Node* p)
{
    int h1, h2;

    h1 = (p && p->lchild) ? p->lchild->height : 0;
    h2 = (p && p->rchild) ? p->rchild->height : 0;

    return h1 - h2;   
}

Node* AVL::LLRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root)
        root = pl;

    return pl;
}

Node* AVL::LRRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = p;
    plr->lchild = pl;
    

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(p == root)
        root = plr;

    return plr;
}

Node* AVL::RRRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(p == root)
        root = pr;

    return pr;
}

Node* AVL::RLRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(p == root)
        root = prl;

    return prl;
}

Node* AVL::RInsert(Node* p, int key)
{
    Node* t;
    if(p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = nullptr;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << " | " << flush;
        Inorder(p->rchild);
    }
}

int main()
{
    AVL tree;
    Node* root = nullptr;
    root = tree.RInsert(root, 10);

    root = tree.RInsert(root, 20);
    root = tree.RInsert(root, 30);
    root = tree.RInsert(root, 25);
    root = tree.RInsert(root, 28);
    root = tree.RInsert(root, 27);
    root = tree.RInsert(root, 5);

    

    tree.Inorder(root);

    root = tree.RInsert(root, 4);
    root = tree.RInsert(root, 3);
    root = tree.RInsert(root, 1);

    cout<<endl;

    tree.Inorder(root);



}