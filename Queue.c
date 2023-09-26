// Queue implementation using array in C

#include<stdio.h>

void enqueue(int);
void deque();
void peek();

int arr[50], n=50, front = -1, rear = -1;

void main()
{
	int choice, num;
	do
	{
		printf("Enter the choice 1 to Enqueue, 2 to Dequeue, 3 to peek and 0 to exit :");
		scanf("%d",&choice)	;
		switch(choice)
		{
			case 1:
				printf("Enter the element to push :");
				scanf("%d",&num);
				enqueue(num);
				break;
				
			case 2:
				deque();
				break;
			
			case 3 :
				peek();
				break;
			
			default :
				if(choice != 0)
					printf("Invalid choice!\n");
		}
	}while(choice != 0);
}

void enqueue(int num)
{
	// add element to the last
	if(front == -1)
	{
		front++;
		rear++;
		arr[front] = num;
	}
	else if(rear >= n-1)
	{
		printf("Queue full!\n");
	}
	else
	{
		rear++;
		arr[rear] = num;
	}
}

void deque()
{
	// fetch element in the front and delete
	if(front > rear || front == -1)
	{
		printf("Queue empty!\n");
	}
	else
	{
		printf("%d\n",arr[front]);
		front++;
	}
}

void peek()
{
	// fetch element in the front
	if(front > rear || front == -1)
	{
		printf("Queue empty!\n");
	}
	else
	{
		printf("%d\n",arr[front]);
	}
}
