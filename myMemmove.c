#include<stdio.h>

#define MAX 1<<21
//标准库版本
void *myMemmove1 (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;

  if (!dest || !src)	return dest;
  
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
    {
      char *lasts = (char *)s + (len-1);
      char *lastd = d + (len-1);
      while (len--)
        *lastd-- = *lasts--;
    }
  return dest;
}


//优化版本
void *myMemmove2(void *dst, const void *src, size_t len)
{
	double *srcdb, *dstdb;
	char *srcch, *dstch;
	size_t times, left;

	times = len / 8;
	left = len % 8;
	
	if (!src || !dst)	return dst;

	//从前往后复制
	if (dst < src)
	{
		srcdb = (double *)src;
		dstdb = (double *)dst;
		
		while (times--)
		{
			*dstdb++ = *srcdb++;
			len-=8;
		}
		
		srcch = (char *)srcdb;
		dstch = (char *)dstdb;

		while (left--)
		{
			*dstch++ = *srcch++;
		}
	}
	//从后往前复制
	else if (dst > src)
	{
		if (times > 0)
		{
			dstdb = (double *)(dst+len-8);
			srcdb = (double *)(src+len-8);	
		}
		
		while(times--)
		{
			*dstdb = *srcdb;
			dstdb--;srcdb--;
		}
		
		if (len > 8 && left)
		{
			srcch = (char *)(srcdb+1)-1;
			dstch = (char *)(dstdb+1)-1;
			while(left--)
			{
				*dstch-- = *srcch--;
			}
		}
		else
		{
      		srcch = (char *)src + (len-1);
      		dstch = (char *)dst + (len-1);	
      		while (len--)
	 	       *dstch-- = *srcch--;
		}
	}
	
	return dst;
}

void showStr(const char *str)
{
	if(str)
		printf("%s\n", str);
	return ;
}

void main()
{
	int i = 0;	
	//char prev[MAX]="\0";
	char src[MAX]="111111112222222233333333";
	//char dst[MAX]="\0";	
	//char dst1[MAX]="\0",dst2[MAX]="\0",dst3[MAX]="\0",dst4[MAX]="\0";
	//char dst5[MAX]="\0",dst6[MAX]="\0",dst7[MAX]="\0",dst8[MAX]="\0";

	char dstBench1[MAX]="\0";
	char dstBench2[MAX]="\0";

	char *cover1;
	double *srcdb, *dstdb;
	size_t len = sizeof(src);

	printf("start test\n");
	//性能测试，标准库版本
	for (i=0; i < 10000; ++i)
		myMemmove1 (dstBench1, src, MAX-1);
	showStr (dstBench1);
	
	
	//性能测试，优化后的版本
	for (i=0; i < 10000; ++i)
		myMemmove2 (dstBench2, src, MAX-1);
	showStr (dstBench2);	
	#if 0
	printf("Test 1, 优化版本，从后往前，非8字节拷贝\n");
	myMemmove2 (dst1, src, 15);
	showStr (dst1);

	printf("Test 2, 优化版本，从后往前，8字节拷贝\n");
	myMemmove2 (dst2, src,16);
	showStr (dst2);

	printf("Test 3, 优化版本，从前往后，非8字节拷贝\n");
	myMemmove2 (dst3, src,15);
	showStr (dst3);

	printf("Test 4, 优化版本，从前往后，8字节拷贝\n");
	myMemmove2 (dst4, src,16);
	showStr (dst4);
	#endif

	#if 0
	//覆盖版本测试1，从后往前复制，8字节拷贝，OK
	showStr (src);
	cover1 = src+8;
	myMemmove2 (cover1, src, 16);
	showStr (src);
	showStr (cover1);
	

	//覆盖版本测试2，从后往前复制，单字节拷贝，OK
	showStr (src);
	cover1 = src+8;
	myMemmove2 (cover1, src, 15);
	showStr (src);
	showStr (cover1);
	#endif 


	return ;
}
