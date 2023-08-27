#include<stdio.h>
void main()
{
	int n, arr[100]={0}, k, i=0, j=0, dist=1, temp=0;
	printf("Enter no. of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the value of k :");
	scanf("%d",&k);
	
	// check if k is less than size of array
	if(k>n+1)
	{
		printf("k is greater than length of array!\n");
	}
	
	// checking duplicate elements
	for(i=0;i<n;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				dist=-1;
				break;
			}
		}
	}
	if(dist==-1)
	printf("Array contains duplicate elements\n");
	else
	{
		// sorting the array upto k th element
		for(i=0;i<k;i++)
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
		printf("k th smallest element is %d",arr[k-1]);
	}
}
