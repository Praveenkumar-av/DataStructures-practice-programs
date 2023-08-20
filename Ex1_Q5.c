#include<stdio.h>
void main()
{
	int arr[100]={0}, n ,i=0, index=-1, j=0;
	printf("Enter the no. of values");
	scanf("%d",&n);
	printf("Enter the array elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	// finding the repeating element 
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				index=i;
				break;
			}
		}
	}
	if(index==-1)
	{
		printf("Repeating element not found!");
	}
	else 
	{
		printf("Index of first occurence of repeating element :%d",index);
	}
}
