// Given a linked list and two integers M and N. Traverse the linked list such that you retain M
// nodes then delete next N nodes, continue the same till end of the linked list.
// Using Singly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList();
void removeNode(int,int);
int length();
void display();

void main()
{
	int n, i, num, M, N;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the values :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(num);
	}
	display();
	
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

void removeNode(int M,int N)
{
	int n = length();
	
	if(n == 0)
		printf("List is empty!");
		
	else if(N == 0 || M == 0)
		printf("Invalid Input!\n");
		
	else if(N+M <= n)
	{
		int i, j, k;
		struct Node *tempPrev = NULL;
		temp = head;
		for(i=1;i<=n-N-M+1;i += N+M)
		{
//			for(j=1;j<=N+M;j++)
//			{
//				if(j<=M)
//				{
//					tempPrev = temp;
//					temp = temp->next;
//				}
//				else
//				{
//					tempPrev->next = temp->next;
//					temp = temp->next;
//				}
//			}
			
			for(j=1;j<=M;j++)
			{
				tempPrev = temp;
				temp = temp->next;
			}
			for(j=1;j<=N;j++)
			{
				tempPrev->next = temp->next;
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
