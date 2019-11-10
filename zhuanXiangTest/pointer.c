#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *left, *right;
}node, *pnode;

void changePointer(pnode *pn)
{
	if (*pn == NULL)
	{
		printf("para is null, malloc new\n");
		*pn = (pnode)calloc(1, sizeof(struct node));
		return ;
	}
	printf("para is not null\n");
	return;
}

void changeRef(pnode &pn)
{
	if (pn == NULL)
	{
		printf("para is null, malloc new\n");
		pn = (pnode)calloc(1, sizeof(struct node));
		return ;
	}
	printf("para is not null\n");
	return;
}

void printNode(pnode p)
{
	printf("key:%d\n", p->key);
	if (p->left == NULL)
	{
		printf("child is NULL\n");
	}
	else
		printf("child exist\n");

	return;
}
void main()
{
	struct node n = {100, NULL,NULL};
	pnode p = &n;
	printNode (p);
	//changePointer (&n.left);
	changeRef (&n.left);
	printNode (p);
	return ;
}
