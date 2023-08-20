#include<stdio.h>
void main()
{
	int n, i=0, invalid=0, unsort=0, total=0;
	printf("Enter n :");
	scanf("%d",&n); 
	total= (n*(n+1))/2;  // total sum of n natural numbers
	n=n-1;
	int arr[100]={0};
	printf("Enter %d elements :",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	i=0;
	while(i<n-1)
	{
		// check if element is greater than n or less than 0
		if(arr[i]>n+1 || arr[i]<=0)  
		{
			invalid=1;
		}
		// check whether array is sorted
		if(arr[i]<arr[i+1])  
		{
			i++;
		}
		else
		{
			unsort=1;
			i++;
		}
	}
	if(arr[n-1]>n+1 || arr[n-1]<=0)  // checking the last element
	{
		invalid=1;
	}
	if(unsort==1 || invalid==1)
	{
		if(unsort==1)
		{
			printf("Array is unsorted!\n");
		}
		if(invalid==1)
		{
			printf("Array contains element greater than n or less than 0");
		}
	}
	else
	{
		//  subtracting the array elements from total
		for(i=0;i<n;i++)
		{
			total-=arr[i];
		}
		printf("Missing element is %d",total);
	}
}
