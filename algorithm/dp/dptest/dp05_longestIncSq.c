/*
 *  最长非降子序列
 *  
 *  m[i] = MAX(m[j]) + 1; a[i] > a[j] && j < i;
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void main()
{
	int a[30] = {0}, n, i,j,k,max,m[30] = {0}, c[30];

	printf("input total numbers :"); scanf("%d", &n);

	if (n > 30)
	{
		printf("invalid number\n");
		return;
	}

	//随机生成一些数字
	srand(time(NULL));
	for (i = 0; i < n; i++)
		a[i] = rand()%20 + 1;

	printf("无序数列为：");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");	
		

	//边界初始化
	m[n-1] = 1;
	c[n-1] = n-1;

	//状态递推
	for (i = n- 2; i >= 0; i--)
	{
		m[i] = 1;
		c[i] = i;
		
		for (j = n - 1; j > i; j--)
		{
			if (a[i] <= a[j])
			{
				if (m[i] < m[j] + 1){
					m[i] = m[j] + 1;	
					c[i] = j;
				}
			}	
		}
	}

	//打印最优值
	max = 0;
	for (i = 0; i < n; i++){	
		//printf("%d ", m[i]);
		if (m[i] > max)
		{
			max = m[i];
			k = i;
		}
	}	
		
	printf("最长非降子数列长度为：%d\n", max);
	while (c[k] != k)
	{
		printf("%d ", a[k]);
		k = c[k];
	}
	printf("%d \n",a[k]);
	return;
}

