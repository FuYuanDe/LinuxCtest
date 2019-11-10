/*
 * 无向图的构造与操作
 * 从命令行读取参数构造邻接多重表，并输出深度优先遍历和宽度优先遍历的结果。
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef int VertexType;
typedef int Status;

typedef enum {
	unvisited,
	visited
}VisitIf;

typedef struct EBox{
	//VisitIf mark;	//访问标记
	int ivex, jvex;		//该边依附的两个顶点的位置。
	struct EBox *ilink, *jlink;		//分别指向依附这两个顶点的下一条边。
	//InfoType *info;	//该边信息指针
}EBox;

typedef struct VexBox{
	VertexType data;
	EBox *firstedge;	//指向第一条依附于该顶点的边
}VexBox;

typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;
}AMLGraph;

VisitIf visitedList[MAX_VERTEX_NUM];

Status CreateAMLGraph(AMLGraph *amlG)
{
	int i, avex = -1, bvex = -1;
	EBox *nEdge = NULL, *oldEdge;
	
	if (amlG == NULL)	
		return 1;

	printf("input vexNum, edgeNum : \n");
	scanf("%d %d", &amlG->vexnum, &amlG->edgenum);
	getchar();

	if (amlG->vexnum > MAX_VERTEX_NUM)
		amlG->vexnum = MAX_VERTEX_NUM;

	//先输入顶点数	
	for(i = 0; i < amlG->vexnum; i++)
	{
		printf("input vex %d data :\n", i+1);
		scanf("%d",&amlG->adjmulist[i].data);
		getchar();
		amlG->adjmulist[i].firstedge = NULL;
	}

	//创建边
	for(i = 0; i < amlG->edgenum; i++)
	{
		printf("input edge %d vex :\n", i);
		scanf("%d %d", &avex, &bvex);
		getchar();

		if (avex >= amlG->vexnum || bvex >= amlG->vexnum)
		{
			printf("input edge data error\n");
			return 1;
		}
		nEdge = (EBox *)malloc(sizeof(EBox));
		nEdge->ivex = avex;
		nEdge->jvex = bvex;
		nEdge->jlink = nEdge->ilink = NULL;

		if (amlG->adjmulist[avex].firstedge == NULL)
		{
			amlG->adjmulist[avex].firstedge = nEdge;
		}
		else
		{
			oldEdge = amlG->adjmulist[avex].firstedge;
			while(oldEdge)
			{
				if (oldEdge->ivex == avex)
				{
					if (oldEdge->ilink)
					{
						oldEdge = oldEdge->ilink;
					}
					else
					{
						oldEdge->ilink = nEdge;
						break;
					}
				}
				else
				{
					if (oldEdge->jlink)
					{
						oldEdge = oldEdge->jlink;
					}
					else
					{
						oldEdge->jlink = nEdge;
						break;
					}
				}
			}
		}

		if (amlG->adjmulist[bvex].firstedge == NULL)
		{
			amlG->adjmulist[bvex].firstedge = nEdge;
		}
		else
		{
			oldEdge = amlG->adjmulist[bvex].firstedge;
			while(oldEdge)
			{
				if (oldEdge->ivex == bvex)
				{
					if (oldEdge->ilink)
					{
						oldEdge = oldEdge->ilink;
					}
					else
					{
						oldEdge->ilink = nEdge;
						break;
					}
				}
				else
				{
					if (oldEdge->jlink)
					{
						oldEdge = oldEdge->jlink;
					}
					else
					{
						oldEdge->jlink = nEdge;
						break;
					}
				}
			}
		}
	}
	return 0;
}


//返回v的第一个邻接
int FirstAdjVex(AMLGraph *amlg, int v)
{
	if (!amlg || v >= amlg->vexnum || !amlg->adjmulist[v].firstedge)
		return -1;
	
	if (amlg->adjmulist[v].firstedge->ivex == v)
		return amlg->adjmulist[v].firstedge->jvex;
	else
		return amlg->adjmulist[v].firstedge->ivex;
}

//返回v 相对于w的下一个邻接顶点，若w是v的最后一个邻接点，则返回空
int NextAdjVex(AMLGraph *amlg, int v, int w)
{
	EBox *next = NULL;
	
	if (!amlg || v >= amlg->vexnum || !amlg->adjmulist[v].firstedge)
		return -1;

	next = amlg->adjmulist[v].firstedge;

	while(next)
	{
		if (next->ivex == w )
		{
			if (!next->jlink)
				return -1;
			else
			{
				if (next->jlink->ivex == v)
					return next->jlink->jvex;
				else
					return next->jlink->ivex;
			}
		}
		else if (next->jvex == w)
		{
			if (!next->ilink)
				return -1;
			else
			{
				if (next->ilink->ivex == v)
					return next->ilink->jvex;
				else
					return next->ilink->ivex;
			}
		}
		else if (next->ivex == v)
		{
			if (!next->ilink)
				return -1;
			else
				next = next->ilink;
		}
		else
		{
			if (!next->jlink)
				return -1;
			else
				next = next->jlink;
		}
			
	}

	return -1;
}

void DFS(AMLGraph *amlg, int v)
{
	int w;
	visitedList[v] = 1;
	printf("%d ", amlg->adjmulist[v].data);
	for(w = FirstAdjVex (amlg, v); w >= 0; w = NextAdjVex (amlg, v, w))
	{
		if (!visitedList[w])
			DFS (amlg, w);
	}
}

//深度优先遍历
void DFSTraverse(AMLGraph *aml)
{
	int v;

	//访问标志数组初始化
	for (v = 0; v < aml->vexnum; ++v)
	{
		visitedList[v] = unvisited;
	}

	for (v = 0; v < aml->vexnum; v++)
	{
		if (!visitedList[v])
			DFS (aml, v);
	}
}

typedef int qElemType;

 typedef struct Node {
	qElemType data;
	struct Node *next;
 }*pNode;

 typedef struct queue{
	pNode front;
	pNode rear;
 }Queue;

 Status initQueue (Queue *q)
 {
	q->front = q->rear = (pNode)malloc(sizeof(struct Node));
	if (!q->front)
		exit(1);

	q->front->next = NULL;
	return 0;
 }

 Status DestroyQueue(Queue *q)
 {
	while(q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}

	return 0;
 }

 Status EnQueue(Queue *q, qElemType e)
 {
	pNode p = (pNode)malloc(sizeof(struct  Node));
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return 0;
 }

 Status DeQueue(Queue *q, qElemType *e)
 {
 	pNode p;
	if (q->rear == q->front)
		return 1;

	p = q->front->next;
	q->front->next = p->next;
	if (q->front->next == NULL)
		q->rear = q->front;
	*e = p->data;
	free(p);
	
	return 0;			
 }

 Status QueueEmpty(Queue *q)
 {
	if (q->rear == q->front)
		return 1;
	else
		return 0;
 }

void BFSTraverse(AMLGraph *amlg)
{
	int v, w;
	Queue q;
	qElemType e;
	
	// 按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visitedList
	for (v = 0; v < amlg->vexnum; v++)
	{
		visitedList[v] = unvisited;
	}

	initQueue (&q);

	for (v = 0; v < amlg->vexnum; v++)
	{
		if (!visitedList[v])
		{
			visitedList[v] = visited;
			printf("%d ", v+1);
			EnQueue (&q, v);

			while(!QueueEmpty (&q))
			{
				DeQueue (&q, &e);
				for (w = FirstAdjVex (amlg, e); w >= 0; w = NextAdjVex (amlg, e, w))
				{
					if (!visitedList[w])
					{
						visitedList[w] = visited;
						printf("%d ", w+1);
						EnQueue (&q, w);
					}
				}
			}
		}
	}
	DestroyQueue (&q);
}

void main()
{
	AMLGraph amlg;

	if (CreateAMLGraph (&amlg))
	{
		printf("create amlg fail\n");
		return ;
	}
	//DFSTraverse (&amlg);
	BFSTraverse(&amlg);
	
	return ;
}



