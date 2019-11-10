/*
 *	小顶堆排序并输出
 *	堆的下标始于1
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	if (a == b)
		return;
	else
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;		
	}
}
void showArray(int *arr, int numSize)
{
	int i = 0;
	while (i < numSize)
		printf("%d ", arr[i++]);
	printf("\n");	
}

//下标从0开始
void heapAdjust(int *heap, int s, int e)
{
	int i,j,key = heap[s];

	for (j = 2*(s+1); j <= (e+1); j*=2)
	{
		if (j < (e+1) && heap[j-1] > heap[j])j++;
		if (heap[j-1] >= key)	break;
		heap[s] = heap[j-1];	s = j-1;
	}
	heap[s] = key;
	return;
}


//堆排序
void heapSort(int *nums, int numsSize)
{
	int i = 0;
	for (i = numsSize/2 - 1; i >= 0; i--)
		heapAdjust (nums, i, numsSize - 1);
		
	showArray (nums, numsSize);

	//顺序调整
	for (i = numsSize-1; i > 0; i--)
	{
		swap(nums, nums+i);
		heapAdjust (nums, 0, i-1);
	}
}


void main()
{
	int arr[] = {10,9,4,5,2,8,6,7,1,0,3,5};

	showArray (arr, sizeof(arr)/sizeof(int));
	heapSort (arr, sizeof(arr)/sizeof(int));
	showArray (arr, sizeof(arr)/sizeof(int));	
	return ;
}
