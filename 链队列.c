#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10 

typedef int Status;
typedef int QElemType;

typedef struct QNode
{
	QElemType data;
	struct QNode *Next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列
Status InitQueue(LinkQueue *Q)
{
	QueuePtr head = (QueuePtr)malloc(sizeof(QNode));
	head->Next = NULL;
	Q->front = Q->rear = head;
	return OK;
} 

//判断队列是否为空
Status QueueEmpty(LinkQueue Q)
{
	return Q.rear==Q.front?TRUE:FALSE;	
} 

//获取队列长度
int QueueLength(LinkQueue Q)
{	
    int n=0;
    
	if(Q.rear==Q.front)
	{	
		return 0;
	}
	QueuePtr p = Q.front; 
	while(p->Next)
	{	
		n++;
		p = p->Next;
	}
	
	return n;
} 

//遍历队元素
void QueueTraverse(LinkQueue Q)
{	
	
	while(Q.front != Q.rear)
	{	
		Q.front = Q.front->Next;
		printf("%d ",Q.front->data);
	}
	printf("\n");
} 

//入队操作
Status EnQueue(LinkQueue *Q,QElemType e)
{	

	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
	p->data = e;
	p->Next = NULL;
	Q->rear->Next = p;
	Q->rear = p;
	
	return OK;
} 

//出队操作
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	//判断队列是否为空
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	
	QueuePtr s = Q->front->Next;
	*e = s->data;
	Q->front->Next = s->Next;
	
	//如果只有一个节点,那么尾指针指向头部,此时队列应该为空
	if(Q->rear == s)
	{
		Q->rear = Q->front;
	}
	
	free(s);
	
	return OK;
	
} 

int main()
{	
	int i,j;
	QElemType e; 
	LinkQueue Q;
	
	//初始化队列 
	i =  InitQueue(&Q); 
	if(i==OK)
	{
		printf("初始化队列成功!\n");
	}
	
	//判断是否为空 
	if(QueueEmpty(Q) == TRUE)
	{
		printf("队列为空!\n");
	}else{
		printf("队列不为空\n");
	}
	
	//获取长度
	printf("此时队列的长度为:%d\n",QueueLength(Q)); 
	
	//添加10个元素
	for(j=1;j<=10;j++)
	{
		EnQueue(&Q,j);	
	}
	printf("入队10个元素后队列的长度为:%d\n",QueueLength(Q)); 
	
	printf("遍历队列:\n");
	QueueTraverse(Q);
	
	//出队操作
	DeQueue(&Q,&e);
	printf("出队的元素是:%d\n",e);
	
	printf("遍历队列:\n");
	QueueTraverse(Q); 
	printf("队列的长度为:%d\n",QueueLength(Q)); 
	
	return 0;
} 