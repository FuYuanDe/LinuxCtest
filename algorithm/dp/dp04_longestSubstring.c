/*
 *  Title : 最长公共子序列
 *  Description : 使用动态规划求解
 *  Date : 20190730
 */

#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

void main()
{
	int i, j, alen, blen, c[MAXLENGTH][MAXLENGTH];
	char astr[MAXLENGTH+1];
	char bstr[MAXLENGTH+1];
	char *pstr;

	printf("input astr: "); gets(astr);
	printf("input bstr: "); gets(bstr);
	alen = strlen(astr);	
	blen = strlen(bstr);	
	printf("astr:%d, bstr:%d\n", alen, blen);

	//初始化边界条件
	for (j = 0; j <= blen; j++)
		c[alen][j] = 0;
	for (i = 0; i <= alen; i++)
		c[i][blen] = 0;
		
	//状态递推
	for (i = alen - 1; i >= 0; i--)
	{
		for (j = blen - 1; j >= 0; j--)
		{
			if (astr[i] == bstr[j])
				c[i][j] = c[i+1][j+1] + 1;
			else
				c[i][j] = MAX (c[i+1][j], c[i][j+1]);
		}
	}

	//打印最优解c[0][0]
	printf("length of longest public substring :%d\n",c[0][0]);
	
	for (i = 0; i < alen - 1;)
	{
		for (j = 0; j < blen - 1;)
		{
			if (astr[i] == bstr[j])
			{
				printf("%c", astr[i]);
				i++;
				j++;
			}
			else
			{
				if (c[i][j] == c[i+1][j])
					i++;
				else
					j++;
			}
		}
	}

	if (i == (alen - 1) || j == (blen - 1))
		if (astr[i] == bstr[j])
			printf("%c", astr[i]);
			
	return;
}
