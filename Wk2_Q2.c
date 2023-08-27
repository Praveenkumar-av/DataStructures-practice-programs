//	Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. 
// If there is such a triplet present in array, then print the triplet and return true. Else return false.

#include<stdio.h>

int triplet(int *,int,int,int *);

void main()
{
	int arr[50], i=0, n, count=0, value, trip;
	printf("Enter the no. of values :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the value :");
	scanf("%d",&value);
	
	int result = triplet(arr,n,value,&trip);
	
	if(result == 1)
	{
		printf("Triplet :%d",trip);
	}
	else
	{
		printf("False");
	}	
}

int triplet(int *arr,int n,int value,int *trip)
{
	int i, j, count=0, sum=0;
	for(i=0;i<n;i++)
	{
		sum=arr[i];
		count = 1;
		for(j=i+1;j<n;j++)
		{
			if(arr[i] == arr[j] && count<=3)
			{
				count++;
				sum+=arr[j];
				if(sum == value && count == 3)
				{
					*trip = arr[i];
					return 1;
				}
			}
		}
	}
	return 0;
}
