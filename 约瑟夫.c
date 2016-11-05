#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* Next;
}Node;

typedef struct Node *LinkList;

//创建一个n个节点的循环链表
int CreateList(LinkList *L,int n)
{	
	int i;
	LinkList p,s;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->Next = NULL;

	s = (*L);

	for(i=1;i<=n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		p->Next = NULL;
		s->Next = p;
		s = p;
	}
	
	//将最后一个节点指向第一个节点,构造一个闭环的循环链表
	s->Next = (*L)->Next;

	//释放头节点
	free(*L);

	*L = s->Next;

	return 1;
}

int KillList(LinkList *L,int n)
{
	LinkList s, p;
	s = p = (*L);
	int i = 1;
	while(p != p->Next)  
	{	
		if(i % (n-1) == 0)
		{	
			s = p->Next;
			p->Next = s->Next;
			free(s);
		}
		p = p->Next;
		i++;
	}
	printf("留下的是%d\n",p->data);

	
	
}

void TraverseList(LinkList L)
{
	LinkList p = L;
	while(p->Next != L)
	{
		printf("%d ", p->data);
		p = p->Next;
	}

	printf("%d\n",p->data);

}


int main()
{
	int i;
	LinkList L;
	i = CreateList(&L,10);
	//TraverseList(L);
	KillList(&L,2);
	return 0;
}
    
