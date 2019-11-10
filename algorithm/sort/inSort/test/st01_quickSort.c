/*
 *	手写快速排序测试,非递归版本
 *  20190822
 */
#include <stdio.h>

void swap(int *a, int *b)
{
	if (a == b)	return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int quickSort(int *nums, int begin, int end) 
{
	int pivot, i = begin, j = end;

	pivot = nums[i];

	while (i < j)
	{
		
		while (j > i && nums[j] >= pivot)j--;
		if (j > i)
			swap (nums+j, nums+i);
		else
			break;
		while (i < j && nums[i] <= pivot)i++;
		if (i < j)
			swap (nums+j, nums+i);
		else
			break;		
	}

	return i;
}

void showArray(int *nums, int numsSize)
{
	int i = 0;
	while (i < numsSize)
		printf("%d ", nums[i++]);
	printf("\n");
	return ;
}

void main()
{
	int top = 0, low = 0, high, pivot, stack[100] = {0};
	int nums[] = {10,3,1,8,4,5,2,9,8,6,5};
	int size = sizeof(nums)/sizeof(int);
	high = size - 1;
	
	showArray (nums, size);
	pivot = quickSort (nums, 0, size - 1);
	
	if (pivot - 1 > low)
	{
		stack[top++] = pivot - 1;
		stack[top++] = low;
	}

	if (pivot + 1 < high)
	{
		stack[top++] = high;
		stack[top++] = pivot + 1;
	}

	while (top > 0)
	{
		low = stack[--top];
		high = stack[--top];
		pivot = quickSort (nums, low, high);

		if (pivot - 1 > low)
		{
			stack[top++] = pivot - 1;
			stack[top++] = low;
		}
		
		if (pivot + 1 < high)
		{
			stack[top++] = high;
			stack[top++] = pivot + 1;
		}
	}
	
	showArray (nums, size);
}

