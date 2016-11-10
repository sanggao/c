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
	int front; //ͷָ�� 
	int rear;  //βָ��	
	
}Queue;


//��ʼ��ѭ������ 
Status InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK; 
	
} 

//����ѭ�����еĳ���
int QueueLength(Queue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 


//ѭ��������Ӳ���
Status EnQueue(Queue *Q,QElemType e)
{	
	//���ж϶����Ƿ�����
	if((Q->rear+1)%MAXSIZE == Q->front)
	{
		return ERROR;
	}
	
	Q->data[Q->rear] = e;
	Q->rear	 = (Q->rear+1)%MAXSIZE;
	
	return OK;
} 

//���Ӳ��� 
Status DeQueue(Queue *Q,QElemType *e)
{
	//���ж϶����Ƿ�Ϊ��
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return OK; 	
}

//�����Ƿ�Ϊ��
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
	
	//��ʼ������
	InitQueue(&Q); 
	j = QueueEmpty(Q);
	if(j==TRUE)
	{
		printf("��ʼ�����к�,����Ϊ��!\n");
	}else{
		printf("��ʼ�����к�,���в�Ϊ��!\n");
	}
	
	printf("������%d������Ԫ��:\n",MAXSIZE-1);
	
	for(i=0;i<MAXSIZE-1;i++)
	{
		EnQueue(&Q,i+10);
	}
	
	j = QueueLength(Q);
	printf("���г���Ϊ:%d\n",j);
	DeQueue(&Q,&e);
	printf("���Ӳ���,Ԫ��%d������\n",e);
	DeQueue(&Q,&e);
	printf("���Ӳ���,Ԫ��%d������\n",e);
	DeQueue(&Q,&e);
	printf("���Ӳ���,Ԫ��%d������\n",e);
	
	j = QueueLength(Q);
	printf("���г���Ϊ:%d\n",j);

}