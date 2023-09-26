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
// Using Doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int a;
	struct Node *next, *prev;
} *list1, *last1, *list2, *last2, *temp;

void insertAlternate();
void addList(struct Node **,struct Node **,int);
void display(struct Node *,struct Node *);

void main()
{
	int n1, n2, i, num;
	printf("Enter the no. of values of list1:");
	scanf("%d",&n1);
	printf("Enter the elements :");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&num);
		addList(&list1,&last1,num);
	}
	
	printf("Enter the no. of values of list2:");
	scanf("%d",&n2);
	printf("Enter the elements :");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&num);
		addList(&list2,&last2,num);
	}
	printf("\n1st ");
	display(list1,last1);
	printf("2nd ");
	display(list2,last2);
	
	insertAlternate();
	printf("\n1st ");
	display(list1,last1);
	printf("2nd ");
	display(list2,last2);
}

void insertAlternate()
{
	if(list1 == NULL)
		printf("List 1 empty!\n");
	else if(list2 == NULL)
		printf("List 2 empty!\n");
	else
	{
		struct Node *temp1 = list1, *last;
		while(temp1 != NULL && list2 != NULL)
		{
			temp = temp1->next;
			temp1->next = list2;
			list2->prev = temp1;
			if(temp == NULL)
				last = list2;
					
			list2 = list2->next;
			if(list2 != NULL)
				list2->prev = NULL;
				
			temp1->next->next = temp;
			if(temp != NULL) 
				temp->prev = temp1->next; 
			
			temp1 = temp;
		}
		if(temp1 == NULL)
		{
			last1 = last;
		}
	}
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void addList(struct Node **headAddr,struct Node **lastAddr,int num)
{
	if((*headAddr) == NULL)
	{
		(*headAddr) = create();
		(*headAddr)->a = num;
		(*lastAddr) = (*headAddr);
	}
	else
	{
		temp = (*lastAddr);
		
		temp->next = create();
		temp->next->a = num;
		temp->next->prev = temp;
		(*lastAddr) = temp->next;
	}
}

void display(struct Node *head,struct Node *last)
{
	temp = head;
	if(temp == NULL)
		printf("\nList empty!\n");
	else
	{
		printf("list :");
		while(temp != NULL)
		{
			printf("%d ",temp->a);
			temp = temp->next;
		}
		
		temp = last;
		printf("\nList rev :");
		while(temp != NULL)
		{
			printf("%d ",temp->a);
			temp = temp->prev;
		}
		printf("\n");
	}
}
