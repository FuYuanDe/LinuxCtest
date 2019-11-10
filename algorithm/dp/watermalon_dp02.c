/* 
 *	Description: 西瓜分堆问题
 *  Date : 20199729
 *  
 */

#include <stdio.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void main()
{
	int i, j, n, s, max, sw, w[20], m[20][1000];

	printf("input watermelon number : ");	scanf("%d", &n);

	for (s = 0, i = 0; i < n; i++)
	{
		printf("input w%d:", i);
		scanf("%d", &w[i]);
		s += w[i];
	}

	max = s / 2;

	//初始化边界
	for (j = 0; j <= max; j++)
		if (j >= w[0])
			m[0][j] = w[0];
		else
			m[0][j] = 0;

	//顺序递推
	for (i = 2; i< n; i++)
	{
		for (j = 0; j <= max; j++)
		{
			if (j < w[i])
				m[i][j] = m[i-1][j];
			else
				m[i][j] = MAX (m[i-1][j], m[i-1][j-w[i]] + w[i]);				
		}
	}

	printf("total weight :%d, avg_Max :%d\n", s, m[n-1][max]);
	
	//打印最优解
	for (sw = 0, i = n - 1; i > 0; i--){
		if (m[i][max] > m[i-1][max])
		{
			sw += w[i];
			max -= w[i];
			printf("%d w%d sw:%d\n", i, w[i], sw);
		}
	}
	max = s / 2;
	if (m[n-1][max] != sw){
		sw += w[0];
		printf("%d w%d sw:%d, max:%d\n", 0, w[0], sw, m[n-1][max]);
	}

	return;
}
 
