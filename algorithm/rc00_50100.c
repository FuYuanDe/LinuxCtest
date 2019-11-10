/* 
 *	排队问题
 */

#include <stdio.h>
#define NUM 100

int f(int m50, int n100, int m, int n)
{
	if (m50 == m || n == n100)
		return 1;
	else if (m50 > n100)
		return f(m50+1, n100, m, n) + f(m50, n100+1, m, n);
	else if (m50 == n100)	
		return f(m50+1, n100, m, n);
	else
		printf("逻辑错误！");
	return 0;	
}

void main()
{
	int i,j,m,n,k[NUM][NUM]={0};

	//递归处理
	printf("分别输入持有50和100币值的人数：");	scanf("%d %d", &m, &n);
	printf("当持有50的人数为%d，持有100的人数为%d，总的排队方式有：%d\n",m,n, f(1,0,m,n));

	//递推方式
	for (i = 1; i <= m; i++)
		k[i][0] = 1;

	for (j = 1; j <= n; j++)	
	for (i = 0; i < j; i++)
		k[i][j] = 0;

	for (i = 1; i <= m; i++)
	for (j = 1; j <= n && j <= i; j++)
		k[i][j] = k[i-1][j] + k[i][j-1];
		
	printf("当持有50的人数为%d，持有100的人数为%d，总的排队方式有：%d\n",m,n, k[m][n]);
}

