#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
	int data;
	int num;
	struct Node *Next;
}Node,*LinkList;	

//初始化链表
void InitLink(LinkList *L)
{
	int i;
	LinkList head, p,q;

	head = (LinkList)malloc(sizeof(Node));
	head->data = 0;
	head->Next = NULL;

	p = (*L) = head;

	for(i=1;i<=13;i++)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->data = 0;
		q->num = i;
		q->Next =  NULL;

		p->Next = q;
		p = q;
	}

	p->Next = head->Next;
}

//遍历链表
void printLink(LinkList L)
{
	LinkList p;
	p = L;

	while(p)
	{
		printf("%d ",p->data);
		p = p->Next;
	}
}

//构造扑克牌顺序
void washCard(LinkList *L)
{	
	int count = 1;
	int i;
	LinkList p;
	p = (*L);
	while(1)
	{
		for(i = 1;i<=count;i++)
		{
			p = p->Next;
			if(p->data != 0)
			{
				i--;	
			}
			
			if(i == count)
			{
				p->data = i;
				printf("%d %d\n",p->num,p->data);
			}
		}
		count++;
		if(count == 14)
		{	
			printf("ok\n");
			break;
		}
	}
}

int main(int argc, char const *argv[])
{
	LinkList L,p;
	int i;
	InitLink(&L);
	//printLink(L);
	washCard(&L);
	p = L->Next;
	for(i=1;i<=13;i++)
	{
		printf("%d ",p->data);
		p = p->Next;
	}
	
	return 0;
}