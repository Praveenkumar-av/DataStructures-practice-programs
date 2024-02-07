// Given a singly linked list, rotate the linked list counter-clockwise by 'k' nodes.
// where k is a given positive integer

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList();
int length();
void display();

void main()
{
	int n, i, num, k;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the values :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display();
	
	printf("Enter k :");
	scanf("%d",&k);
    rotate(k);
	
	display();
}

void rotate(int k)
{
    int n = length();
    if(n == 0)
    {
        printf("List empty!");
        return;
    }
    int i;
    
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    // using circular singly list method
    temp->next = head;

    for(i=0;i<k;i++)
        head = head->next;

    temp = head;
    while(temp->next != head)
        temp = temp->next;

    temp->next = NULL;

    // by moving node to last node
	
    // for(i=0;i<k;i++)
    // {
    //     temp->next = head;
    //     head = head->next;
    //     temp->next->next = NULL;
    //     temp = temp->next;
    // }
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

void addList(int num)
{
	if(head == NULL)
	{
		head = create();
		head->a = num;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create();
		temp->next->a = num;
	}
}

int length()
{
	if(head == NULL)
		return 0;
	else
	{
		int count = 0;
		temp = head;
		while(temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
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
			printf("%d ",temp->a);
			temp = temp->next;
		}
		printf("\n");
	}
}
