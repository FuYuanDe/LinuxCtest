/*
 *	西瓜分堆问题
 *
 */

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void main()
{
	int i,j,n, k, w[30] = {0}, m[30][1000] = {0};
	int c[30] = {0}; 

	printf("输入西瓜个数：");	scanf("%d", &n);
	if (n > 30) n = 30;

	k = 0;
	for (i = 0; i < n; i++)
	{
		printf("输入第%d个瓜的重量：", i + 1);
		scanf("%d", &w[i]);
		k += w[i];
	}

	//得到平均重量
	k = k / 2;
	printf("k = %d\n", k);
	//初始化边界
	for (j = 0; j <= k; j++)
	{
		if (j >= w[0])
			m[0][j] = w[0];
		else
			m[0][j] = 0;
	}

	//状态递推
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			if (j >= w[i])
				m[i][j] = MAX(m[i-1][j], m[i-1][j-w[i]] + w[i]);
			else
				m[i][j] = m[i-1][j];
		}
	}

	//打印最优解
	for (j = k, i = n - 1; i >= 1; i--)
	{
		if (j >= w[i])
		{
			if (m[i][j] == m[i-1][j])
				c[i] = 2; //B堆
			else
			{
				c[i] = 1; //A堆
				j -= w[i];
			}	
		}
		else
			c[i] = 2;	
	}
	if (j >= w[0])
		c[0] = 1;
		
	printf("A堆的瓜：");
	for (j = 0, i = 0; i < n; i++)
	{
		if (c[i] == 1)
		{
			printf("%d ", w[i]);
			j += w[i];
		}
	}
	printf(" 总和：%d \nB堆的瓜：", j);
	for (k = 0, i = 0; i < n; i++)
	{
		if (c[i] == 2)
		{
			printf("%d ", w[i]);
			k += w[i];
		}
	}
	printf(" 总和：%d \n 两堆瓜的重量差为：%d\n",k, ((k > j) ? (k - j) : (j - k)));

	return;
}
