//	Given an array arr[] of integers and a number x, the task is to find the smallest subarray with a sum greater than the given value. 

#include<stdio.h>

void subArray1(int *,int,int,int *,int*);
void subArray2(int *,int,int,int *,int*);

void main()
{
	int arr[50], i=0, n, x;
	printf("Enter the no. of values :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the value of x :");
	scanf("%d",&x);
	
	int start=0, end=0;
	
	subArray2(arr,n,x,&start,&end);
	
	printf("Sub array :");
	for(i=start;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	
}

void subArray1(int *arr,int n,int x,int *start,int *end)  // smallest sub array based on sum of elements
{
	int i, j, sumprev=0, sum=0;
	for(i=0;i<n;i++)
	{
		sum = arr[i];
		for(j=i+1;j<n;j++)
		{
			sum+=arr[j];
			if(sum>x && sum<sumprev)
			{
				sumprev = sum;
				*start = i;
				*end = j;
				printf("i = %d, j = %d\n",i,j);
				break;
			}
			else if( i == 0 && sum > x )
			{
				sumprev = sum;
				*start = i;
				*end = j;
				break;
			}
		}
	}
}

void subArray2(int *arr,int n,int x,int *start,int *end)  // smallest sub array based on size
{
	int i, j, prevsize=n, size = 0, sum=0;
	
	for(i=0;i<n;i++)
	{
		sum = arr[i];
		for(j=i+1;j<n;j++)
		{
			sum+=arr[j];
			if(sum>x)
			{
				size = j - i + 1;
				if(size < prevsize)
				{
					prevsize = size;
					*start = i;
					*end = j;
					break;
				}
			}
		}
	}
}
