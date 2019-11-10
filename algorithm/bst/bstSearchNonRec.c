//二叉树的六种递归
#include <stdio.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}*pnode, node;


//后序遍历递归算法
void postOrderRecursive(pnode root)
{
	if (root)
	{
		//访问左子树
		postOrderRecursive (root->left);
		
		//访问右子树
		postOrderRecursive (root->right);

		//访问根结点
		printf("%d ", root->val);		
	}
	return ;
}


//中序遍历递归算法
void inOrderRecursive(pnode root)
{
	if (root)
	{
		//访问左子树
		inOrderRecursive (root->left);

		//访问根结点
		printf("%d ", root->val);

		//访问右子树
		inOrderRecursive (root->right);		
	}
	return ;
}


//先序遍历递归算法
void preOrderRecursive(pnode root)
{
	if (root)
	{
		printf("%d ", root->val);

		//访问左子树
		preOrderRecursive (root->left);
		//访问右子树
		preOrderRecursive (root->right);		
	}
	return ;
}

//先序遍历非递归
void preOrderNonRec(pnode root)
{
	pnode stack[1000], curr, prev;
	int top, end;

	if (root == NULL)
		return ;

	top = end = 0;

	//根结点入栈
	stack[top++] = root;

	while (top > 0)
	{
		//取栈顶
		curr = stack[--top];

		//右子树入栈
		if (curr->right)
			stack[top++] = curr->right;

		//左子树入栈	
		if (curr->left)
			stack[top++] = curr->left;

		//访问节点	
		printf ("%d ", curr->val);	
	}
	printf("\n");
	return ;
}


//后序遍历，非递归
void postOrderNonRec(pnode root)
{
	pnode stack[1000], curr, prev;
	int top, end;

	if (root == NULL)
		return ;

	top = end = 0;

	//根结点入栈
	stack[top++] = root;

	//指向左孩子
	curr = root->left;
	
	while (curr || top > 0)
	{
		//只要存在孩子节点，则父节点进栈，指向其孩子节点。
		if (curr)
		{
			if (curr->left || curr->right)
			{
				stack[top++] = curr;
				if (curr->left)
					curr = curr->left;
				else
					curr = curr->right; 	
				continue;
			}
		}
		else
		{
			//取栈顶，如果存在右孩子且和上一个访问节点不一样，则父节点
			//继续进栈，指向右孩子。
			curr = stack[--top];

			if (curr->right && curr->right != prev)
			{
				stack[top++] = curr;				
				curr = curr->right;
				continue;
			}
		}

		//访问节点同时保存访问的位置。
		printf("%d ", curr->val);
		prev = curr;
		curr = NULL;
	}
	printf("\n");
	return ;
}

//中序遍历，非递归
void inorderNonRec(pnode root)
{
	pnode stack[1000], curr;
	int top, end;

	if (root == NULL)
		return ;

	top = end = 0;
	//根结点进栈
	stack[top++] = root;

	//当前节点指向左孩子
	curr = root->left;

	while (curr || top > 0)
	{
		//节点存在，则父节点进栈，指向左孩子
		if (curr)
		{
			if (curr->left)
			{
				stack[top++] = curr;
				curr = curr->left;
				continue;
			}
		}
		else
		{
			curr = stack[--top];
		}

		//取栈顶，访问后，指向右孩子
		printf("%d ", curr->val);
		curr = curr->right;
	}
	printf("\n");

	return ;
}



void main()
{
	node a,b,c,d,e,f,g,h;
	a.left = NULL;
	a.right = &c;
	a.val = 10;
	b.left = &d;
	b.right = &e;
	b.val = 8;
	c.left = &f;
	c.right = &g;
	c.val = 12;
	d.left = d.right = e.left = e.right = f.left = f.right = g.left = h.left = h.right = NULL;
	g.right = &h;
	d.val = 6;
	e.val = 9;
	f.val = 11;
	g.val = 15;
	h.val = 18;
	printf("后序遍历递归算法:\n");
	postOrderRecursive (&a);
	printf("\n后序遍历非递归算法:\n");
	postOrderNonRec (&a);
	
	printf("中序遍历递归算法:\n");
	inOrderRecursive (&a);
	printf("\n中序遍历非递归算法:\n");
	inorderNonRec (&a);

	printf("先序遍历递归算法:\n");
	preOrderRecursive (&a);
	printf("\n先序遍历非递归算法:\n");
	preOrderNonRec (&a);
	return ;
}
