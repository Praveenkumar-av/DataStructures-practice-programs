// Given a linked list, swap every two adjacent nodes and return its head. You must solve the 
// problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList();
void swap();
int length();
void display();

void main()
{
	int n, i, num;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the values :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display();
	
	swap();
	display();
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

void swap()
{
	if(head == NULL)
	{
		printf("List empty!\n");
	}
	else
	{
		int n = length();
		if(n>=2)
		{
			// swap first two Nodes
			temp = head->next;
			head->next = temp->next;
			temp->next = head;
			head = temp;
			
			// swap remaining Nodes
			if(n>3)
			{
				struct Node *tempprev = head->next;
				int i;
				for(i=2;i<n-1;i+=2)
				{
					temp = tempprev->next;
					tempprev->next = temp->next;
					temp->next = tempprev->next->next;
					tempprev->next->next = temp;
					tempprev = temp;
				}
			}
		}
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

