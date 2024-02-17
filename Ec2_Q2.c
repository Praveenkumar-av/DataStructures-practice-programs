// Given a binary tree.Find the size of its largest subtree that is a Binary Search Tree.
// Note : Here Size is equal to the number of nodes in the subtree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL, *temp = NULL;

int max = 0;

struct Node *create(int);
void inorder(struct Node *);
void largestBst(struct Node *,int);

void main()
{
    root = create(6);
    root->left = create(6);
    root->right = create(3);
    root->right->left = create(9);
    // root->left->left = create(3);
    root->left->right = create(2);
    root->right->right = create(3);
    // root->left->left->left = create(2);
//    root->left->left->right = create(4);
    root->left->right->right = create(8);
    root->right->left->left = create(8);
    root->right->left->right = create(2);

    // printf("%d ",root->data);
    // inorder(root);

    largestBst(root,1);
    printf("Largest BST : %d", max);
}

void largestBst(struct Node *temp,int bst)
{
	static int count = 0;
    if(!bst) 
        count = 0;

    bst = 0;

    if (temp != NULL)
    {
        if (temp->left != NULL && temp->right != NULL)
        {
            if (temp->left->data < temp->data && temp->right->data >= temp->data)
                bst = 1;
        }
        else if (temp->left != NULL)
        {
            if (temp->left->data < temp->data)
                bst = 1;
        }
        else if (temp->right != NULL)
        {
            if (temp->right->data >= temp->data)
                bst = 1;
        }
        else
        {
            bst = 1;
        }

        if (bst)
        {
            count++;         
        }
            
        largestBst(temp->left,bst);
        largestBst(temp->right,bst);
    }
    else 
    {
        if (count > max)
            max = count;
    }
}

struct Node *create(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->left = NULL;
    n->right = NULL;
    n->data = val;
    return n;
}

void inorder(struct Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
