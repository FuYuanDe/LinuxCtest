/*
 *	归并排序
 * 	20190822
 */

#include <stdio.h>

void mergeSort(int *arr1, int start, int end, int *arr2)
{
	int i,j,k, mid;
	
	if (start >= end)
		return ;

	mid = (start + end) / 2;

	mergeSort(arr1, start, mid, arr2);
	mergeSort(arr1, mid+1, end, arr2);

	for (k = i = start, j = mid + 1; i <= mid && j <= end;)
	{
		if (arr1[i] < arr1[j])
			arr2[k++] = arr1[i++];
		else
			arr2[k++] = arr1[j++];
	}
	if (i <= mid)
	{
		while(i <= mid)
			arr2[k++] = arr1[i++];
	}
	
	if (j <= end)
	{
		while(j <= end)
			arr2[k++] = arr1[j++];
	}	

	//复制到原始数组
	for (i = start; i < k; i++)
		arr1[i] = arr2[i];

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
	int size, nums[] = {10,5,8,2,3,9,4,2,6,7,1};
	int nums2[20] = {0};

	size = sizeof(nums)/sizeof(int);
	showArray(nums, size);
	mergeSort(nums, 0, size - 1,nums2);
	showArray(nums, size);
}
