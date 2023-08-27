//	Find the majority element in the array. A majority element in an array A[] of size n is an element
// that appears more than n/2 times (and hence there is at most one such element). 

#include<stdio.h>

void main()
{
	int arr[100], n, i, maj = 0;
	
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int flag = majority(arr,n,&maj);
	
	if(flag == 1)
	{
		printf("Majority element :%d",maj);
	}
	else
	{
		printf("Majority element not found!");
	}
}

int majority(int *arr,int n,int *maj)
{
	int i, j, count = 1;
	for(i=0;i<n;i++)
	{
		count =1 ;
		for(j=i+1;j<n;j++)
		{
			if(arr[i] == arr[j])
			{
				count++;
				if(count > n/2)
				{
					*maj = arr[i];
					return 1;
				}
			}
		}
	}
	return -1;
}
