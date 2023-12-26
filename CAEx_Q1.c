// finding the lowest common ancestor of two nodes in tree

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
}*root=NULL;

struct Node *create(int);
struct Node *insert(struct Node *,int);
void preorder(struct Node *);

void main()
{
    int n, num, i;
    printf("Enter the no. of elements :");
    scanf("%d",&n);

    printf("Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root = insert(root,num);   
    }
    preorder(root);
}

struct Node *create(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *insert(struct Node *temp,int value)
{
    if(temp == NULL)
        return create(value);
    else 
    {
        if(value < temp->data)
            temp->left = insert(temp->left,value);
        else
            temp->right = insert(temp->right,value);
        return temp;
    }    
}

void preorder(struct Node *temp)
{
    if(temp != NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}