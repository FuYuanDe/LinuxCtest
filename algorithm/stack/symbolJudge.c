/*
 *  判断符号是否合法
 *  [()],([()])
 *  使用栈来解决
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char ElemType;

#define STACK_INIT_SIZE 100

typedef int Status;

#define FAIL 0
#define OK 1

typedef struct Stack {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

Status initStack(sqStack *S)
{
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S->base)
		exit(1);
	S->top = S->base;
	S->stackSize = STACK_INIT_SIZE;

	return OK;
}

Status GetTop(sqStack *s, ElemType *elem)
{
	if (s->base == s->top)
		return FAIL;
	*elem = *(s->top - 1);

	return OK;
}

Status Push(sqStack *s, ElemType elem)
{
	if (s->top - s->base >= s->stackSize)
		exit(1);

	*s->top++ = elem;
	return OK;
}

Status Pop(sqStack *s, ElemType *elem)
{
	if (s->top == s->base)
		return FAIL;

	*elem = *(--s->top);
	return OK;		
}

Status DestroyStack(sqStack *s)
{
	if (s->base == NULL)
		return FAIL;
		
	free(s->base);
	return OK;
}

Status ClearStack(sqStack *s)
{
	if (s->base == NULL)
		exit(1);

	if (s->base == s->top)
		return OK;

	s->top = s->base;
	return OK;
}

Status StackEmpty(sqStack *s)
{
	if (!s || !s->base)
		exit(1);
	if (s->base == s->top)
		return OK;
	return FAIL;	
}

void main()
{
	int len, index;
	Status ret;
	sqStack sq;
	ElemType  elem;

	//char symbol[] = "(([()]))";
	//char symbol[] = "(([]))";
	//char symbol[] = "[[())]";
	char symbol[] = "[([(])]";

	initStack (&sq);
	
	len = strlen(symbol);
	for (index = 0; index <= len; index++)
	{
		switch (symbol[index]){
		case '(':
		case '[':
			ret = Push (&sq, symbol[index]);
			if (ret != OK)
			{
				printf("push error\n");
				exit(1);
			}
			break;

		case ')':
			ret = GetTop (&sq, &elem);
			if (ret != OK)
			{
				printf("getTop error\n");
				exit(1);
			}

			if (elem == '(')
				Pop (&sq, &elem);
			else
			{
				printf("%c ~ %c invalid \n", elem, symbol[index]);
				return ;
			}
			
			break;
		case ']':		
			ret = GetTop (&sq, &elem);
			if (ret != OK)
			{
				printf("push error\n");
				exit(1);
			}

			if (elem == '[')
				Pop (&sq, &elem);
			else
			{
				printf("%c ~ %c invalid \n", elem, symbol[index]);
				return ;
			}						
		}
	}
	if (StackEmpty (&sq) == OK)
		printf("%s valid\n", symbol);
	else
		printf("%s invalid\n", symbol);
	return;	
}

