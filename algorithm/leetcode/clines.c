#include <stdio.h>
#include <string.h>
void main()
{
   char a[] = "hello";
   char *s = (char *)a;
   char *p = "ddddddd";
   *p = 'c';
} 
