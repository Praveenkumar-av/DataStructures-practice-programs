// Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value
// to each the array element between two given indices, inclusive. Once all operations have been
// performed, return the maximum value in the array.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n, *arr, q, i, **queries, j, start, end, max, val;
    printf("Enter the size of array :");
    scanf("%d",&n);
    printf("Enter the no. of queries :");
    scanf("%d",&q);

    arr = (int *)calloc(n,sizeof(int));
    queries = (int **)calloc(q,sizeof(int *));
    for(i=0;i<q;i++)
        queries[i] = (int *)calloc(3,sizeof(int));

    for(i=0;i<q;i++)
        for(j=0;j<3;j++)
            scanf("%d",&queries[i][j]);

    for(i=0;i<q;i++)
    {
        start = queries[i][0]-1;
        end = queries[i][1];
        val = queries[i][2];
        for(j=start;j<end;j++)
        {
            arr[j] += val;
        }
    }

    max = arr[0];
    for(i=1;i<n;i++)
        if(arr[i] > max)
            max = arr[i];

    printf("Max :%d",max);
}