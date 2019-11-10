#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 *  特殊情况：参数为空或者长度小于1
 *  普通情况：申请等长字符数组，然后逐个复制单词
 */


char * reverseWords(char * s){
    int i, j, first, last,len;
    char *p;
    
    //参数为空或者长度为0返回
    if (!s || strlen(s) < 1)
        return s;
    
    //申请内存，倒序复制单词
    len = strlen(s);
    printf("str len : %d\n", len);
    
    p = (char *)malloc(sizeof(char) * (len + 1));
    if (!p) exit(1);
    
    for (j = 0, i = len - 1; i >= 0; i--)
    {
        printf("%d ", i);
        while(i >= 0 && s[i] == ' ')i--;
        if (i < 0)
        {
            if (j == 0)
                p[j] = '\0';
            else
                p[j-1] = '\0';
            return p;
        }
        else
        {
            //记录单词尾部指针
            last = i;
            while (i >= 0 && s[i] != ' ')i--;
            if (i < 0)
            {
                //第一个单词
                for (i = 0; i <= last; i++)
                    p[j++] = s[i];
                printf("%d \n", j);
                p[j] = '\0';
                return p;
            }
            else
            {
                for (first = i + 1; first <= last; first++)
                    p[j++] = s[first];
                //预留空格
                
                p[j++] = ' ';
                printf("%d \n", j);
            }
        }
    }
        
    return p;
}
void main()
{
	char a[] = " 1";
	char *p;
	p  = reverseWords (a);
	printf("%s\n",p);
	return;
}
