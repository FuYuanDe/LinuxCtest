/*
 *	大顶堆排序实现，操作包括：大顶堆的初始化，插入、删除、查询等。
 * 	20190819
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	if (a == b)
		return ;

	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;	
	return;
}

typedef struct heap{
	int *data;
	int size;
	int len;
}heap, *pheap;

void showHeap(pheap p)
{
	int i = 1;
	while (i <= p->len)
	{
		printf("%d ", p->data[i++]);
	}
	printf("\n");
	return ;
}

pheap heapInit(int size)
{
	pheap p = (pheap)calloc(1, sizeof(heap));
	p->data = (int *)calloc(size + 1, sizeof(int));
	p->size = size;
	p->len = 0;
	return p;
}

void heapAdjust(pheap p, int s, int end)
{
	int i, j;
	j = 2 * s;

	for (;j <= end; j*=2)
	{
		if (j < end && p->data[j] < p->data[j+1])j++;
		if (p->data[s] >= p->data[j]) break;
		swap(p->data + s, p->data + j);
		s = j;
	}
	return ;
}

void heapSort(pheap p)
{
	int i, size = p->len;

	for (i = size/2; i >= 1; i--)
		heapAdjust (p, i, p->len);
	
	for (i = size; i > 1; i--)
	{
		swap(p->data+i, p->data+1);
		heapAdjust (p, 1, i - 1);
	}
	
	return;
}

void main()
{
	int i, size;
	pheap p = heapInit (1000);
	printf("输入堆大小：");	scanf("%d",&p->len);
	for (i = 1; i <= p->len; i++)
	{
		printf("输入第%d 数字：", i);
		scanf("%d", &p->data[i]);
	}

	showHeap (p);
	heapSort (p);
	showHeap (p);
	return;
}

