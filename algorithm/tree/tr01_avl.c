/* 
 *	Description:二叉平衡搜索树BBST
 *	实现操作：插入，删除、查询、打印树深
 *  Date :	20190817
 *
 */

#define LH 1
#define EH 0
#define RH -1

typedef struct tnode{
	int bf;	//平衡因子
	int val;
	struct tnode *lchild, *rchild;
}tnode, *pnode;

//右旋处理
void rRotate(tnode **p)
{
	pnode lc = *p->lchild;
	*p->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//左旋处理
void lRotate(tnode **p)
{
	pnode rc = *p->rchild;
	*p->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//左平衡
void leftBalance(tnode **p)
{
	pnode rc, lc = *p->lchild;
	switch (lc->bf)
	{
		//LL型，右旋
		case LH:
			*p->bf = lc->bf = EH;
			rRotate (p);
			break;

		//LR型，双向旋转，先左后又
		case RH:
			rc = lc->rchild;
			switch (rc->bf)
			{
				//修改p以及其左孩子的平衡因子，以下三种情况需要多思考
				case LH:*p->bf = RH; lc->bf = EH;break;
				case EH:*p->bf = lc->bf = EH;	break;
				case RH:*p->bf = EH; lc->bf = LH; break;							
			}
			rc->bf = EH;
			lRotate (&(*p->lchild));
			rRotate (p);
	}
}

//右平衡
void rightBalance(tnode **p)
{
	pnode lc, rc = *p->rchild;
	switch (rc->bf)
	{
		case LH:
			
		case RH:
	}
	
}
