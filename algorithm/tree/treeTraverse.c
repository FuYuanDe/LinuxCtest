/*
 * 树的二叉链式存储
 * 三种遍历方式：先序遍历、中序遍历、后序遍历
 *
 *
 *
 */
#include <stdio.h>
typedef struct Node {
	int data;
	struct Node *lChild, *rChild;
}*pNode;

//先序遍历
void preorderTraverse(pNode root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);

	if (root->lChild)
		preorderTraverse (root->lChild);
		
	if (root->rChild)	
		preorderTraverse (root->rChild);

	return;
}

//中序遍历
void middleorderTraverse(pNode root)
{
	if (root == NULL)
		return;

	if (root->lChild)
		middleorderTraverse (root->lChild);
	
	printf("%d ", root->data);

	if (root->rChild)
		middleorderTraverse (root->rChild);
		
	return;
}

//后序遍历
void postorderTraverse(pNode root)
{
	if (root == NULL)
		return;

	if (root->lChild)
		postorderTraverse (root->lChild);

	if (root->rChild)
		postorderTraverse (root->rChild);

	printf("%d ", root->data);
	
	return;
}



void main()
{
	struct Node a,b,c,d,e,f,g,h;
	a.data = 1;
	a.lChild = &b;
	a.rChild = &c;
	
	b.data = 2;
	b.lChild = &d;
	b.rChild = &e;

	c.data = 3;
	c.lChild = &f;
	c.rChild = &g;	

	d.data = 4;
	d.lChild = &h;
	d.rChild = NULL;
	
	e.data = 5;
	e.lChild = NULL;
	e.rChild = NULL;
	
	f.data = 6;
	f.lChild = NULL;
	f.rChild = NULL;	

	g.data = 7;
	g.lChild = NULL;
	g.rChild = NULL;	

	h.data = 8;
	h.lChild = NULL;
	h.rChild = NULL;

	//preorderTraverse (&a);
	//middleorderTraverse (&a);
	postorderTraverse (&a);
	printf("\n");
	return ;
}
