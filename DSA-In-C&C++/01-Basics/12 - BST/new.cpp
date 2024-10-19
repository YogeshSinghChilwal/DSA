
#include <iostream>

#include <stack>

using namespace std;



class Node{

public:

Node *lchild;

Node *rchild;

int data;

};



class BST{

private:

Node *root;

Node* RInsert(Node*,int);

public:

BST(){root=NULL;}

void Insert(int);

Node* Search(int);

void Inorder(Node *p);

void Inorder(){Inorder(root);}

int Height(Node *p);

void CreatePre(int*,int);

};



void BST::Insert(int key){

if(root==NULL){

Node *p=new Node;

p->lchild=NULL;

p->rchild=NULL;

p->data=key;

root=p;

cout<<"Inserted "<<key<<endl;

return;

}

Node *t=root;

Node *r; //tailing pointer

while(t){

if(t->data==key) return;

r=t;

if(t->data<key){

t=t->rchild;

}

else if(t->data>key){

t=t->lchild;

}

}

Node *p=new Node;

p->data=key;

p->lchild=NULL;

p->rchild=NULL;

if(r->data>key){

r->lchild=p;

}

else r->rchild=p;

cout<<"Inserted "<<key<<endl;

}



void BST::Inorder(Node *p){

if(p){

Inorder(p->lchild);

cout<<p->data<<" ";

Inorder(p->rchild);

}

}



Node* BST::Search(int key){

Node *temp=root;

while(temp){

if(key==temp->data) return temp;

if(key<temp->data) temp=temp->lchild;

else temp=temp->rchild;

}

return NULL;

}



int BST::Height(Node *p){

int x,y;

if(!p) return -1;

x=Height(p->lchild);

y=Height(p->rchild);

if(x>y){

return x+1;

}

else return y+1;

}



void BST::CreatePre(int* pre,int n){

stack<Node*> stk;

int i=0;

Node *p,*t;

root=new Node;

root->data=pre[i++];

root->lchild=root->rchild=NULL;

p=root;

while(i<n){

if(pre[i]<p->data){

stk.push(p);

t=new Node;

t->data=pre[i++];

t->lchild=t->rchild=NULL;

p->lchild=t;

p=t;

}

else{

if(pre[i]>p->data && (pre[i]<stk.top()->data || stk.empty())){

t=new Node;

t->data=pre[i++];

t->lchild=t->rchild=NULL;

p->rchild=t;

p=t;

}

else{

p=stk.top();

stk.pop();

}

}

}

}



int main(){

BST b;

int A[]={20,10,5,15,12,25};

b.CreatePre(A,6);

b.Inorder();

return 0;

}