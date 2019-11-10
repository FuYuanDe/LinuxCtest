/*
 *	Title : 矩阵的最长路径
 *	Description: 求矩阵的左上角到右下角所经过路径的最大值以及路径条数
 *	Date : 20190730
 *	递归公式
 *  f[i][j] = MAX(f[i][j-1], f[i-1][j]) + m[i][j];
 */

#include <stdio.h>

void main()
{
	int i,j, n, r, d[20][20] = {0}, m[20][20]={
	{2,3,4,2,1,1,4,5},
	{2,1,3,2,5,2,3,1},
	{5,4,5,5,1,1,3,5},
	{4,1,4,4,2,2,1,3},
	{5,4,4,2,4,5,5,4},
	{5,4,3,4,1,1,1,2},
	{3,4,3,3,1,4,1,2},
	{5,2,3,5,4,3,2,2},
	{3,3,4,2,2,5,4,5},
	{5,5,4,2,4,5,3,4}};

	int f[20][20] = {0};

	printf("input lines and rows of matrix :");	scanf("%d %d", &n, &r);

	if (n>20 || r > 20)
	{
		printf("invalid parameter!\n");
		return;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < r; j++)
			printf("%d ", m[i][j]);
		printf("\n");	
	}

	//边界初始化
	f[0][0] = m[0][0];
	d[0][0] = 1;

	//递推
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < r; j++)
		{
			if ((j - 1 >= 0) && (i - 1 >= 0))
			{
				if (f[i][j-1] == f[i-1][j])
				{
					f[i][j] = f[i][j-1] + m[i][j];
					d[i][j] = d[i][j-1] + d[i-1][j];
				}
				else if (f[i][j-1] > f[i-1][j])
				{
					f[i][j] = f[i][j-1] + m[i][j];
					d[i][j] = d[i][j-1];
				}
				else
				{
					f[i][j] = f[i-1][j] + m[i][j];
					d[i][j] = d[i-1][j];
				}
			}
			else if (i - 1 >= 0)
			{
				f[i][j] = f[i-1][j] + m[i][j];
				d[i][j] = d[i-1][j];				
			}
			else if (j - 1 >= 0)
			{
				f[i][j] = f[i][j-1] + m[i][j];
				d[i][j] = d[i][j-1];
			}
		}
	}

	//打印最优值
	printf("longest path :%d, number of path:%d \n", f[n-1][r-1], d[n-1][r-1]);

	return;
}
