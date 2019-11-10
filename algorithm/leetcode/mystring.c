#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
/*
	char *p;
	p = (char *)malloc(sizeof(char));
	if (!p){
		printf("error\n");
		return;
	}
	else
		memset(p,0,sizeof(char));
	*p = 1;
*/
	char **p;
	p = (char **)malloc(sizeof(char **));
	if (!p){
		printf("error\n");
		return;
	}
	else{
		*p = (char *)malloc(sizeof(char)*10);
	}
	memset(*p,4,sizeof(char)*10);
	p[0][0] = 1;

	printf("end\n");
}
