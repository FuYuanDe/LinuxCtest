/*
 * 希尔排序
 */
#include <stdio.h>

 void shellSort(int *arr, int numsSize, int *d, int size)
 {	
 	int i, k, v, j, m, n = 0;
	while (n < size)
	{
		//遍历增量
		k = d[n++];

		//对增量子数组排序
		for (i = 0; i < k; i++)
		{
			//指向增量子数组第二个元素
			for (j = i + k; j < numsSize; j = j + k)
			{
				if (arr[j] < arr[j-k])
				{
					v = arr[j];
					
					//在i, i+k,..,j之间找到合适位置并插入
					m = j - k;
					while(m >= 0 && arr[m] > arr[j]){
						arr[m + k] = arr[m];
						m -= k;
					}
					arr[m + k] = v;	
				}
			}
		}
	}
 }

void showArray(int *arr, int numsSize)
{
	int i;
	for (i = 0; i < numsSize; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[] = {27, 21, 9, 3, 0, 18, 24, 15, 6, 12};
	int d[]= {5, 3, 2, 1};
	showArray ((int *)&arr, 10);
	shellSort ((int *)&arr, 10, (int *)&d, 4);
	showArray ((int *)&arr, 10);
}
