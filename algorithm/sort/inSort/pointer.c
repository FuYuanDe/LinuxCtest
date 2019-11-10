#include <stdio.h>

void showArray(int **arr, int row, int col)
{
	int i = 0, j = 0;
	for (; i < row; i++)
	{
		for (; j < col; j++)
			printf("%d ", *((int *)arr+i*col + j));
	}
	return;
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void main()
{
	int a = 3;
	int b = 3;
	int c = 3;
	swap (&c, &c);
	printf("%d\n", c);
}
