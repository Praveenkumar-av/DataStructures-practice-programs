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
void boundaryTraversal(struct Node *);
void leftBoundary(struct Node *);
void leafNodes(struct Node *);
void rightBoundary(struct Node *);

void main()
{
    // example 1
    root = create(1);
    root->left = create(2);
    root->right = create(3);

    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);

    root->left->right->left = create(8);
    root->left->right->right = create(9);

    // example 2
    // root = create(1);
    // root->left = create(2);
    // root->left->left = create(4);
    // root->left->right = create(9);
    // root->left->left->left = create(6);
    // root->left->left->right = create(5);
    // root->left->right->right = create(3);
    // root->left->right->right->left = create(7);
    // root->left->right->right->right = create(8);

    boundaryTraversal(root);
}

void boundaryTraversal(struct Node *root)
{
    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root->right);
}

void leftBoundary(struct Node *temp)
{
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
            return;

        printf("%d ", temp->data);
        if (temp->left == NULL)
            leftBoundary(temp->right);
        else
            leftBoundary(temp->left);
    }
}

void leafNodes(struct Node *temp)
{
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            printf("%d ", temp->data);
            return;
        }
        else
        {
            leafNodes(temp->left);
            leafNodes(temp->right);
        }
    }
}

void rightBoundary(struct Node *temp)
{
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
            return;

        if (temp->right == NULL)
            leftBoundary(temp->left);
        else
            leftBoundary(temp->right);

        printf("%d ", temp->data);
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