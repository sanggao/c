#include <stdio.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct Node
{
	ElemType data; //������ 
	struct Node* Next; //ָ���� 
} Node;

typedef struct Node* LinkList;


//���ҵ�i��Ԫ��
ElemType GetElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	
	p = L->Next; //�˿�pָ����ǵ�һ��Ԫ�� 
	while(p && j<i)
	{	
		p = p->Next; //�˿�pָ����ǵ�j+1��Ԫ�� 
		j++;
	}
	
	if(!p)
	{
		return ERROR;
	}
	
	*e = p->data;
	return OK;
}

//����Ԫ��
Status ListInsert(LinkList L,int i,ElemType *e)
{
	LinkList p,s;
	int j = 1;
	
	p = L->Next;
	
	while(p && j<i)
	{
		p = p->Next;
		j++;	
	}
	
	if(!p)
	{
		return ERROR;
	}
	
	//�����ڴ�ռ�
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	
	s->Next = p->Next;
	p->Next = s;
	
	return OK;
} 

int main()
{
	
	int *a,*b;
	a=1;
	b = a;
	b=2;
	
	printf("%d\n",a);
	
	return 0;
}


