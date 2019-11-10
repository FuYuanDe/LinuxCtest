#include <stdio.h>


//两个数值互换
void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void qSort(int *arr, int low, int high)
{
	int pivotKey, pivotLoc;
	int left = low;
	int right = high;
	if (low < high)
	{
		//保存枢轴点和枢轴值
		pivotLoc = (low + high) / 2;
		pivotKey = arr[pivotLoc];
		while (low < high)
		{
			while (low < pivotLoc && arr[low] <= pivotKey)low++;
			if (low < pivotLoc)
			{
				swap(arr+low, arr+pivotLoc);
				pivotLoc = low;
			}
			
			while(high > pivotLoc && arr[high] >= pivotKey)high--;
			if (high > pivotLoc)
			{
				swap(arr+high, arr+pivotLoc);
				pivotLoc = high;					
			}
		}

		qSort (arr, left, pivotLoc);
		qSort (arr, pivotLoc + 1, right);
	}
	return;
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
	//int arr[] = {9, 6};
	showArray ((int *)arr, sizeof(arr)/sizeof(int));
	qSort ((int *)arr, 0, sizeof(arr)/sizeof(int)-1);
	showArray ((int *)arr, sizeof(arr)/sizeof(int));
}

