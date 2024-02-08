#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *arr, n, i, **result, j, temp, flag=0, k;
    printf("Enter the size :");
    scanf("%d",&n);

    arr = (int *)calloc(n,sizeof(int));
    printf("Enter the elements :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter k :");
    scanf("%d",&k);

    for(i=1;i<n;i++)
    {
        for(j=i;j>=0 && arr[j] < arr[j-1];j--)
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    for(i=0;i<n;i+=3)
    {
        if((arr[i+1]-arr[i] > k) || (arr[i+2]-arr[i+1] > k) || (arr[i+2]-arr[i] > k))
        {
            flag = 1;
            break;
        }
    }

    if(!flag)
    {
        for(i=0;i<n;i++)
        {
            if (i % 3 == 0)
                printf("\n");
            printf("%d ",arr[i]);
        }
    }
}