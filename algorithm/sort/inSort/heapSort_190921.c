//最小堆排序
#include<stdio.h>

void swap(int *a, int *b)
{
	if (a == b)	return ;
	*a = *b ^ *a;
	*b = *b ^ *a;
	*a = *b ^ *a;	
	return ;
}

//堆调整，调整start节点
void heapAdjust(int *heap, int start, int end)
{
	int j = start * 2;

	while(j <= end)
	{
		if (j < end && heap[j] > heap[j+1])j++;
		if (heap[start] < heap[j]) break;
		swap(heap+start, heap+j);
		start = j;
		j = j * 2;
	}
	
	return;
}

//堆排序
void heapSort(int *heap, int heapSize)
{
	int start = heapSize/2, end = heapSize;

	while(start > 0)
	{
		heapAdjust (heap, start, heapSize);
		--start;
	}

	//排序
	for (start = 1; start <= end; )
	{
		swap(heap+start, heap+end);
		--end;
		heapAdjust (heap, start, end);
	}

	for(start = 1, end = heapSize; start < end;)
	{
		swap(heap+start, heap+end);
		++start;--end;
	}
	
	return ;
}

void showHeap(int *heap, int heapSize)
{
	int i = 1;
	for (; i < heapSize; ++i)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
	return ;
}

void main()
{
	int seq[] = {-1,10,9,4,0,7,3,1,8,2,3,4,5,5,2,6};
	showHeap (seq, sizeof(seq)/sizeof(int));
	heapSort (seq, sizeof(seq)/sizeof(int) - 1);
	showHeap (seq, sizeof(seq)/sizeof(int));
	return ;
}
