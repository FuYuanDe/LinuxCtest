/*
 * 插入排序
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 30
typedef int KeyType;
typedef int InfoType;
typedef struct {
	KeyType key;
	InfoType otherInfo;
}RedType;

typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}Sqlist;

/*
//2路插入排序
void twoInsertSort(Sqlist *q)
{
	int final, first;
	Sqlist d;
	int i, m, j, low, high;

	m = d.r[1] = q->r[1];
	final = first = 1;
	
	for (i = 2; i <= q->length; i++)
	{
		if (q->r[i] > m)
		{
			low = 2;
			high = final;
			while (low <= high)
			{
				m = (low + high)/2;
				if (q->r[i] > d.r[m]) low = m + 1;
				else	high = m - 1;
			}
			++final;
			for (j = final; j > high + 1; j--)
				d[j] = d[j-1];
			d[high + 1] = q->r[i];	
		}
		else
		{
			low = first;
			high = MAXSIZE;
			while (low <= high)
			{
				m = (low + high)/2;
				if (q->r[i] > d.r[m]) low = m + 1;
				else	high = m - 1;
			}
			--first;
			for(j = first; j < MAXSIZE; j++)
				d[j] = d[j+1];
			d[high + 1] = q->r[i];	
		}
	}
}
*/

void showList(Sqlist *q)
{
	int i = 1;
	while (i <= q->length)
	{
		printf("%d ", q->r[i++].key);
	}
	printf("\n");
	return;
}

void showList2(int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d ", arr[i++]);
	}
	printf("\n");
	return;
}


//2路插入排序
void twoInsertSort(Sqlist *q)
{
	int final, first;
	Sqlist d;
	int i, m, j, n;

	memset(&d, 0, sizeof(Sqlist));
	d.r[1].key = q->r[1].key;
	final = first = 1;
	d.length = MAXSIZE;
	
	for (i = 2; i <= q->length; i++)
	{
		d.r[0].key = q->r[i].key;
		
		//往右边插入
		if (q->r[i].key > d.r[1].key)
		{
			j = final;
			while (d.r[j].key >= q->r[i].key)
				j--;
			for(n = ++final; n > j + 1; n--)
				d.r[n] = d.r[n-1];
			d.r[n].key = d.r[0].key;	
		}
		else
		{
			//往左边插入
			if (first == 1)
			{
				d.r[MAXSIZE] = q->r[i];
				first = MAXSIZE;
			}
			else
			{
				j = first;
				while(d.r[j].key < q->r[i].key && j <= MAXSIZE)
					j++;
				for (n = --first; n < j - 1 && n < MAXSIZE; n++)
					d.r[n] = d.r[n+1];
				d.r[n].key = d.r[0].key;
			}
		}
	}
	showList (&d);
}


void insertSort2(int *array, int arraysize)
{
	int final, first, i, j, n;
	final = first = 0;

	if (!array || arraysize < 1)
		return ;
		
	int *tmp = (int *)malloc(sizeof(int) * arraysize);
	if (!tmp)
	{
		printf("malloc error\n");
		return ;
	}

	tmp[0] = array[0];
	for (i = 1; i < arraysize; i++)
	{
		if (array[i] >= tmp[0])
		{
			//插入到左边
			j = final;
			while(array[i] < tmp[j])j--;
			
			for (n = ++final; n > j + 1; n--)
				tmp[n] = tmp[n-1];
			tmp[n] = array[i];	
		}
		else
		{
			//插入到右边
			if (first == 0)
			{
				first = arraysize - 1;
				tmp[first%arraysize] = array[i];
			}			
			else
			{
				j = first - arraysize;
				while(tmp[(j + arraysize)%arraysize] < array[i])
					j++;
				for (n = (--first - arraysize); n < (j - 1); n++)
					tmp[(n + arraysize)%arraysize] = tmp[(n + 1 + arraysize)%arraysize];
					
				tmp[(n + arraysize)% arraysize] = array[i]; 
			}
		}
	}
	showList2 (tmp, arraysize);
}

//插入排序
void inserSort0(int *arr, int numsSize)
{
	int i, j, k, v;
	for (i = 1; i < numsSize; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i] >= arr[j])
				break;
		}
		v = arr[i];
		
		for (k = i; k > j + 1; k--)
			arr[k] = arr[k-1];
		arr[k] = v;	
	}
	
	return;
}

//折半插入
void BiInsertSort(int *arr, int numsSize)
{
	int high, low, m, i, j, v;
	for (i = 1; i < numsSize; i++)
	{
		high = i - 1;
		low = 0;
		v = arr[i];
		while (low <= high)
		{
			m = (low + high)/2;
			if (arr[m] >= arr[i])
				high = m - 1;
			else
				low = m + 1;
		}
		for (j = i; j > low; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[low] = v;
	}
}

void main()
{
	Sqlist q;
	q.length = 7;
	int array[] = {49,38,65,97,76,13,27,4,15,40,67,42,31,5,27,2};
	q.r[1].key = 49;
	q.r[2].key = 38;
	q.r[3].key = 65;
	q.r[4].key = 97;
	q.r[5].key = 76;
	q.r[6].key = 13;
	q.r[7].key = 27;
	//showList (&q);
	//twoInsertSort (&q);
	showList2 (array, 16);
	//insertSort2 (array, 16);
	//inserSort0 (array, 16);
	BiInsertSort (array, 16);
	showList2 (array, 16);
}



