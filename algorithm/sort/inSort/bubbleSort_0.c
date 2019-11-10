/*
 * 冒泡排序
 */
#include <stdio.h>

//两个数值互换
void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

//冒泡排序
void bubbleSort(int *arr, int numsSize)
{
	int i, j, v;
	for (i = numsSize - 1; i > 0; i--)
	{
		for (j = 0;j < i; j++)
		{
			if (arr[j] > arr[j+1])
				swap (arr+j, arr+j+1);
		}
	}
}

void showArray (int * arr, int numsSize)
{
	int i = 0;
	while (i < numsSize)
	{
		printf("%d ", arr[i++]);
	}
	printf("\n");
}

void main()
{
	int arr[] = {9, 6, 1, 8, 2, 5, 4, 0, 7, 3};
	bubbleSort ((int *)arr, sizeof(arr)/sizeof(int));
	showArray ((int *)arr, sizeof(arr)/sizeof(int));
	
}
