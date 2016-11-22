#include<stdio.h>
#include<stdlib.h>
#include<math.h>  
#include<time.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DulNode
{
	ElemType data;
	struct DulNode *Next;
	struct DulNode *Prior;
}DulNode, *DuLinkList;

//初始化双向链表 
Status InitList(DuLinkList *DL)
{
		DuLinkList head,p,q;
		int i;
		
		head = (DuLinkList)malloc(sizeof(DulNode));
		head->Next = NULL;
		head->Prior = NULL;
		
		(*DL) = q = head;
		
		for(i=0;i<26;i++)
		{
			p = (DuLinkList)malloc(sizeof(DulNode));
			p->data = 'A'+i;
			p->Next = NULL;
			
			q->Next = p;
			p->Prior = q;
			
			q = p; 
		}
		
		//循环双向链表 
		p->Next = (*DL)->Next;
		(*DL)->Next->Prior = p; 
		
		
		return OK;
} 

//遍历双向链表
void TraverseList(DuLinkList DL)
{
	DuLinkList p;
	p = DL->Next;
	
	while(p)
	{
		printf("%c ",p->data);
		p = p->Next;
	}
	printf("\n");
} 

//插入一个节点到双向链表
Status InsertList(DuLinkList *DL,int i,ElemType e)
{
	DuLinkList q, p = (*DL);
	int j = 0;
	
	while(p && j<i)
	{
		p = p->Next;
		j++;	
	}
	
	if(!p)
	{
		return ERROR;
	}
	
	p = p->Prior;
	
	q = (DuLinkList)malloc(sizeof(DulNode));
	q->data = e;
	
	
	q->Prior = p;
	q->Next = p->Next;
	p->Next = q;
	q->Next->Prior = p;
		
	return OK;
}
 
Status Caesar(int i,DuLinkList *DL)
{
	(*DL) = (*DL)->Next;
	if(i>0)
	{
		do
		{
			(*DL) = (*DL)->Next;
		}while(--i);
	}
	
	if(i<0)
	{
		do
		{
			(*DL) = (*DL)->Prior;
		}while(++i);
	}
} 
 

int main()
{
	DuLinkList DL;
	int i=1;
	ElemType e;
	
	InitList(&DL);
	
	printf("请输入一个数字,0结束:");
	
	while(1)
	{	
		
		scanf("%d",&i);
		if(i==0)
		{
			break;
		}
	
		Caesar(i,&DL);
		
		for(i=0;i<26;i++)
		{
			printf("%c",DL->data);
			DL = DL->Next;
		}
		InitList(&DL);
		printf("\n请输入一个数字,0结束:");
	}
	
	
	

	return 0;
}