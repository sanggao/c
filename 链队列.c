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

//��ʼ������
Status InitQueue(LinkQueue *Q)
{
	QueuePtr head = (QueuePtr)malloc(sizeof(QNode));
	head->Next = NULL;
	Q->front = Q->rear = head;
	return OK;
} 

//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)
{
	return Q.rear==Q.front?TRUE:FALSE;	
} 

//��ȡ���г���
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

//������Ԫ��
void QueueTraverse(LinkQueue Q)
{	
	
	while(Q.front != Q.rear)
	{	
		Q.front = Q.front->Next;
		printf("%d ",Q.front->data);
	}
	printf("\n");
} 

//��Ӳ���
Status EnQueue(LinkQueue *Q,QElemType e)
{	

	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	
	p->data = e;
	p->Next = NULL;
	Q->rear->Next = p;
	Q->rear = p;
	
	return OK;
} 

//���Ӳ���
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	//�ж϶����Ƿ�Ϊ��
	if(Q->front == Q->rear)
	{
		return ERROR;
	}
	
	QueuePtr s = Q->front->Next;
	*e = s->data;
	Q->front->Next = s->Next;
	
	//���ֻ��һ���ڵ�,��ôβָ��ָ��ͷ��,��ʱ����Ӧ��Ϊ��
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
	
	//��ʼ������ 
	i =  InitQueue(&Q); 
	if(i==OK)
	{
		printf("��ʼ�����гɹ�!\n");
	}
	
	//�ж��Ƿ�Ϊ�� 
	if(QueueEmpty(Q) == TRUE)
	{
		printf("����Ϊ��!\n");
	}else{
		printf("���в�Ϊ��\n");
	}
	
	//��ȡ����
	printf("��ʱ���еĳ���Ϊ:%d\n",QueueLength(Q)); 
	
	//���10��Ԫ��
	for(j=1;j<=10;j++)
	{
		EnQueue(&Q,j);	
	}
	printf("���10��Ԫ�غ���еĳ���Ϊ:%d\n",QueueLength(Q)); 
	
	printf("��������:\n");
	QueueTraverse(Q);
	
	//���Ӳ���
	DeQueue(&Q,&e);
	printf("���ӵ�Ԫ����:%d\n",e);
	
	printf("��������:\n");
	QueueTraverse(Q); 
	printf("���еĳ���Ϊ:%d\n",QueueLength(Q)); 
	
	return 0;
} 