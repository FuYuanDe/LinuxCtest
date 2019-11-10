//测试宏定义
#include <stdio.h>

#define MAX(a,b) \
({	\
	typeof(a) _max1 = (a); \
	typeof(b) _max2 = (b); \
	(void) (&_max1 == &_max2); \
	_max1 > _max2 ? _max1 : _max2; \
}) \

void main()
{
	int a = 1, b = 2;
	printf("%d\n", MAX (a++, b++));
	printf("a:%d,b:%d\n", a, b);

	return ;
}

