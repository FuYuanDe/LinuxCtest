/*
 *	N凸边形划分三角形，求所得所有的三角形顶点之积的最大值
 *  m[i][j] = MAX(m[i][k] + m[k][j] + a[i]*a[k]*a[j])
 */

#include <stdio.h>


void showEdage(int (*p)[30], int i, int j)
{
	int k;
	k = p[i][j];
	if (j <= i + 1)
		return;
	if (k > i + 1)
		printf("%d - %d ", i, k);
	if (k < j - 1)	
		printf("%d - %d ", k, j);
	showEdage (p, i, k);
	showEdage (p, k, j);
}

void main()
{
	int i, j, k, d, n, a[30] = {0}, m[30][30] = {0}, c[30][30] = {0};
	printf("input nTriangle's n:");	scanf("%d", &n);
	if (n > 30)
	{
		printf("invalid n\n");
		return;
	}
	
	for (i = 0; i < n; i++)
	{
		printf("input %d value:", i+1);
		scanf("%d", &a[i]);
	}
	
	printf("you input n :%d \nvertex: ",n);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	//边界初始化
	for (i = 0; i < n - 1; i++)
		m[i][i+1] = 0;
	
	//递推求解
	for (d = 2; d < n; d++)
	for (i = 0; i <= n - d - 1; i++)
	{
		j = i + d;
		m[i][j] = 10000000;
		for (k = i + 1; k < j; k++)
		{
			if (m[i][j] > m[i][k] + m[k][j] + a[i] * a[j] * a[k])
			{
				m[i][j] = m[i][k] + m[k][j] + a[i] * a[j] * a[k];
				c[i][j] = k;
			}			
		}		
	}

	//打印最优解
	printf("Min : %d\n", m[0][n-1]);
	showEdage (c, 0, n-1);
}
