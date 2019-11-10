/*
 *	大顶堆排序并输出
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
		if (j < (e+1) && heap[j-1] < heap[j])j++;
		if (heap[j-1] <= key)	break;
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

	//顺序调整
	for (i = numsSize-1; i > 0; i--)
	{
		swap(nums+i, nums);
		
		heapAdjust (nums, 0, i-1);
		//showArray (nums, numsSize);

	}
}

//插入堆
void heapInsert(int *heap, int e, int val)
{

    int f;
    f = (e+1) / 2;
	printf("e:%d, heap[0]:%d\n", e, heap[0]);
	
    if (e == 1)
    	heap[e-1] = val;
    else
    {
		while (f>1)
		{
			printf("val:%d, f:%d\n", val, heap[f-1]);
			if (val > heap[f-1])
			{
				swap(heap+e, heap+f-1);
				e = f; f = e / 2;
			}
			else
				break;
		}
		heap[e-1] = val;
    }

    return;
}

void main()
{
	int arr[20] = {0};
	int i = 0, size,v;
	for (size = 0, i = 0; i < 15; i++)
	{
		printf("input value:"); scanf("%d", &v);
		size++;
		heapInsert(arr, size, v);
		showArray (arr, size);
		//heapAdjust (arr, size);
		heapSort(arr, size);
		showArray (arr, size);		
	}
	
	return ;
}
