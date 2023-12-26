// Design a stack that supports push, pop, peek and retrieving the minimum element in
// constant time. Returns -1 is the stack is empty. You must implement a solution with O(1)
// time complexity for each function.

#include<stdio.h>

int arr[50], n = 50, top = -1, min;

void push(int);
void pop();
void getMin();

void main()
{
	int choice, num;
	do
	{
		printf("Enter 1 to push, 2 to pop, 3 to getMin and 0 to exit :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to push :");
				scanf("%d",&num);
				push(num);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				getMin();
				break;
			
			default :
				if(choice != 0)
					printf("Invalid choice!\n");
		}
	}while(choice != 0);
}

void push(int value)  
{
	// function to insert the element at the top of the stack
    if(top >= n-1)
        printf("Stack full!");
	else if(top == -1)
    {
        top++;
        arr[top] = value;
        min = value;
    }
    else if(value >= min)
    {
        top++;
        arr[top] = value;
    }
    else 
    {
        top++;
        arr[top] = (2*value)-min;
        min = value;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack empty!\n");
    }
    else
    {
        int value = arr[top];
        top--;
        if(value >= min)
        {
            printf("%d\n",value);
        }
        else 
        {
            min = (2*min)-value;
            printf("%d\n",(value+min)/2);
        }
    }
}

void getMin()
{
    if(top == -1)
    {
        printf("Stack empty!\n");
    }
    else
    {
        printf("%d\n",min);
    }
}