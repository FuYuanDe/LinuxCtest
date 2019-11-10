#include <stdio.h>
#include <limits.h>

void main()
{
	int d = '0' - '\0';
	printf("%d,%d %d\n",d, '\0', ' ');
	printf("%d %d", INT_MAX%10, INT_MIN%10);
	return;
}
