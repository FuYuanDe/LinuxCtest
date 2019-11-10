/*
 *  Title : 插入乘号问题
 *  Description : 在一串长度为n的数列中插入r个乘号，使得得到的r+1个数乘积最小
 *  Date : 20190730
 */

#include <stdio.h>
#include <string.h>

void main()s
{
	char str[16];
	int n,i,j,k,u,r,b[16],t[16],c[16][16];
	double f[17][17],d;

	printf("input integer:"); scanf("%s", str);
	n = strlen(str);
	printf("input insert symbol number :");	scanf("%d", &r);

	if (n<=r)
	{
		printf("invalid parameter\n");
		return;
	}

	printf("insert %d multiply into %s\n", r, str);

	for (d = 0, j = 0; j <= n - 1; j++)
		b[j] = str[j] - 48;

	for (d = 0, j = 1; j <= n - r; j++)
	{
		d = d * 10 + b[j-1];
		f[j][0] = d;
	}  

	for (k = 1; k <= r; k++)
	{
		for (i = k + 1; i <= n - r + k; i++)
		{
			for (j = k; j < i; j++)
			{
				for (d = 0, u = j + 1; u <= i; u++)
					d = d * 10 + b[u-1];
				if (f[i][k] < f[j][k-1]*d)
				{
					f[i][k] = f[j][k-1]*d;
					c[i][k] = j;
				}
			}
			t[r] = c[n][r];
		}
	}

	for (k = r - 1; k >= 1; k--)
		t[k] = c[t[k+1]][k];
	t[0] = 0; t[r+1] = n;
	for (k = 1; k <= r + 1; k++)
	{
		for (u = t[k-1]; u <= t[k]; u++)
			printf("%c", str[u-1]);
		if (k < r + 1)	printf("*");	
	}
	printf("=%.0f\n", f[n][r]);
}

