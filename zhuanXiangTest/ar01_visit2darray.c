#include <stdio.h>


void showArray(int **a, int arraySize, int col)
{
	int i = 0, row = arraySize / (col * sizeof(int));
	int j = 0;

	for (; i < row; i++)
	for (j = 0; j < col; j++)
		printf("%d ",*((int *)a+ i*col + j));
		//printf("%d ",*(*(a+i) + j));
}

void main()
{
	int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	printf("size of array : %d\n", sizeof(a));
	showArray ((int **)a, sizeof(a), 3);
}
