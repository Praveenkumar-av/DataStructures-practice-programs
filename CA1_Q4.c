// The span of the stock's price in one day is the maximum number of consecutive days
// (starting from that day and going backward) for which the stock price was less than or
// equal to the price of that day. For example, if the prices of the stock in the last four days
// is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because
// starting from today, the price of the stock was less than or equal 2 for 4 consecutive
// days. Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the
// stock today is 8, then the span of today is 3 because starting from today, the price of the
// stock was less than or equal 8 for 3 consecutive days.

// Input Format
// Number of values in the list List of values
// Constraints
// Accept all values as integers
// Output Format
// a list representing the span for stock each day
// Sample Input 0
// 7
// [100, 80, 60, 70, 60, 75, 85]

// Sample Output 0
// [1,1,1,2,1,4,6]

#include<stdio.h>
#include<stdlib.h>

int *span(int *,int);

void main()
{
    int n, i;
    printf("Enter the no. of values :");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the values :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int *result = span(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
}

int *span(int *arr,int n)
{
    int *result = (int *)malloc(n*sizeof(int));
    int i,j, count;
    for(i=0;i<n;i++)
    {
        count = 1;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j] > arr[i])
            {
                break;
            }
            count++;
        }
        result[i] = count;
    }
    return result;
}