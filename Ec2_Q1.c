// Given a Binary Tree. Find the Zig - Zag Level Order Traversal of the Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL, *temp = NULL;

struct Node **st1, **st2;
int top1 = -1, top2 = -1;

void zigzag(struct Node *);
struct Node *create(int);
struct Node *insert(struct Node *, int);
void push(int, struct Node *);
struct Node *pop(int);
int isStackEmpty(int);

void main()
{
    int n, i, num;
    printf("Enter the size :");
    scanf("%d", &n);

    printf("Enter the values :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        root = insert(root, num);
    }

    st1 = (struct Node **)calloc(n, sizeof(struct Node *));
    st2 = (struct Node **)calloc(n, sizeof(struct Node *));

    printf("\nZig zag traversal :");
    zigzag(root);
}

void zigzag(struct Node *temp)
{
    int forward = 1;
    if (temp == NULL)
        return;

    push(2, temp);

    while (!isStackEmpty(1) || !isStackEmpty(2))
    {
        if (forward)
        {
            // prints the values in forward direction
            temp = pop(2);
            printf("%d ", temp->data);
            if (temp->left != NULL)
                push(1, temp->left);
            if (temp->right != NULL)
                push(1, temp->right);

            if (isStackEmpty(2))
            {
                forward = 0;
            }
        }
        else
        {
            // prints the values in backward direction
            temp = pop(1);
            printf("%d ", temp->data);
            if (temp->right != NULL)
                push(2, temp->right);
            if (temp->left != NULL)
                push(2, temp->left);

            if (isStackEmpty(1))
            {
                forward = 1;
            }
        }
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

struct Node *insert(struct Node *temp, int val)
{
    if (temp == NULL)
        return create(val);
    else
    {
        if (val < temp->data)
            temp->left = insert(temp->left, val);
        else
            temp->right = insert(temp->right, val);

        return temp;
    }
}

void push(int s, struct Node *temp)
{
    if (s == 1)
    {
        top1++;
        st1[top1] = temp;
    }
    else
    {
        top2++;
        st2[top2] = temp;
    }
}

struct Node *pop(int s)
{
    struct Node *temp;
    if (s == 1)
    {
        temp = st1[top1];
        top1--;
    }
    else
    {
        temp = st2[top2];
        top2--;
    }
    return temp;
}

int isStackEmpty(int s)
{
    if (s == 1)
    {
        if (top1 == -1)
            return 1;
        else
            return 0;
    }
    else
    {
        if (top2 == -1)
            return 1;
        else
            return 0;
    }
}
