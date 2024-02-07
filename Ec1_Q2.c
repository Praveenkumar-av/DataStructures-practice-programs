#include<stdio.h>

int maxSum(int *,int);

void main()
{
    int n, i, arr[50];

    printf("Enter the no. of values :");
    scanf("%d",&n);

    printf("Enter the values :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Maximum sum :%d",maxSum(arr,n));
}

int maxSum(int *arr,int n)
{
    int sum = 0, max = 0, i;

    for(i=0;i<n;i++)
    {
        sum += arr[i];

        if(sum > max)
            max = sum;

        if(sum < 0)
            sum = 0;
    }

    return max;
}
