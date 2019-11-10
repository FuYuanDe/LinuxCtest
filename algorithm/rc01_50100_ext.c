/*
 *  带约束条件的排队问题
 */

#include <stdio.h>

#define NUM 100

void main()
{
	int i,j,m,n,k[NUM][NUM]={0};
	
	printf("分别输入持有50和100币值的人数："); scanf("%d %d", &m, &n);

	//递推方式
	for (i = 1; i <= 7; i++)
		k[i][0] = 1;

	for (j = 1; j <= n; j++)	
	for (i = 0; i < j; i++)
		k[i][j] = 0;

	for (i = 1; i <= m; i++)
	for (j = 1; j <= n && j <= i; j++)
	{
		if ((i == 4 && j == 1) || (i == 3 && j == 2) )
			k[i][j] = k[i-1][j];
		if((i == 7 && j == 1) ||(i == 6 && j == 2)||(i == 5 && j == 3))
			k[i][j] = k[i][j-1];
		else	
			k[i][j] = k[i-1][j] + k[i][j-1];
	}
		
	printf("当持有50的人数为%d，持有100的人数为%d，总的排队方式有：%d\n",m,n, k[m][n]);
}
 
