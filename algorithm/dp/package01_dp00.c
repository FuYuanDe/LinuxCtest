/*
 *  01背包逆序、顺序求解
 *  20190729
 */
#include <stdio.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void main()
{
	int i, j, c, cw, n, sw,sp,p[50], w[50], m[50][500];
	printf(" input n:"); scanf("%d", &n);
	printf(" input c:"); scanf("%d", &c);
	for (i = 1; i <= n; i++)
	{
		printf(" input w%d, p%d:", i , j); 
		scanf("%d, %d", &w[i], &p[i]);
	}
	
	for (j = 0; j <= c; j++)
		if (j >= w[1])
			m[1][j] = p[1];
		else
			m[1][j] = 0;

	for (i = 2; i <= n; i++)
	{
		for (j = 0;j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = MAX(m[i-1][j], m[i-1][j - w[i]]+p[i]);
			else
				m[i][j] = m[i-1][j];
		}
	}
	
	sp = 0;
	for (cw = c, i = n; i >= 2; i--)
	{
		if (m[i][cw] > m[i-1][cw])
		{
			sp += p[i];
			cw -= w[i];
			printf("%d w:%d p:%d sp:%d\n",i, w[i], p[i], sp);
		}
	}
	
	if (m[n][c] != sp)
		printf("%d w:%d p:%d sp:%d\n",1, w[1], p[1], sp + p[1]);	
		
/******逆序倒推*************
	
	//初始化边界条件
	for (j = 0; j <= c; j++)
	{
		if (j >= w[n])
			m[n][j] = p[n];
		else
			m[n][j] = 0;
	}

	for (i = n - 1; i >= 1; i--)
	{
		for (j = 0; j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = MAX(m[i+1][j], m[i+1][j-w[i]]+ p[i]);
			else
				m[i][j] = m[i+1][j];
		}
	}
	//打印最优化结果
	sp = 0；
	for (cw = c, i = 1; i <= n - 1; i++)
	{
		if (m[i][cw] > m[i+1][cw])
		{
			sp += p[i];
			cw -= w[i];
			printf("%d w:%d p:%d sp:%d\n",i, w[i], p[i], sp);
		}
	}
	
	if (m[1][c] != sp)
		printf("%d w:%d p:%d sp:%d\n",n, w[n], p[n], sp + p[n]);
****************************/		
	return;	
}


