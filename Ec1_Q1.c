//Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing
//number from the first N integers.

#include<stdio.h>
int find(int *,int);

void main()
{
    int n, i, arr[50];

    printf("Enter n :");
    scanf("%d",&n);

    printf("Enter the values :");
    for(i=0;i<n-1;i++)
        scanf("%d",&arr[i]);

    int num = find(arr,n);
    printf("\nMissing number :%d",num);

}

int find(int *arr,int n)
    // Time complexity : O(n)
{
    int sum=0, total=0, missnum;
    total = (n*(n+1))/2;

    for(int i=0;i<n-1;i++)
        sum += arr[i];

    missnum = total - sum;

    return missnum;
}
