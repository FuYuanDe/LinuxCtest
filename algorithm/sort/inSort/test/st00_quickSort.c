/*
 *	手写快速排序测试
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

void quickSort(int *nums, int begin, int end) 
{
	int pivot, i = begin, j = end;
	if (end <= begin)
		return;
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
	quickSort (nums, begin, i-1);
	quickSort (nums, i+1, end);
	return ;
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
	int nums[] = {-1,10,15,7,1,3,9,8,11,14,6,11,12,2,4,5,13};
	int size = sizeof(nums)/sizeof(int);

	showArray (nums, size);
	quickSort (nums, 0, size - 1);
	showArray (nums, size);
}
