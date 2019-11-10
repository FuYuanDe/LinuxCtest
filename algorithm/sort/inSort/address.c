/*
 *  引用测试
 */

#include <stdio.h>

void display(int *s)
{
	int i = 0;
	for (; i <= 4; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
}

void main()
{
	int a = 10;
	int b;
	b == a;
	printf("%d %d\n", a, b);
}
