//	Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 and m > n. 
// Find the smallest number that is missing from the array. 

#include<stdio.h>

void main()
{
	int arr[100], n, i, flag = 1;
	printf("Enter the no. of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n-1;i++)  // check if array is sorted or not
	{
		if(arr[i] > arr[i+1])
		{
			flag = 0;
		}
	}
	if(flag == 0)
	{
		printf("Array is not sorted!");
	}
	else 
	{
		// finding missing element 
		int num = arr[0];
		for(i=0;i<n;i++)
		{
			if(arr[i] == num)
			{
				num++;
			}
			else 
			{
				printf("Missing element :%d",num);
				break;
			}
		}
	}
}
