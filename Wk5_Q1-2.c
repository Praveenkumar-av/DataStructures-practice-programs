// Given a linked list and two integers M and N. Traverse the linked list such that you retain M
// nodes then delete next N nodes, continue the same till end of the linked list.
// Using doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node *create();
void addList(int);
void removeNode(int,int);
int length();
void display();

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
	
	printf("Enter M :");
	scanf("%d",&M);
	printf("Enter N :");
	scanf("%d",&N);
	removeNode(M,N);
	display();
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	n->prev = NULL;
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
		temp->next->prev = temp;
		temp->next->a = num;
	}
}

void removeNode(int M,int N)
{
	int n = length();
	
	if(n == 0)
		printf("List is empty!");
		
	else if(N == 0 || M == 0)
		printf("Invalid Input!\n");
		
	else if(N+M <= n)
	{
		int i, j;
		temp = head;
		for(i=1;i<=n-N-M+1;i += N+M)
		{
			for(j=1;j<=M;j++)
			{
				temp = temp->next;
			}
			for(j=1;j<=N;j++)
			{
				temp->prev->next = temp->next;
				if(temp->next != NULL) 
				{
					temp->next->prev = temp->prev;
				}
				temp = temp->next;
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
		printf("List empty!\n");
		
	else
	{
		temp = head;
		while(temp != NULL)
		{
			printf("%d ",temp->a);
			temp = temp->next;
		}
	}
}
