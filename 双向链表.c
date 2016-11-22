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

//��ʼ��˫������ 
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
		
		//ѭ��˫������ 
		p->Next = (*DL)->Next;
		(*DL)->Next->Prior = p; 
		
		
		return OK;
} 

//����˫������
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

//����һ���ڵ㵽˫������
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
	
	printf("������һ������,0����:");
	
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
		printf("\n������һ������,0����:");
	}
	
	
	

	return 0;
}