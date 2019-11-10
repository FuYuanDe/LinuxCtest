/*
 *	n个数插入r个乘号使得乘积最大
 *  f[i][j] 表示前i个数中插入j个乘号的最大值。
 *  f[i][j] = MAX(f[i-k][j-1]*a[i-k+1 ~ i])
 */

#include <stdio.h> 

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void main()
{	
	double f[30][20] = {0}, d;
	int a[30] = {0}, i, j, k, m, n, r, c[30][20] = {0}, b[20];
	char l[30];

	printf("输入数列：");	scanf("%s",l);
	printf("输入插入乘号的个数："); scanf("%d", &r);

	n = 0;
	while(l[n] != '\0'){
		a[n] = l[n] - 48;
		n++;
	}
	
	//边界初始化
	for (i = 0; i < n - r; i++)
	{
		for (d = 0, j = 0; j <= i; j++)
			d = d * 10 + a[j];
		f[i][0] = d;	
	}

	//递推
	for (j = 1; j <= r; j++)
	{
		for (i = j; i < n - r + j; i++)
		{
			for (k = j; k < i; k++)
			{
				for (d = 0, m = k + 1; m <= i; m++)
					d = d * 10 + a[m];

				if (f[i][j] < f[k][j-1] * d)
				{
					f[i][j] = f[k][j-1] * d;
					//保存乘号的位置
					c[i][j] = k;
				}
			}
		}
	}

	//打印最优解
	b[r] = c[n-1][r];
	for(j = r - 1; j > 0; j--)
		b[j] = c[b[j+1]][j];

	for (j = 1, i = 0; j <= r; j++)	
	{
		while (i <= b[j])
			printf("%c", l[i++]);
		printf(" * ");
	}	
	printf(" = %0.1f\n", f[n-1][r]);
}
