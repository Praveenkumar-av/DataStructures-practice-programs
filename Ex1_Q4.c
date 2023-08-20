#include<stdio.h>
void main()
{
	int arr[100]={0}, n, index=-1 ,i=0;
	printf("Enter the no. of values");
	scanf("%d",&n);
	printf("Enter the array elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	// finding peak element
	for(i=1;i<n-1;i++)
	{
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
		{
			index=i;
			break;
		}
	}
	if(index==-1)
	{
		printf("Peak element does not exists in the given array!");
	}
	else
	{
		printf("Index of Peak element is %d",index);
	}
}
