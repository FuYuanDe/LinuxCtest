#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getChar(char **array, int row, int col)
{
    int irow = 0, icol = 0;
    char ret;
    for (; irow < row;irow++)
    {
        for (icol = 0; icol < col; icol++)
        {
            if (array[irow][icol] != '\0')
            {
                ret = array[irow][icol];
                array[irow][icol] = '\0';
                return ret;
            }
        }
    }
    return '\0';
}

char * convert(char * s, int numRows){
    int len = 0, arraySize;
    int row, col, rowLast, colLast,i = 0;
    
    char *pstr = s;
    char **cArray;
    if (!s || numRows == 1)
        return s;
    while(*pstr++ != '\0')len++;
    col = len;
    arraySize = sizeof(char) * numRows * col;
    cArray = (char **)malloc(sizeof(char *)*numRows);
    while (i<numRows)
    	cArray[i++] = (char *)malloc(sizeof(char) * col);

    for (i = 0; i < numRows; i++)
    	memset(cArray[i], 0, col);
    
    pstr = s;
    rowLast = colLast = 0;
    while(*pstr != '\0')
    {
        if (colLast%(numRows-1) == 0)
            cArray[rowLast++][colLast] = *pstr;
        else
            cArray[rowLast--][colLast++] = *pstr;
        
        if (rowLast >= numRows)
        {
            rowLast -= 2;
            colLast++;
        }
        pstr++;
    }
    pstr = s;
    while(*pstr != '\0')
    {
        *pstr = getChar(cArray, numRows, col);
        pstr++;
    }
        
    return s;
}

char * convert1(char * s, int numRows){
    int len = 0, row = 0, i = 0, j = 0, k = 0;
    char *pstr;
    pstr = s;
    
    if (!s || numRows < 2)
        return s;
    
    while (*pstr++ != '\0')len++;
    printf("%d\n", len);
    
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
                pstr[j++] = s[i];
                //printf("%d \n", i);
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
    pstr[j] = '\0';
    return pstr;
}

void main()
{
	char *p;
	char str[]="LEETCODEISHIRING";
	//char str[]="PAYG";
	printf("%s \n", str);
	p = convert1 ((char *)str, 3);
	printf("%s \n", p);
}
