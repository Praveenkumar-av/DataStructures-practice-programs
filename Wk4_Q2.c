// Given the head of a linked list and a value x, partition it such that all nodes less than x
// come before nodes greater than or equal to x. You should preserve the original relative order of
// the nodes in each of the two partitions.

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void partition(int);
void addList();
int length();
void display();

void main()
{
	int n, i, num, x;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the values :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display();
	
	printf("Enter the value of x to partition :");
	scanf("%d",&x);
	partition(x);
	display();
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

void partition(int x)
{
	int n = length();
	if(n == 0)
		printf("List empty!");
	else
	{
		struct Node *tempPrev = NULL;
		if(head->a > x)		// check if first Node is greater than x
		{
			temp = head;
			while(temp->next != NULL)
			{
				tempPrev = temp;
				temp = temp->next;
				if(temp->a < x)
				{
					tempPrev->next = head;
					head = head->next;
					tempPrev->next->next = temp->next;
					temp->next = head;
					head = temp;
					break;
				}
			}
		}
		// Swap remaining Nodes
		struct Node *lastMod = head;
		temp = head;
		int i, flag = 0;
		for(i=0;i<n-1;i++)
		{
			tempPrev = temp;
			temp = temp->next;
			if(temp->a == x)
				flag = 1;
			if(temp->a < x && flag==1)
			{
				tempPrev->next = temp->next;
				temp->next = lastMod->next;
				lastMod->next = temp;
				lastMod = temp;
				temp = tempPrev;
			}
		}
	}
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
