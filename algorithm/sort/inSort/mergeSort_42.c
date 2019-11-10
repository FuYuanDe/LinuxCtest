/*
 *  归并排序
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//归并排序
void MergeSort3(int *arr, int left, int right)
{
	int i, j, k;
	//辅助数组
    int *arr2;
    
	int mid = (right + left) / 2;
 
    //只有一个元素则返回
	if (left >= right || !arr)
		return;
    
    arr2 = (int *)calloc(right-left + 1, sizeof(int));
	
    //递归分割	
	MergeSort3(arr, left, mid);
	MergeSort3(arr, mid+1, right);
 
	//归并处理
	k = i = left;
	j = mid + 1;
	while(i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];			
	}
	if (i>mid)
		while (j<=right)
			arr2[k++] = arr[j++];
	else 		
		while (i<=mid)
			arr2[k++] = arr[i++];
 
	//返回有序数据
	for (i = left; i <= right; i++)
		arr[i] = arr2[i];
	return;		
}

void MergeSort(int *arr, int left, int right, int *dst)
{
	int arr2[MAXSIZE] = {0};
	
	int i, j, k;
	
	int mid = (right + left) / 2;

	if (left > right || !arr ||!dst)
		return;

	if (left == right)
	{
		dst[left] = arr[left];
		return;
	}
		
	MergeSort(arr, left, mid, (int *)arr2);
	MergeSort(arr, mid+1, right, (int *)arr2);

	k = i = left;
	j = mid + 1;
	while(i <= mid && j <= right)
	{
		if (arr2[i] < arr2[j])
			dst[k++] = arr2[i++];
		else
			dst[k++] = arr2[j++];			
	}
	if (i>mid)
		while (j<=right)
			dst[k++] = arr2[j++];
	else 		
		while (i<=mid)
			dst[k++] = arr2[i++];

	return;		
}


void MergeSort2(int *arr, int left, int right)
{
	//辅助数组
	//int arr2[MAXSIZE] = {0};
	
	int i, j, k, *arr2;
	
	int mid = (right + left) / 2;

	if (left >= right || !arr)
		return;	
		
	arr2 = (int *)calloc(right-left + 1, sizeof(int));

	//递归分割	
	MergeSort2(arr, left, mid);
	MergeSort2(arr, mid+1, right);

	//归并处理
	k = i = left;
	j = mid + 1;
	while(i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];			
	}
	if (i>mid)
		while (j<=right)
			arr2[k++] = arr[j++];
	else 		
		while (i<=mid)
			arr2[k++] = arr[i++];

	//返回有序数据
	for (i = left; i <= right; i++)
		arr[i] = arr2[i];
	return;		
}


void showArray(int *arr, int numSize)
{
	int i = 0;
	while (i < numSize)
		printf("%d ", arr[i++]);
	printf("\n");	
}

void main()
{
	int arr[MAXSIZE] = {10,9,4,5,2,8,6,7,1,0,3};
	int arrSort[MAXSIZE] = {0};

	showArray (&arr[0], 11);
	MergeSort3 (&arr[0], 0, 10);
	showArray (&arr[0], 11);	
}
