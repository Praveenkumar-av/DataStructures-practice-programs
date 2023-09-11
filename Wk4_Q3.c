
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList();
void removeFirst();
void deleteNode(int);
int length();
void display();

void main()
{
	int n, i, num, pos;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the values :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display();
	
	printf("Enter the position to remove from last :");
	scanf("%d",&pos);
	deleteNode(pos);
	display();
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

void removeFirst()
{
	if(head == NULL)
	{
		printf("List empty!");
	}
	else if(head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		head = head->next;
	}
}

void deleteNode(int pos)
{
	int n = length(), flag = 0;
	if(n == 0)
		printf("List empty!\n");
	if(pos > n || pos < 1)
		printf("Invalid position!\n");
	else
	{
		if(pos == n)
		{
			removeFirst();
			flag = 1;
		}
		else
		{
			int i;
			struct Node *tempPrev;  // to store the previous node address
			n -= pos;
			temp = head;

			for(i=1;i<=n;i++)
			{
				tempPrev = temp;
				temp = temp->next;
			}
			tempPrev->next = temp->next;
			flag = 1;
		}
		if(flag == 0)
			printf("Element not found!\n");
		else
			printf("Element removed\n");
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
