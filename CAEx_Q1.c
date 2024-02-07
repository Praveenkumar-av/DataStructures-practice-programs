// finding the lowest common ancestor of two nodes in tree

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
}*root=NULL;

int findAncestor(struct Node *,int,int);
struct Node *create(int);
struct Node *insert(struct Node *,int);
void preorder(struct Node *);

void main()
{
    int n, num, i, val1, val2, result;
    printf("Enter the no. of elements :");
    scanf("%d",&n);

    printf("Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root = insert(root,num);   
    }
    preorder(root);

    printf("\nEnter the value 1 and value 2 :");
    scanf("%d%d",&val1,&val2);
    result = findAncestor(root,val1,val2);
    printf("Lowest common ancestor is :%d\n",result);

}

int findAncestor(struct Node *temp,int val1, int val2)
{
    static int result = 0;
    
    if(temp == NULL)
        return result;
    
    if(val1 < temp->data && val2 < temp->data)
    {
        return findAncestor(temp->left,val1,val2);
    }
    else if(val1 > temp->data && val2 > temp->data)
    {
        return findAncestor(temp->right,val1,val2);
    }
    else 
    {
        result = temp->data;
        return result;
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