/* 
 * 20190715
 * 循环队列
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 5

typedef int Status;

typedef char QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;

//循环队列初始化
Status initQueue(SqQueue *q)
{
	q->base = (QElemType *)malloc(sizeof(QElemType) * MAXQSIZE);
	if (!q->base)
		exit(1);

	q->front = q->rear = 0;
	return 0;
}

//循环队列入队列
Status EnQueue(SqQueue *q, QElemType e)
{
	if ((q->rear + 1) % MAXQSIZE == q->front)
		return 1;

	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXQSIZE;

	return 0;
}

//循环队列出队列
Status DeQueue(SqQueue *q, QElemType *e)
{
	if (q->front == q->rear)
		return 1;

	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXQSIZE;
	return 0;
}


//获取循环队列长度
int QueueLength(SqQueue *q)
{
	return (q->rear - q->front + MAXQSIZE) % MAXQSIZE;
}

void DestroyQueue(SqQueue *q)
{
	free(q->base);
	return;
}

void main()
{
	char value;
	SqQueue q;
	int ret;

	if (initQueue (&q))
	{
		printf("queue init fail\n");
		return;
	}

	scanf("%c", &value);
	getchar();
	while (value != ' ')
	{
		if (EnQueue (&q, value))
		{
			printf("enQueue fail\n");
			break;
		}
		scanf("%c", &value);
		getchar();
	}

	printf("Queue length : %d\n", QueueLength (&q));

	DestroyQueue (&q);
}
