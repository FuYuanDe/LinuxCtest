1/* 20190715
 * 链式队列
 */

 #include <stdio.h>
 #include <stdlib.h>

typedef char qElemType;
 typedef struct Node {
	qElemType data;
	struct Node *next;
 }*pNode;

 typedef struct queue{
	pNode front;
	pNode rear;
 }Queue;

 typedef int Status;

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

 void main()
 {
 	char input;
	Queue q;
	int ret;

	initQueue (&q);
	scanf("%c", &input);
	getchar();

	while(input != 'q')
	{
		EnQueue (&q, input);
		scanf("%c", &input);
		getchar();
	}
	printf("input :");
	while(!DeQueue (&q, &input))
		printf("%c ", input);

	DestroyQueue (&q);	
 }
