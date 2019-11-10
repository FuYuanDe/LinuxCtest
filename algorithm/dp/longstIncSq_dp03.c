/*
 *	Title : 最长非递减子序列
 *  Description : 动态规划
 *  Date : 20190729
 */

#include <stdio.h> 

#define MAXSIZE 100
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void main()
{
	int i, j, n, m[MAXSIZE+1], b[MAXSIZE+1];

	printf("input sequence size :"); scanf("%d", &n);
	n = n < MAXSIZE ? n : MAXSIZE;
	
	for (i = 0; i < n; i++)
	{
		printf("input %dth:",i + 1);
		scanf("%d", &m[i]);
	}

	//边界初始化
	b[n-1] = 1;

	//状态递推
	for (i = n - 2; i >= 0; i--)
	{
		b[i] = 1;
		for (j = n - 1; j > i; j--)
		{
			if (m[i] <= m[j])
				b[i] = MAX (b[j]+1, b[i]);
		}
	}

	//打印最优解
	for (j = 0, i = 1; i < n; i++)
	{
		if (b[j] < b[i])
			j = i;
	}
	printf("len of longest sequence is : %d\n", b[j]);		
	printf("%d ", m[j]);
	for (i = j + 1; i <= n - 1; i++)
	{
		if ((m[i] >= m[j]) && (b[j] == (b[i] + 1)))
		{
			j = i;
			printf("%d ", m[i]);
		}
	}
	printf("\n");
}
