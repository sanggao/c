#include <stdio.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct Node
{
	ElemType data; //数据域 
	struct Node* Next; //指针域 
} Node;

typedef struct Node* LinkList;


//查找第i个元素
ElemType GetElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	
	p = L->Next; //此刻p指向的是第一个元素 
	while(p && j<i)
	{	
		p = p->Next; //此刻p指向的是第j+1个元素 
		j++;
	}
	
	if(!p)
	{
		return ERROR;
	}
	
	*e = p->data;
	return OK;
}

//插入元素
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
	
	//分配内存空间
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


