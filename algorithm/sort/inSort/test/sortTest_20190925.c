//测试手写归并排序、堆排序、快速排序
#include <stdio.h>

void showArray(int *nums, int numsSize)
{
	int i = 1;
	for (; i <= numsSize; ++i)
		printf("%d ", nums[i]);
	printf("\n");
	return ;
}

 void swap(int *a, int *b)
{
	if (a == b)	return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	return ;
}

//大顶堆排序
void maxHeapAdjust(int *heap, int start, int end)
{
	int j = start * 2;

	while (j < end)
	{
		if (j < end && heap[j] < heap[j+1])j++;
		if (heap[j] > heap[start])
		{
			swap (heap+start, heap+j);
			start = j; j *= 2;
		}
		else
			break;
	}
	return ;
}

//最大堆排序
void maxHeapSort(int *heap, int heapSize)
{
	int i = heapSize / 2, end = heapSize;

	if (heap == NULL || heapSize < 2)	return ;

	for (; i > 0; --i)
	{
		maxHeapAdjust (heap, i, end);
	}

	while (end > 1)
	{
		swap (heap+1, heap+end);
		maxHeapAdjust (heap, 1, --end);
	}

	return ;
}

//快速排序
void qSort(int *nums, int start, int end)
{
	int mid = start + (end-start)/2, left = start, right = end, val;
	if (start >= end)	return ;
	//printf("start:%d, end:%d\n", start, end);	
	val = nums[mid];

	while (left < right)
	{
		while (mid < right && nums[right] >= val)	--right;
		if (mid < right)
		{
			swap (nums+mid, nums+right);
			mid = right;
		}
		
		while (left < mid && nums[left] <= val)	++left;
		if (left < mid)
		{
			swap (nums+left, nums+mid);
			mid = left;
		}		
	}
	//printf("start:%d, left :%d, end:%d\n", start, left, end);	
	qSort (nums, start, mid-1);
	qSort (nums, mid+1, end);
	return ;
}

void quickSort(int *nums, int numsSize)
{
	if (nums == NULL || numsSize < 2)	return ;
	qSort (nums, 0, numsSize);

	return ;
}

//归并排序
void mergeSort(int *nums, int *tmp, int start, int end)
{
	int i,j,k, left = start, right = end, mid = start + (end-start)/2;

	if (start >= end)	return ;

	mergeSort (nums, tmp, left, mid);
	mergeSort (nums, tmp, mid+1, right);	

	//合并
	for(i=k=start,j=mid+1; i <= mid && j <= end;)
	{
		if (nums[i] > nums[j])
			tmp[k++] = nums[j++];
		else
			tmp[k++] = nums[i++];
	}

	while (i <= mid)
	{
		tmp[k++] = nums[i++];
	}
	while (j <= end)
	{
		tmp[k++] = nums[j++];
	}	
	for (i = start; i <= end; ++i)
		nums[i] = tmp[i];

	return ;
}

void main()
{
	int nums[] = {-1,15,10,1,4,3,5,2,6,9,8,7,14,12,13,11};
	//int nums[] = {-1,10,15,7,1,3,9,8,11,14,6,11,12,2,4,5,13};
	int tmp[100] = {0};

	showArray (nums, sizeof(nums)/sizeof(int)-1);
	//printf("快速排序：\n");
	//quickSort (nums, sizeof(nums)/sizeof(int)-1);

	//printf("归并排序：\n");
	//mergeSort (nums, tmp, 0, sizeof(nums)/sizeof(int)-1);

	printf("大顶堆排序：\n");	
	maxHeapSort (nums, sizeof(nums)/sizeof(int)-1);
	showArray (nums, sizeof(nums)/sizeof(int)-1);
	return ;
}
