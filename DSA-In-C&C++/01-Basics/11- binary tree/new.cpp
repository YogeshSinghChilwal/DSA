#include<iostream>


#include <stdio.h>
#include <stdlib.h>

// Tree Structure
struct Tree
{
    struct Tree *lchild;
    int data;
    struct Tree *rchild;
} *root = NULL;
 
//Queue Structure
struct Queue
{
    struct Tree *qdata; //Store the address of Tree
    struct Queue *next;
} *front = NULL, *rear = NULL;
 
void enQueue(struct Tree *x)
{
    struct Queue *t;
    t = (struct Queue *)malloc(sizeof(struct Queue));
    if (t == NULL)
    {
        printf("Queue is Full!");
    }
    else
    {
        t->qdata = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t; //When the queue doesn't exist
        }
        else
        {
            rear->next = t; //Insert from rear
            rear = t;
        }
    }
}
struct Tree *deQueue()
{
    struct Tree *x;
    struct Queue *t;
    if (front == NULL)
    {
        printf("Queue is Empty!");
    }
    else
    {
        t = front;
        x = t->qdata;
        front = t->next;
        free(t);
    }
    return x;
}
 
int isQueueEmpty()
{
    return front == NULL;
}

 
struct Stack
{
    long int sdata; //Stack Data , Stores the address of each node. It's in long int format beacuse we need to store negative address.
    struct Stack *next;
} *top = NULL;
 
void push(long int x)
{
    struct Stack *t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    if (top == NULL)
    {
        t->sdata = x;
        t->next = NULL;
        top = t;
    }
    else
    {
        t->sdata = x;
        t->next = top;
        top = t;
    }
}
//Returns the address of a node of tree
long int pop()
{
    long int x;
    struct Stack *t;
    x =top->sdata;
    t = top->next;
    free(top);
    top = t;
    return x; //Returns the address of Node
}
 
int isStackEmpty()
{
    return top == NULL;
}
 




 void createTree()
{
    struct Tree *p, *t;
    int x;
    printf("Enter The Value of Root : ");
    scanf("%d", &x);
    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enQueue(root);
    while (!isQueueEmpty())
    {
        p = deQueue(); //pop the item from queue and link it to lchild and rchild
        printf("Enter the left child of %d :  ", p->data);
        scanf("%d", &x);
        //Check for leaf node
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enQueue(t); //Insert the address of lchild in queue
        }
        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enQueue(t);
        }
    }
}
 
//Traversal using Recursion
 
void preOrder(struct Tree *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
 
void inOrder(struct Tree *p)
{
    if (p)
    {
 
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}
 
void postOrder(struct Tree *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}
 
//Traversal Using Iteration
void IPreOrder(struct Tree *p)
{
    long int temp;
 
    while (p || !isStackEmpty())
    {
        if (p)
        {
            printf("%d ", p->data);
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Tree *)temp;
            p = p->rchild;
        }
    }
}
 
void IInOrder(struct Tree *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {
 
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            p = (struct Tree *)temp;
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}
 
void IPostOrder(struct Tree *p)
{
    long int temp;
    while (p || !isStackEmpty())
    {
        if (p)
        {
            push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = pop();
            if (temp > 0)
            {
                push(-temp);
                p = (struct Tree *)temp;
                p = p->rchild;
            }
            else
            {
                p = (struct Tree *)-temp;
                printf("%d ", p->data);
                p = NULL;
            }
        }
    }
}
 
int main()
{
    createTree();
    printf("\nPreorder Traversal is : ");
    IPreOrder(root);
    printf("\n");
    printf("\nInorder Traversal is : ");
    IInOrder(root);
    printf("\n");
    printf("\nPostorder Traversal is : ");
    IPostOrder(root);
    printf("\n");
    return 0;
}