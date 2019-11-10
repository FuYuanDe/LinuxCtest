#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum Dir{
  UP, DOWN  
};

int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int i, j, row, *ret, done = 0, dir, k = 0, col;
    
    col = *matrixColSize;
    ret = (int *)malloc(matrixSize * sizeof(int));
    if (!ret) return NULL;
    *returnSize = matrixSize;
    row = matrixSize / col;
    printf("row%d, col:%d\n", row, col);
    
    i = j = 0;
    dir = UP;
    while(!done)
    {
        ret[k++] = *((int *)matrix + i * col +j);
        printf("x:%d,y:%d, v :%d\n", i, j, ret[k-1]);
        done = 1;
        if (dir == UP)
        {
            //向斜上遍历
            if (i-1 >= 0 && j+1 < col)
            {
                i -= 1;
                j += 1;
                done = 0;
            }
            else if (i - 1 < 0 && j + 1 < col)
            {
                //右移
                j += 1;
                dir = DOWN;
                done = 0;
            }
            else
            {
                //下移
                i += 1;
                dir = DOWN;
                if (i >= row)
                    done = 1;
                else 
                    done = 0;
            }
        }
        else 
        {            
            if (i + 1 < row && j - 1 >= 0)
            {
                //向左下遍历
                i += 1;
                j -= 1;
                done = 0;
            }
            else if (i + 1 < row && j - 1 < 0)
            {
                //下移变向
                i = i + 1;
                dir = UP;
                done = 0;
            }
            else
            {
                //右移
                j += 1;
                dir = UP;
                if (j >= col)
                    done = 1;
                else 
                    done = 0;
            }
        }
    }
    return ret;
}

void main()
{
	int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int b = 3;
	int ret, i;
	int *p;
	p = findDiagonalOrder ((int **)a, 9, &b, &ret);
	if (p == NULL)
	{
		printf("返回NULL\n");
		return ;
	}
	printf("返回数组大小为：%d\n",ret);
	for (i = 0; i < ret; i++)
		printf("%d ", p[i]);

	return;	
}
