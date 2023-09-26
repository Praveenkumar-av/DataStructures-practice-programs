/* Given two linked lists, insert nodes of second list into first list at alternate positions of first
list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list
should become 5->12->7->10->17->2->13->4->11->6 and second list should become
empty. The nodes of second list should only be inserted when there are positions
available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then
first list should become 1->4->2->5->3->6 and second list to 7->8.
Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion
must be done in-place. Expected time complexity is O(n) where n is number of nodes in
first list.  */
// Using Singly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next;
}*list1 = NULL, *list2 = NULL, *temp = NULL;

struct Node *create();
void addList(struct Node **,int);
void insertAlternate();
void display(struct Node *);

void main()
{
	int n1, n2, i, num, M, N;
	printf("Enter the no. of elements of list 1:");
	scanf("%d",&n1);
	printf("Enter the elements of list 1:");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&num);
		addList(&list1,num);
	}
	
	printf("Enter the no. of elements of list 2:");
	scanf("%d",&n2);
	printf("Enter the elements of list 2 :");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&num);
		addList(&list2,num);
	}
	printf("\nList 1 :");
	display(list1);
	printf("List 2 :");
	display(list2);

	insertAlternate();
	printf("List 1 :");
	display(list1);
	printf("List 2 :");
	display(list2);
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

void addList(struct Node **headAddr,int num)
{
	if((*headAddr) == NULL)
	{
		(*headAddr) = create();
		(*headAddr)->a = num;
	}
	else
	{
		temp = (*headAddr);
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create();
		temp->next->a = num;
	}
}

void insertAlternate()
{
	if(list1 == NULL)
	{
		printf("\nList 1 is empty\n");
	}
	else if(list2 == NULL)
	{
		printf("\nList 2 is empty\n");
	}
	else
	{
		struct Node *temp1;
		temp1 = list1;
		while(temp1 != NULL && list2 != NULL)
		{
			temp = temp1->next;
			temp1->next = list2;
			list2 = list2->next;
			temp1->next->next = temp;
			temp1 = temp;
		}
	}
}

void display(struct Node *temp)
{
	if(temp == NULL)
	{
		printf("List empty!");
	}
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
