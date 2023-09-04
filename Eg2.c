// Datastructures in C to concatenate numbers in each Node of two linked list and find the sum of these.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
	int a;
	struct Node *next;
};

struct Node *create();
void addList();
int concat(struct Node *);
void display();

void main()
{
	struct Node *list1 = NULL, *list2 = NULL;
	int n, i, num;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the elements of list 1:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(&list1,num);
	}
	printf("Enter the elements of list 2:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		addList(&list2,num);
	}
	
	display(list1);
	display(list2);
	
	int num1, num2, sum;
	num1 = concat(list1);
	num2 = concat(list2);
	sum = num1 + num2;
	printf("Sum is %d",sum);
}

struct Node *create()
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

void addList(struct Node **head,int num)
{
	if(*head == NULL)
	{
		*head = create();
		(*head)->a = num;
	}
	else
	{
		struct Node *temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create();
		temp->next->a = num;
	}
}

int concat(struct Node *temp)
{
	int add = 0, nd;
	while(temp != NULL)
	{
		nd = log10(temp->a)+1;
		add = (add*pow(10,nd))+temp->a;
		temp = temp->next;
	}
	return add;
}

void display(struct Node *temp)	// printing in the output console
{
	if(temp == NULL)
	{
		printf("List is empty!\n");
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
