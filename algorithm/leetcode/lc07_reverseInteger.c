#include <stdio.h>

#include<limits.h>

int reverse(int x){
    int a[15] = {0}, i = 0, flag, j = 0;
    unsigned int re = 0, se = 0;
    
    if (x == 0) return 0;
    else if (x < 0) 
    {
        re = -((unsigned int)x);
        flag = -1;
    }
    else
    {
        re = (unsigned int)x;
        flag = 1;
    }

    printf("re = %d \n", re);
    while (re)
    {
        a[i++] = (int)(re % 10);
        re = re / 10;
    }
    
    while (j < i)
    {
        se = se * 10 + a[j++];
    }
    printf("se = %d, max:%d, min :%d \n", se, INT_MAX, INT_MIN);

    se *= flag;
    if (se > INT_MAX || se < INT_MIN)
        return 0;
    else
        return (int)re;
}

void main()
{
	int d;
	printf("输入整型数字："); scanf("%d", &d);
	printf("return :%d\n", reverse (d));
	return;
}
