// Given a singly linked list, swap kth node from the beginning with kth node from the
// end, Write a program to perTorm swap operation using pointers, For instance when
// Linked List is: 12345678 and k-2, output is 87234521  when k-3, output is 87645321

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *temp;

void swapKth(int);
struct Node *create(int);
void addList(int);
void display();
int length();

void main()
{
    int n, i, num, k;
    printf("Enter the no. of elements :");
    scanf("%d",&n);

    printf("Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        addList(num);        
    }

    printf("k :");
    scanf("%d",&k);

    display();

    swapKth(k);
    display();
}

void swapKth(int k)
{
    int i=1, j;
    struct Node *temp1, *temp2, *temp1Prev, *temp2Prev;
    int n = length();
    while(i<=k)
    {
        temp1 = head;
        temp1Prev = NULL;
        for(j=1;j<i;j++)
        {
            temp1Prev = temp1;
            temp1 = temp1->next;
        }

        temp2 = head;
        temp2Prev = NULL;
        for(j=1;j<=n-i;j++)
        {
            temp2Prev = temp2;
            temp2 = temp2->next;
        }

        if(temp1 == head)
        {
            temp2->next = head->next;
            temp2Prev->next = head;
            temp2Prev->next->next = NULL;
            head = temp2;
        }
        else 
        {
            temp = temp2Prev->next;
            temp2Prev->next = temp1Prev->next;
            temp1Prev->next = temp;
            temp = temp1Prev->next->next;
            temp1Prev->next->next = temp2Prev->next->next;
            temp2Prev->next->next = temp;
        }

        i++;
    }
}

struct Node *create(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->next = NULL;
    n->data = val;
    return n;
}

void addList(int val)
{
    if(head == NULL)
    {
        head = create(val);
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = create(val);
    }
}

void display()
{
    if(head == NULL)
    {
        printf("List empty!");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int length()
{
    if(head == NULL)
        return 0;
    
    temp = head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}