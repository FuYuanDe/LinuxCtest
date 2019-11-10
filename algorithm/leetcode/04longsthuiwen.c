#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

//暴力解法
char * longestPalindrome(char * s){
    int first, last, len = 0, i, j, max = 0, cursor, jump = 0;
    char *ps = s;
    if (!s)
        return s;
    
    while(*ps++ != '\0')len++;
    
    for (i = 0; i < len; i++)
    {
        for (j = len - 1; j >= jump; j--)
        {
            first = i, last = j;
            while (first <= last){
                if (s[first++] != s[last--])
                    break;
            }
            
            if (s[first-1] == s[last+1]){
                if (j - i + 1 > max)
                {
                    max = j - i + 1;
                    cursor = i;
                }
                jump = jump > last + 1 ? jump: (last + 1);
                break;
            }                
        }
    }
    ps = (char *)malloc(sizeof(char) * (max + 1));
    if (ps == NULL)
        exit(1);
    for (i = 0; i < max; i++)
        ps[i] = *(s + cursor + i);
	ps[i] = '\0';
    return ps;
}

int centerExpand(char *s, int len, int left, int right)
{
	while(left >= 0 && right < len && s[left] == s[right])
	{
		left--;
		right++;
	}

	return right - left - 1;
}

//中心扩展法
char *longestPalindrome_CenterExpand(char *s)
{
	int len = 0, center = 0, max = 0, max0 = 0, max1 = 0, cursor = 0;
	char *pStr = s;

	if (!s)return s;
	while (*pStr++ != '\0')len++;

	for (center = 0; center < len; center++)
	{
		max0 = centerExpand (s, len, center, center);
		max1 = centerExpand (s, len, center, center+1);
		
		if (max < max0 || max < max1)
		{
			if (max0 > max1)
                cursor = center - max0 / 2;
            else
                cursor = center + 1 - max1 /2;

			max = MAX(max0, max1);
		}
	}

	pStr = s + cursor;
	if (max != len)
		pStr[max] = '\0';
		
	return 	pStr;

}

void main()
{
	char *s = "abba";
	char *p;
	p = longestPalindrome (s);
	printf("%s\n", p);
	return;
}
