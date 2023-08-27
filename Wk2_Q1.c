// 	Given an unsorted array of integers, sorr[0..n-1] :Given an unsorted array of integers, sort the array into a wave array. 
// An array arr[0..n-1] is sorted in wave form if: arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..


#include<stdio.h>

void main()
{
	int arr[50], i=0, j=0, n, temp, n2;
	printf("Enter the no. of values :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	if(n%2 == 0)
	{
		n2=n-1;
	}
	else
	{
		n2=n-2;
	}
	
	for(i=0;i<n2;i+=2)
	{
		printf("%d\n",i);
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
