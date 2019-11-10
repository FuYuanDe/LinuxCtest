#include <stdio.h>

void showArray(int *arr, int numSize)
{
	int i = 0;
	while (i < numSize)
		printf("%d ", arr[i++]);
	printf("\n");	
}



#define LT(a,b) ((a) < (b) ? 1 : 0) 

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void heapAdjust(int *heap, int s, int m)
{
	int j;
	
	//堆中序号从1开始,在线性数组中，下标从0开始。
	int v = heap[s-1];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && LT (heap[j-1], heap[j])) ++j;
		if (!LT (v, heap[j-1])) break;
		heap[s-1] = heap[j-1];
		s = j;
	}
	heap[s-1] = v;
}

void heapSort(int *heap, int numsSize)
{
	int i;
	for (i = numsSize/2; i >= 1; --i)
		heapAdjust (heap, i, numsSize);
	
	for (i = numsSize; i > 0; --i)
	{
		//交换首尾
		swap (heap, heap + i - 1);
		heapAdjust (heap, 1, i - 1);
	}
}


void main()
{
	int arr[] = {9, 1, 5, 8, 7, 0, 2, 3, 6, 4};
	int numsSize = (sizeof(arr)/sizeof(int));

	showArray ((int *)arr, numsSize);
	heapSort ((int *)arr, numsSize);
	showArray ((int *)arr, numsSize);
}
