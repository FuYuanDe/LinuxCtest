//堆排序
#include<stdio.h>

void swap(int *a, int *b)
{
	if (a == b)	return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;	
	return ;
}

void showArray(int *array, int numsSize)
{
	int i = 0;
	while (i < numsSize)
	{
		printf("%d ", array[i]);
		++i;
	}
	printf("\n");
	return ;
}

//最小堆调整
void minHeapAdjust(int *heap, int start, int end)
{
	int j = start * 2;

	while(j <= end)
	{
		if(j < end && heap[j] > heap[j+1])j++;
		if (heap[start] > heap[j])
		{
			swap (heap+start, heap+j);
			start = j; j = 2 * start;
		}
		else
			break;
	}
	return ;
}

//最小堆排序
void minHeapSort(int *heap, int heapSize)
{
	int node = heapSize/2, end = heapSize, start = 1;
	if (!heap || heapSize < 2)	return ;

	//堆调整
	for(;node > 0; --node)
	{
		minHeapAdjust (heap, node, heapSize);
	}

	//堆排序
	for(;end>1;--end)
	{
		swap (heap+1, heap+end);
		minHeapAdjust (heap, 1, end-1);
	}

	//调整位置
	for(start = 1, end = heapSize; start < end; ++start, --end)
		swap (heap+start, heap+end);

	return ;
}

//最大堆调整
void maxHeapAdjust(int *heap, int start, int end)
{
	int j = start * 2;

	while (j <= end)
	{
		if (j < end && heap[j] < heap[j+1])j++;
		if (heap[j] > heap[start])
		{
			swap (heap+j, heap+start);
			start = j; j = start * 2;
		}
		else
			break;
	}
	
	return ;
}

//最小堆排序
void maxHeapSort(int *heap, int heapSize)
{
	int start = 1, end = heapSize, node = heapSize/2;

	if (!heap || heapSize < 2)	return ;

	//堆调整
	while(node > 0)
	{
		maxHeapAdjust (heap, node, end);
		--node;
	}

	//showArray (heap, heapSize+1);
	
	//堆排序
	for (; end > 1; --end)
	{
		swap (heap+1, heap+end);
		maxHeapAdjust (heap, 1, end-1);
	}
	return ;
}

//快速排序
void qSort(int *arr, int start, int end)
{
	int key, left = start, right = end;

	if (left >= right)	return ;

	//printf("left:%d, right:%d\n", left, right);
	
	key = arr[start];

	while (left < right)
	{
		while (left < right && arr[right] >= key) right--;
		if (left < right) 
		{
			swap(arr+left, arr+right);
			++left;
		}
		while (left < right && arr[left] <= key) left++;
		if (left < right) 
		{
			swap(arr+left, arr+right);
			--right;
		}
	}
	
	//printf("left:%d, right:%d\n", left, right);
	qSort(arr, start,left-1);
	qSort(arr, left+1, end);
	
	return ;
}

void quickSort(int *nums, int numsSize)
{
	if (!nums || numsSize < 2)	return ;
	qSort (nums, 0, numsSize);
	return ;
}

//归并排序
void mergeSort(int *nums, int *tmp, int start, int end)
{
	int mid, left = start, right = end, i, j, k;

	if (!nums || start >= end)	return ;

	mid = left + (right - left)/2;

	mergeSort (nums, tmp, left, mid);
	mergeSort (nums, tmp, mid+1, right);

	//合并
	for (k = i = left, j = mid+1; i <= mid && j <= right;)
	{
		if (nums[i] < nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}

	while (i <= mid)
		tmp[k++] = nums[i++];
	while (j <= right)
		tmp[k++] = nums[j++];

	for (i = left; i <= right; i++)
		nums[i] = tmp[i];
	return ;	
}


void main()
{
	int seq[] = {-1,10,15,7,1,3,9,8,11,14,6,11,12,2,4,5,13};
	int tmp[100] = {0};

	printf("排序前：");
	showArray (seq, sizeof(seq)/sizeof(int));
	//最小堆排序
	//minHeapSort (seq, sizeof(seq)/sizeof(int)-1);
	//最大堆排序
	//maxHeapSort (seq, sizeof(seq)/sizeof(int)-1);

	//快速排序
	//quickSort (seq, sizeof(seq)/sizeof(int)-1);

	//归并排序
	mergeSort (seq, tmp, 0, sizeof(seq)/sizeof(int)-1);
	printf("排序后：");
	showArray (seq, sizeof(seq)/sizeof(int));

	return ;
}
