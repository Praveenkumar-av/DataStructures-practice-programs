#include<stdio.h>
void main()
{
	int arr[100]={0}, n, invalid=0, i=0, j=0, temp=0;
	printf("Enter the no. of values");
	scanf("%d",&n);
	printf("Enter the array elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	// check whether the array has other elements than 0,1,2
	for(i=0;i<n;i++)
	{
		if(arr[i]<0 || arr[i]>2)
		{
			invalid=1;
			break;
		}
	}
	if(invalid==1)
	{
		printf("Enter only 0, 1 and 2\n");
	}
	else 
	{
		// sorting the array
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(arr[j]<arr[i])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		
		// printing
		for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
	}
}
