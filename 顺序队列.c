#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10 

typedef int Status;
typedef int QElemType;

typedef struct Queue
{
	QElemType data[MAXSIZE];
	int front; //头指针 
	int rear;  //尾指针	
	
}Queue;


//初始化循环队列 
Status InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK; 
	
} 

//返回循环队列的长度
int QueueLength(Queue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 


//循环队列入队操作
Status EnQueue(Queue *Q,QElemType e)
{	
	//先判断队列是否已满
	if((Q->rear+1)%MAXSIZE == Q->front)
	{
		return ERROR;
	}
	
	Q->data[Q->rear] = e;
	Q->rear	 = (Q->rear+1)%MAXSIZE;
	
	return OK;
} 

//出队操作 
Status DeQueue(Queue *Q,QElemType *e)
{
	//先判断队列是否为空
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return OK; 	
}

//队列是否为空
Status QueueEmpty(Queue Q)
{
	return Q.front == Q.rear?TRUE:FALSE;
} 

int main()
{	
	
	Status j;
	int i=0,l;
	QElemType e;
	Queue Q;
	
	//初始化队列
	InitQueue(&Q); 
	j = QueueEmpty(Q);
	if(j==TRUE)
	{
		printf("初始化队列后,队列为空!\n");
	}else{
		printf("初始化队列后,队列不为空!\n");
	}
	
	printf("请输入%d个整形元素:\n",MAXSIZE-1);
	
	for(i=0;i<MAXSIZE-1;i++)
	{
		EnQueue(&Q,i+10);
	}
	
	j = QueueLength(Q);
	printf("队列长度为:%d\n",j);
	DeQueue(&Q,&e);
	printf("出队操作,元素%d出队了\n",e);
	DeQueue(&Q,&e);
	printf("出队操作,元素%d出队了\n",e);
	DeQueue(&Q,&e);
	printf("出队操作,元素%d出队了\n",e);
	
	j = QueueLength(Q);
	printf("队列长度为:%d\n",j);

}