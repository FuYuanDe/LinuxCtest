/*
 * 01背包问题扩展，二维约束条件
 */

 #include <stdio.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void main()
{
	int p[9], w[9], v[9],m[9][45][72];
	int i,j,k,c,d,cw,cv,n,sw,sv,sp;

	printf(" input n:"); scanf("%d", &n);
	printf(" input c:"); scanf("%d", &c);
	printf(" input d:"); scanf("%d", &d);
	for (i = 1; i <= n; i++)
	{
		printf(" input w%d, v%d, p%d:", i, i, i); 
		scanf("%d, %d, %d", &w[i], &v[i], &p[i]);
	}	

	//初始化边界条件
	for (j = 0; j <= c; j++)
	{
		for (k = 0; k <= d; k++)
		{
			if (v[1] <= k && w[1] <= j)
				m[1][j][k] = p[1];
			else
				m[1][j][k] = 0;
		}
	}

	//顺序递推
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= c; j++)
		{
			for (k = 0; k <= d; k++)
			{
				if (v[i] <= k && w[i] <= j)
					m[i][j][k] = MAX (m[i-1][j][k], m[i-1][j-w[i]][k-v[i]] + p[i]);
				else
					m[i][j][k] = m[i-1][j][k];
			}
		}
	}

	//打印最优解
	cw = c;
	cv = d;
	sp = 0;
	for (i = n; i >= 2; i--)
	{
		if (m[i][cw][cv] > m[i-1][cw][cv])
		{
			sp += p[i];
			cw -= w[i];
			cv -= v[i];
			printf("%d %d \n", i, sp);
		}
	}

	if (m[n][c][d] != sp)
		printf("%d %d \n", 1, sp+p[1]);
		
	return;	
}
