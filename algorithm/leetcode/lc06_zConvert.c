/*
 *  Z字形变换
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert1(char * s, int numRows){	
	int len = 0, row = 0, i = 0, j = 0, k = 0;
	char *pstr;
	pstr = s;
	
	if (!s || numRows < 2)
		return s;
	
	while (*pstr++ != '\0')len++;
	
	pstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!pstr)
		return NULL;
	
	//逐行读取字符
	while(row < numRows)
	{
		i = row;
		k = 0;
		
		//首尾行
		if (row == 0 || row == (numRows - 1))
		{
			while(i < len)
			{
				pstr[j] = s[i];
				i += (2 * (numRows - 1));
			}
		}
		else
		{
			while(i < len)
			{
				pstr[j++] = s[i];
				k++;
				if (k % 2)
					i += (2 * (numRows - row));
				else
					i += (2 * (row - 1));
			}
		}
		row++;
	}

	return pstr;
}


char * convert(char * s, int numRows){
    int len = 0, row = 0, i = 0, j = 0, k = 0;
    char *pstr;
    pstr = s;
    
    if (!s || numRows < 2)
        return s;
    
    while (*pstr++ != '\0')len++;
    
    if (len < 2)
        return s;
    
    pstr = (char *)malloc(sizeof(char) * (len + 1));
    if (!pstr)
        return NULL;
    
    i = 0;
    for (row = 1; row <= numRows; row++)
    {
        //按行读取每个字符下标
        j = row - 1;
        if (row == 1 || row == numRows)
        {            
            while (j < len)
            {
                pstr[i++] = s[j];
                j += (2 * numRows - 2);
            }
        }
        else
        {
            k = 1;
            while(j < len)
            {
				pstr[i++] = s[j];
                j = j + ((k++ % 2) ? 2 * (numRows - row) : 2 * (row - 1));
            }
        }   
    }
    pstr[i] = '\0';
    return pstr;
} 

void main()
{
	char str[100] = "LEETCODEISHIRING";
	char *p;
	p = convert (str, 3);
	printf("%s\n", p);
	free(p);
	return;
}
