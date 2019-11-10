//01背包问题

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void main()
{
	int i, j, k, n, c, w[30] = {0}, p[30] = {0}, m[30][100] = {0};

	printf("输入物品个数：");	scanf("%d", &n);
	printf("输入背包载重量：");	scanf("%d", &c);
	if (n > 30) n = 30;

	for (i = 0; i < n; i++)
	{
		printf("输入物品%d的重量和效益：",i+1);
		scanf("%d %d", &w[i], &p[i]);
	}

	//初始化边界
	for (i = 0; i <= c; i++)
	{
		if (i >= w[0])
			m[0][i] = p[i];
		else
			m[0][i] = 0;
	}

	//状态递推
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = MAX (m[i-1][j], m[i-1][j-w[i]] + p[i]);
			else
				m[i][j] = m[i-1][j];
		}
	}

	//打印最大效益
	printf("最大装包效益为：%d\n", m[n-1][c]);
	printf("背包所装物品为：");
	//打印最优解
	for (j = c, i = n - 1; i > 0; i--)
	{
		if (j >= w[i]){
			if (m[i][j] != m[i-1][j])
			{
				printf("%d ", i+1);
				j -= w[i];
			}
		}
	}
	if (j >= w[i])
		printf("%d \n", i+1);
	printf("\n");	
	return;	
}
