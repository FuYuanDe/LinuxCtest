/*
 *  Title : 插入乘号问题
 *  Description : 在一串长度为n的数列中插入r个乘号，使得得到的r+1个数乘积最小
 *  Date : 20190730
 *  f[i][k] = MAX(f[j][k-1]*a[j+1][i]);
 */

#include <stdio.h>

void main()
{
	int i,j,k, r,n = 0, v[20] = {0}, m[20][20] = {0}, t[20];
	char nums[20];
	double d, a[20][20] = {0.0}, f[20][20] = {0.0};

	printf("input number string:"); scanf("%s", nums);
	while(nums[n] != '\0')n++;
	printf("input number of symbol:"); scanf("%d",&r);

	if (r>=n)
	{
		printf("invalid parameters\n");
		return;
	}
	printf("insert %d (*) into %s \n", r, nums);

	//字符转换成数字
	for (i = 0; i < n; i++)
		v[i] = nums[i] - 48;

	//计算区间nums[i~j]数值大小
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			for (d = 0, k = i; k <= j; k++)
				d = d * 10 + v[k];
			a[i][j] = d;
		}
	}

	//边界条件初始化
	for (i = 0; i <= n - r - 1; i++)
		f[i][0] = a[0][i];
		
	//递推
	for (k = 1; k <= r; k++)
	{
		for (i = k + 1; i <= n - 1 - r + k; i++)
		{
			for (j = k; j < i; j++)
			{
				if (f[i][k] < f[j][k-1]*a[j+1][i]){
					f[i][k] = f[j][k-1] * a[j+1][i];
					m[i][k] = j;
				}	
			}
		}
	}

	//打印最优解
	i = r;
	t[i] = m[n-1][i];
	while(i >= 1){
		t[i-1] = m[t[i]][i-1];
		i--;
	}	

	for (j = 0, i = 1; i <= r; i++)
	{
		for (; j <= t[i]; j++)
			printf("%c", nums[j]);
		printf("*");	
	}
	printf("=%f\n",f[n-1][r]);
	
	return;
}
