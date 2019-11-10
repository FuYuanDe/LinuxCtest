//最长公共子串的动态规划解法

#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void main()
{
	int i, j, k, n, m[30][30] = {0};
	char astr[30+1] = "hsbafdreghsbacdba", bstr[30+1] = "acdbegshbdrabsa";

	n = strlen(astr);
	k = strlen(bstr);

	printf("string A : %s\n", astr);
	printf("string B : %s\n", bstr);
	
	//边界初始化
	for (i = 0; i < n; i++)
		m[i][k] = 0;
	for (j = 0; j < k; j++)
		m[n][j] = 0;

	//状态递推
	for (i = n - 1; i >= 0; i--)
	{
		for (j = k - 1; j >= 0; j--)
		{
			if (astr[i] == bstr[j])
				m[i][j] = m[i+1][j+1] + 1;
			else
				m[i][j] = MAX (m[i+1][j], m[i][j+1]);
		}
	}

	//打印最优解
	printf("最长公共子串长度为：%d\n", m[0][0]); 
	for (i = 0; i < n;)
	{
		for (j = 0; j < k;)
		{
			if (astr[i] == bstr[j]){
				printf("%c", astr[i]);
				i++;
				j++;
			}
			else
			{
				if (m[i][j] == m[i+1][j])
					i++;
				else
					j++;
			}
		}
	}
	printf("\n");
	return;
}
