/*
 * 快速排序
 *
 */

#include <stdio.h>

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

int partition(Sqlist *q, int low, int high)
{
	int pivot;
	q->r[0] = q->r[low];
	while(low < high)
	{
		pivot = q->r[0].key;
		while(low < high && q->r[high].key >= pivot) --high;
		q->r[low] = q->r[high];

		while(low < high && q->r[low].key <= pivot) ++low;
		q->r[high] = q->r[low];
	}
	q->r[low] = q->r[0];
	return low;
}

void QSort(Sqlist *q, int low, int high)
{
	int pivotLoc;
	if (low < high)
	{
		pivotLoc = partition (q, low, high);
		QSort (q, low, pivotLoc - 1);
		QSort (q, pivotLoc + 1, high);
	}
	
}

void quickSort(Sqlist *q)
{
	QSort (q, 1, q->length);
}

void printSort(Sqlist *q)
{
	int len = 1;
	while(len <= q->length)
	{
		printf("%d ", q->r[len++].key);
	}
	printf("\n");
}


void main()
{
	int len;
	Sqlist q;
	printf("input length : ");
	scanf("%d", &q.length);
	getchar();

	if (q.length >= MAXSIZE + 1)
		q.length = MAXSIZE;

	for(len = 1; len <= q.length; len++)
	{
		printf("input %d number:", len);
		scanf("%d", &q.r[len].key); getchar();
	}

	printf("input:");
	printSort (&q);
	quickSort (&q);
	printf("output:");
	printSort (&q);
	return;
}
