/*
 * 位运算交换两个数
 */

#include <stdio.h>

void main()
{
	int a, b;
	printf("input a and b :");
	scanf("%d %d", &a, &b);
	getchar();

	printf("\nbefore swap, a = %d, b = %d\n", a, b);

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	printf("a = %d, b = %d \n", a, b);
}
