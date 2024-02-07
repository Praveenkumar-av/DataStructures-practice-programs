// Program to print the root nodes of tree

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL;

struct Node *create(int);
struct Node *insert(struct Node *,int);
void inorder(struct Node *);
void printRoot(struct Node *);

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

    printf("Inorder traversal :");
    inorder(root);

    printf("\nRoot nodes :");
    printRoot(root);
}

void printRoot(struct Node *temp)
{
    if(temp != NULL)
    {
        if(temp->left == NULL && temp->right == NULL)
        {
            printf("%d ",temp->data);
        }
        else 
        {
            printRoot(temp->left);
            printRoot(temp->right);
        }
    }
}

struct Node *create(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *insert(struct Node *temp, int value)
{
    if(temp == NULL)
    {
        return create(value);
    }
    else 
    {
        if(value < temp->data)
        {
            temp->left = insert(temp->left,value);
        }
        else
        {
            temp->right = insert(temp->right,value);
        }
        return temp; 
    }
}

void inorder(struct Node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}
