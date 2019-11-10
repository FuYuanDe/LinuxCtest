/*
 * 简单选择排序
 * 找最小的数放在最前面。
 */

#include <stdio.h>

#define MIN(a,b)	((a) <= (b) ? (a) : (b))

void showArray(int *arr, int numSize)
{
	int i = 0;
	printf("\n");	
	while (i < numSize)
		printf("%d ", arr[i++]);
	printf("\n");	
}

//两数交换
void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

//简单选择排序
void selectSort(int *arr, int numsSize)
{
	int i, j, minLoc, minValue;
	minValue = arr[0];
	
	for (i = 0; i < numsSize - 1; i++)
	{
		//保存当前最小值及所在位置
		minLoc = i;
		minValue = arr[i];

		//查找最小值
		for (j = i + 1; j < numsSize; j++)
		{
			if (minValue > arr[j])
			{
				minValue = arr[j];
				minLoc = j;
			}			
		}

		//保存
		if (i != minLoc)
			swap (arr + i, arr + minLoc);
	}
}

void main()
{
	int arr[] = {9, 8, 1, 7, 5, 2, 6, 4, 3,43,55,26,18,28,31,17,65,48};
	showArray (arr, sizeof(arr)/sizeof(int));
	selectSort (arr, sizeof(arr)/sizeof(int));
	showArray (arr, sizeof(arr)/sizeof(int));
}
