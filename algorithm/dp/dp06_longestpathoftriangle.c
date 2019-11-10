/*
 *  Title : 三角数阵最大路径
 *  Description : 
 *  Date : 20190730
 *  f[i][j]表示点(i,j)到顶点的路径之和的最大值
 *  f[i][j] = max(f[i-1][j], f[i-1][j-1]) + tri[i][j]
 *	求f[n][j]的最大值
 *  设d[i][j]表示顶点到点[i][j]的路径
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))


void main()
{
	int i, j, k, m, n, f[10][10] = {0}, d[10][10] = {0};
	int paths = 0;
	int tri[10][10] = {{22},{30,16},{10,22,18},{27,13,1,22},{9,28,10,14,15},{23,19,26,12,21,26},{8,17,1,18,25,28,7},{11,23,18,8,15,25,13,15}};

	printf("input lines :"); scanf("%d", &n);
	srand(time(NULL));

	#if 0
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("input line %d %d number:",i,j+1);
			scanf("%d", &tri[i][j]);
		}
	}
	#endif
	
	//随机数生成三角数阵
	/*
	for (i = 0; i < n; i++)
	for (j = 0; j <= i; j++)
		tri[i][j] = rand()%10 + 1;
	*/
	
	
	for (i = 0; i < n; i++){
		for (j = 0; j <= i; j++)
		{
			printf("%d ", tri[i][j]);
		}
		printf("\n");
	}
	
	
	//初始化边界条件
	f[0][0] = tri[0][0];
	d[0][0] = 1;
	
	//递推
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (j - 1 >= 0)
			{
				if (f[i-1][j] == f[i-1][j-1])
				{
					f[i][j] = f[i-1][j-1] + tri[i][j];;
					d[i][j] = d[i-1][j] + d[i-1][j-1];
				}
				else if (f[i-1][j] > f[i-1][j-1])
				{
					f[i][j] = f[i-1][j] + tri[i][j];
					d[i][j] = d[i-1][j];
				}
				else
				{
					f[i][j] = f[i-1][j-1] + tri[i][j];
					d[i][j] = d[i-1][j-1];
				}
			}	
			else
			{
				f[i][j] = f[i-1][j] + tri[i][j];
				d[i][j] = d[i-1][j];
			}	
		}
	}

	//打印最优解
	k = 0, paths = 0;
	for (i = 0; i < n; i++){
		if (f[n-1][i] > k)
		{
			k = f[n-1][i];
			paths = d[n-1][i];
		}
		else if (f[n-1][i] == k)
		{
			paths += d[n-1][i];
		}
	}	
	printf("longest path is :%d, total path :%d \n", k, paths);

	return;
}
