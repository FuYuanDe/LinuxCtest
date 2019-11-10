/* 
 *  归并排序
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

void Merge(RedType *sr, RedType *tr, int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (sr[i].key <= sr[j].key)
			tr[k].key = sr[i++].key;
		else
			tr[k].key = sr[j++].key;
	}

	if (i <= m)
		for (; i <= m; )	
			tr[k++].key = sr[i++].key;
			
	if (j <= n)
		for (; j <= n; )	
			tr[k++].key = sr[j++].key;
			
}


void MergeS(RedType *sr, RedType *tr, int s, int t)
{
	int m;
	Sqlist s1;
	
	if (s == t)	
	{
		//tr[s].key == sr[s].key;
		tr[s].key = sr[s].key;
	}
	else
	{
		m = (s + t)/2;
		MergeS (sr, &s1.r[0], s, m);
		MergeS (sr, &s1.r[0], m + 1, t);
		Merge (&s1.r[0], tr, s, m, t);
	}
}

void MergeSort(Sqlist *sl)
{
	MergeS (&sl->r[0], &sl->r[0], 1, sl->length);
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
	Sqlist sql;
	
	printf("input length : ");
	scanf("%d", &sql.length);
	getchar();

	if (sql.length >= MAXSIZE + 1)
		sql.length = MAXSIZE;

	for(len = 1; len <= sql.length; len++)
	{
		printf("input %d number:", len);
		scanf("%d", &sql.r[len].key); getchar();
	}

	printf("input:");
	printSort (&sql);
	MergeSort (&sql);
	printf("output:");
	printSort (&sql);
	return;

}
