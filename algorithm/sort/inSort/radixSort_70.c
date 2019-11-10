/*
 *	基数排序
 *  缺点，只针对正数，复数不处理
 *  辅助空间RADIX*numsSize
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
#define RADIX 10

void showArray(int *arr, int numSize)
{
	int i = 0;
	while (i < numSize)
		printf("%d ", arr[i++]);
	printf("\n");	
}

void radixSort(int *arr, int numsSize)
{ 
	int max = 0, i, bitLen = 0, j, n, k;
	int radix, offset, key;
	int *bucket[RADIX];

	//数组为空或者元素个数只有一个则返回
	if (!arr || numsSize < 2)
		return ;

	//获取最大值
	for (i = 0; i < numsSize; i++)
		max = max > arr[i] ? max : arr[i];
	if (!max)
		return ;
		
	//从最大值获取需要分类的次数
	while (max)
	{
		bitLen++;
		max = max/RADIX;
	}

	//初始化桶
	for	(i = 0; i < RADIX; i++)
	{	
		//bucket[i][0]保存桶中元素个数
		bucket[i] = (int *)malloc(sizeof(int) * (numsSize + 1));
		if (!bucket[i])
			exit(1);
		memset(bucket[i], 0, sizeof(int) * (numsSize + 1));	
	}	
	
	//基数排序
	for (i = 0; i < bitLen; i++)
	{
		//根据基数分类
		for (j = 0; j < numsSize; j++)
		{
			offset = i;
			key = arr[j];
			//获取基类
			while (offset--)
				key = key / RADIX;
			radix = key % RADIX;

			//插入到桶中
			bucket[radix][++bucket[radix][0]] = arr[j];
		}

		//收集元素到数组中
		n = 0;
		for (j = 0; j < RADIX; j++)
		{
			k = 1;
			if (bucket[j][0])
				while (bucket[j][0]){
					arr[n++] = bucket[j][k++];		
					bucket[j][0]--;
				}
		}		
	}

	//释放桶的内存
	for	(i = 0; i < RADIX; i++)
		free(bucket[i]);
	
	return;
}

void main()
{
	int arr[] = {9, 8, 1, 7, 5, 2, 6, 4, 3,43,55,26,18,28,31,17,65, 0, 48};
	showArray (arr, sizeof(arr)/sizeof(int));
	radixSort (arr, sizeof(arr)/sizeof(int));
	showArray (arr, sizeof(arr)/sizeof(int));
}
