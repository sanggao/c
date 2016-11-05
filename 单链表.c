#include<stdio.h>
#include<stdlib.h>
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct Node
{
	ElemType data;
	struct Node *Next;
}Node;

typedef struct Node *LinkList;

//初始化链表 
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(!(*L))
	{
		return ERROR;  //分配内存失败 
	}
	
	(*L)->Next = NULL;
	return OK;	
}

//获取链表长度
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p;
	p = L->Next;
	
	while(p)
	{
		p=p->Next;
		i++;
	}
	
	return i;
	
}

//遍历链表
void ListTraverse(LinkList L)
{
	LinkList p = L->Next;
	while(p)
	{
		printf("%d,",p->data);
		p = p->Next;
	}
	printf("\n");
}

//查找元素索引
int LocateElem(LinkList L,ElemType e)
{
	int j,k;
	j=1;
	k=0;
	LinkList p = L->Next;
	while(p)
	{
		if(p->data == e){
			k = j;
			break;
		}
		p = p->Next;
		j++;
	}

	return k;
}

//插入一个节点
Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j=1;
	LinkList p,s ;
	p = *L;

	while(p && j<i)
	{
		p = p->Next;
		j++;
	}

	if(!p || j>i)
	{
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->Next = p->Next;
	p->Next = s;
	return OK;

}

//随机产生n个元素的值,建立带表头节点的单链表线性L
void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));  //产生随机数
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->Next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		p->Next = (*L)->Next;
		(*L)->Next = p;
	}	
}

//随机产生N个元素,尾巴插入法 
void CreateListTail(LinkList *L,int n)
{
	LinkList p,s;
	int i;
	srand(time(0));  //产生随机数
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->Next = NULL;
	s = (*L);
	for(i=0;i<n;i++)
	{	
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->Next = NULL;
		
		s->Next = p;
		s = p;
	}
	
}




//查找节点
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j=1;
	LinkList p = L->Next;
	while(p && j<i)
	{
		p = p->Next;
		j++;
	}

	if(!p || j>i)
	{
		return ERROR;
	}

	*e = p->data;
	return OK;
}

//删除某个节点元素
Status ListDelete(LinkList *L,int i,ElemType *e)
{
	int j = 1;
	LinkList p,s;
	p = (*L);

	while(p->Next && j<i)
	{
		p = p->Next; 
		j++; 
	}

	if(!p->Next || j>i)
	{	
		return ERROR;
	}

	//此刻p代表低i-1个元素
	s = p->Next;
	*e = s->data;
	p->Next = s->Next;
	free(s);
	return OK;


}

//清空链表
Status ClearList(LinkList *L)
{
	LinkList p,s;
	p = (*L)->Next;

	while(p)
	{	
		s = p->Next;
		free(p);
		p = s;
	}

	(*L)->Next  = NULL;
	return OK;
}

int main()
{
	LinkList L;
	ElemType e;
	Status i;
	int j,k;
	
	//初始化链表结构 
	i =  InitList(&L);
	j =  ListLength(L);
	printf("初始化链表后,长度为:%d\n",j);

	for(j=1;j<=5;j++)
	{
		ListInsert(&L,1,j);
	}

	j =  ListLength(L);
	printf("插入5个元素后,链表长度为:%d\n",j);
	printf("此时链表的数据为:\n");
	ListTraverse(L);

	k = 1;
	i = ListDelete(&L,k,&e);
	if(i == OK)
	{
		printf("删除第%d个元素成功,该元素为%d\n",k,e);
	}else{
		printf("删除第%d个元素失败\n",k);
	}

	k = 4;
	i = ListDelete(&L,k,&e);
	if(i == OK)
	{
		printf("删除第%d个元素成功,该元素为%d\n",k,e);
	}else{
		printf("删除第%d个元素失败\n",k);
	}

	printf("此时链表的数据为:\n");
	ListTraverse(L);

	ClearList(&L);
	j =  ListLength(L);
	printf("清空链表数据后,链表的产度为:%d\n",j);
	printf("此时链表的数据为:\n");
	ListTraverse(L);

	for(j=1;j<=15;j++)
	{
		ListInsert(&L,j,j);
	}

	j =  ListLength(L);
	printf("插入15个元素后,链表长度为:%d\n",j);
	printf("此时链表的数据为:\n");
	ListTraverse(L);

	k = 3;
	i = GetElem(L,k,&e);
	if(i==OK)
	{
		printf("第%d个元素是:%d\n",k,e);
	}else{
		printf("没有查找到第%d个元素\n",k);
	}

	e = 100;
	k = LocateElem(L,e);

	if(k == 0)
	{
		printf("没有查找到节点数据为:%d的节点\n",e);
	}else{
		printf("节点数据为:%d的节点位置为:%d\n",e,k);
	}
	ClearList(&L);
	j =  ListLength(L);
	printf("清空链表数据后,链表的产度为:%d\n",j);
	
	CreateListHead(&L,10);
	printf("头部插入10个节点后数据为:\n");
	ListTraverse(L);
	ClearList(&L);
	j =  ListLength(L);
	printf("清空链表数据后,链表的产度为:%d\n",j);
	
	CreateListTail(&L,10);
	printf("尾部插入10个节点后数据为:\n");
	ListTraverse(L);
	
	
	return 0;
	

	
	 
}