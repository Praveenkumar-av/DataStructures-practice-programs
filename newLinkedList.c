// given a reference to the head of a so doubly-linked list and an integer,write a
// function that creates a new DoublyLinkedList having data value K inserted at the
// proper location to maintain the sort.

#include<stdio.h>
#include<stdlib.h>

struct Node *insertList(int);
struct Node *create();
void addList(int);
void display(struct Node *);

struct Node 
{
	int a;
	struct Node *next, *prev;
}*head = NULL, *temp = NULL;

void main()
{
	int n, num, i, M, N;
	printf("Enter no. of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display(head);

    printf("Enter the value to insert :");
    scanf("%d",&num);
	struct Node *list2;
    list2 = insertList(num);
	
	display(list2);
}

struct Node *insertList(int val)
{
    temp = head;
    struct Node *head2=NULL, *last2 = NULL;
    int flag = 0, data;
    if(temp != NULL)
    {
        if(val <= temp->a)
        {
            data = val;
            flag = 1;
        }
        else 
        {
            data = temp->a;
            temp = temp->next;
        }
        head2 = create(data);
        last2 = head2;
    }

    while(temp != NULL)
    {
        if(flag == 0 && val <= temp->a)
        {
            data = val;
            flag = 1;
        }
        else 
        {
            data = temp->a;
            temp = temp->next;
        }

        last2->next = create(data);
        last2->next->prev = last2;
        last2 = last2->next;
    }
    if(flag == 0)
    {
        last2->next = create(val);
        last2->next->prev = last2;
        last2 = last2->next;
    }

    return head2;
}

struct Node *create(int val)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	n->prev = NULL;
    n->a = val;
	return n;
}

void addList(int num)
{
	if(head == NULL)
	{
		head = create(num);
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create(num);
		temp->next->prev = temp;
	}
}

void display(struct Node *temp)
{
	if(temp == NULL)
		printf("List empty!\n");
		
	else
	{
		while(temp != NULL)
		{
			printf("%d ",temp->a);
			temp = temp->next;
		}
        printf("\n");
	}
}
