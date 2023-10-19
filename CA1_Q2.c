// Implement a first in first out (FIFO) queue using only two stacks. The implemented
// queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Operations to be performed are as follows: void push(int x) Pushes element x to the
// back of the queue. int pop() Removes the element from the front of the queue and
// returns it. int peek() Returns the element at the front of the queue. boolean empty()
// Returns true if the queue is empty, false otherwise.
//
// Input Format
// size of the stack list of operations and values to be pushed
// Constraints
// Accept all integers between 1 to 500
// Output Format
// [Elements in the stack, separated by spaces]
// Sample Input 0
// 7
// ["Queue","push","push","pop","pop","push","pop"]
// [0,51,65,0,0,72,0]
// Sample Output 0
// [51,65,72]

#include<stdio.h>
#include<string.h>

int n=50;
int st1[50], st2[50], top1=-1, top2=-1;

void enqueue(int);
int dequeue();
int peek();
void push(int *,int *,int);
int pop(int *,int *);

void main()
{
    int n, i, num, result[50];
    printf("Enter the no. of elements :");
    scanf("%d",&n);
    char op[50][10];
    int arr[50];

    printf("Enter the operations :");
    for(i=0;i<n;i++)
    {
        scanf("%s",op[i]);
    }

    printf("Enter the values :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int r = -1;
    for(i=0;i<n;i++)
    {
    	if(strcmp(op[i],"push") == 0)
    	{
    		enqueue(arr[i]);
		}
		else if(strcmp(op[i],"pop") == 0)
		{
			r++;
			result[r] = dequeue();
		}
		else if(strcmp(op[i],"peek") == 0)
		{
			r++;
			result[r] = peek();
		}
	}
	
	for(i=0;i<=r;i++)
	{
		printf("%d ",result[i]);
	}

}

void enqueue(int num)
{
    int temp;  // store the value
    int i;
    // copy the elements from stack 2 to stack 1
    top1 = -1;
    while(top2 >= 0)
    {
        temp = pop(st2,&top2);
        push(st1,&top1,temp);
    }

    // push the given element
    push(st1,&top1,num);

    // copy the elements of stack 1 to stack 2
    top2 = -1;
    while(top1 >= 0)
    {
        temp = pop(st1,&top1);
        push(st2,&top2,temp);
    }
}

int dequeue()
{
    if(top2 == -1)
    {
        return -1;
    }

    int num = pop(st2,&top2);
    return num;
}

int peek()
{
	if(top2 == -1)
		return -1;
	
	return st2[top2];
}

void push(int *st,int *top,int num)
{
    if(*top >= n-1)
    {
        printf("Stack full!");
    }
    else
    {
        (*top)++;
        st[*top] = num;
    }
}

int pop(int *st,int *top)
{
    if(*top == -1)
        return -1;
    else 
    {
        int num = st[*top];
        (*top)--;
        return num;
    }
}
