/* Given a linked list of size N. The task is to reverse every k nodes (where k is an input to
the function) in the linked list. If the number of nodes is not a multiple of k then left-out
nodes, in the end, should be considered as a group and must be reversed.
Example 1:
Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Example 2:
Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Expected TimeComplexity: O(n)  */

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*head = NULL, *temp = NULL;

struct Node *create();
void addList();
void reverse(int);
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
	reverse(k);
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

void reverse(int k)
{
	int n = length(), i;
	if(n > 1)
	{
		struct Node *tempPrev, *tempNext, *add, *first;
		tempPrev = head;
		temp = head->next;
	
		for(i=1;i<k && temp != NULL;i++)
		{
			tempNext = temp->next;
			temp->next = tempPrev;
			tempPrev = temp;
			temp = tempNext;
		}
		add = head;
		head->next = NULL;
		head = tempPrev;
		
		for(i=k+1;i<n;i++)
		{
			if(i%k == 1)
			{
				first = tempNext;
				first->next = NULL;
				tempPrev = tempNext;
				temp = tempNext->next;
			}
			else
			{
				tempNext = temp->next;
				temp->next = tempPrev;
				tempPrev = temp;
				temp = tempNext;
			}
			if(i%k == 0)
			{
				add->next = tempPrev;
				add = first;
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
