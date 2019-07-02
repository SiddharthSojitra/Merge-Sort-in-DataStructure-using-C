#include<stdio.h>

mergesort(int arr[], int size)
{
	int *temp = (int *)malloc(size*sizeof(int));
	msort(arr, temp, 0, size-1);
	free(temp);
}

msort(int arr[], int temp[], int start, int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;
		msort(arr, temp, start, mid);
		msort(arr, temp, mid+1, end);
		merge(arr, temp, start, mid+1, end);
	}
}

merge(int arr[], int temp[], int starta, int startb, int endb)
{
	int aptr = starta;
	int bptr = startb;
	int idx = starta;
	int i;
	while(aptr < startb && bptr < endb+1)
	{
		if(arr[aptr] < arr[bptr])
		{
			temp[idx++] = arr[aptr++];
		}
		else 
		{
			temp[idx++] = arr[bptr++];
		}
	}
	while(aptr < startb)
	{
		temp[idx++] = arr[aptr++];
	}
	while(bptr < endb+1)
	{
		temp[idx++] = arr[bptr++];
	}
	for(i = starta; i <= endb; i++)
	{
		arr[i] = temp[i];
	}
}

void main()
{
	int n, i, j, k, temp;
	printf("\n How many elements want to insert : ");
	scanf("%d",&n);
	int t[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element %d :",i+1);
		scanf("%d",&t[i]);
	}
	
        mergesort(t,n);        
	
        for(i=0 ; i<n ; i++)
        {       printf("%d",t[i]);    }
}
