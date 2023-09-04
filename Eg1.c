// C program to find the loop Node in an linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList(int);
void referPosition(int,int);
int findPosition(int);
void display(int,int);

void main()
{
	int n, i, num;
	printf("Enter the number of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	
	display(n,0);
	
	int pos;
	printf("\nEnter the position to refer :");
	scanf("%d",&pos);
	referPosition(pos,n);
	display(n,1);
	
	pos = findPosition(n);
	printf("\nPosition is %d",pos);
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

void referPosition(int pos,int n)  // sets the reference of given position node to the last->next
{
	if(head == NULL)
		printf("List empty!");
	else if(pos>n)
		printf("invalid\n");
	else
	{
		struct Node *temp2 = NULL;
		temp = head;
		int i;
		for(i=1;i<n;i++)
		{
			if(i == pos)
			{
				temp2 = temp;
			}
			temp = temp->next;
		}
		temp->next = temp2;
	}
}

int findPosition(int n)  // returns the position of node which the last node->next is pointing
{
	if(head == NULL)
	{
		printf("list empty!");
	}
	else
	{
		int count;
		struct Node *temp2;
		temp = head->next;
		while(1)
		{
			count = 0;
			temp2 = head;
			while(temp2 != temp)
			{
				count++;
				if(temp->next == temp2)
				{
					return count;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
	}
}

void display(int n,int run)
{
	int i, j=0;
	temp = head;
	for(i=0;i<n;i++)
	{
		printf("%d ",temp->a);
		temp = temp->next;
	}
	if(run==1)
	{
		while(j<2)
		{
			for(i=0;i<n;i++)
			{
				printf("%d ",temp->a);
				temp = temp->next;
				j++;
			}
			printf("\n");
		}
	}
}
