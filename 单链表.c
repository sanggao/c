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

//��ʼ������ 
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(!(*L))
	{
		return ERROR;  //�����ڴ�ʧ�� 
	}
	
	(*L)->Next = NULL;
	return OK;	
}

//��ȡ������
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

//��������
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

//����Ԫ������
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

//����һ���ڵ�
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

//�������n��Ԫ�ص�ֵ,��������ͷ�ڵ�ĵ���������L
void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));  //���������
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

//�������N��Ԫ��,β�Ͳ��뷨 
void CreateListTail(LinkList *L,int n)
{
	LinkList p,s;
	int i;
	srand(time(0));  //���������
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




//���ҽڵ�
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

//ɾ��ĳ���ڵ�Ԫ��
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

	//�˿�p�����i-1��Ԫ��
	s = p->Next;
	*e = s->data;
	p->Next = s->Next;
	free(s);
	return OK;


}

//�������
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
	
	//��ʼ������ṹ 
	i =  InitList(&L);
	j =  ListLength(L);
	printf("��ʼ�������,����Ϊ:%d\n",j);

	for(j=1;j<=5;j++)
	{
		ListInsert(&L,1,j);
	}

	j =  ListLength(L);
	printf("����5��Ԫ�غ�,������Ϊ:%d\n",j);
	printf("��ʱ���������Ϊ:\n");
	ListTraverse(L);

	k = 1;
	i = ListDelete(&L,k,&e);
	if(i == OK)
	{
		printf("ɾ����%d��Ԫ�سɹ�,��Ԫ��Ϊ%d\n",k,e);
	}else{
		printf("ɾ����%d��Ԫ��ʧ��\n",k);
	}

	k = 4;
	i = ListDelete(&L,k,&e);
	if(i == OK)
	{
		printf("ɾ����%d��Ԫ�سɹ�,��Ԫ��Ϊ%d\n",k,e);
	}else{
		printf("ɾ����%d��Ԫ��ʧ��\n",k);
	}

	printf("��ʱ���������Ϊ:\n");
	ListTraverse(L);

	ClearList(&L);
	j =  ListLength(L);
	printf("����������ݺ�,����Ĳ���Ϊ:%d\n",j);
	printf("��ʱ���������Ϊ:\n");
	ListTraverse(L);

	for(j=1;j<=15;j++)
	{
		ListInsert(&L,j,j);
	}

	j =  ListLength(L);
	printf("����15��Ԫ�غ�,������Ϊ:%d\n",j);
	printf("��ʱ���������Ϊ:\n");
	ListTraverse(L);

	k = 3;
	i = GetElem(L,k,&e);
	if(i==OK)
	{
		printf("��%d��Ԫ����:%d\n",k,e);
	}else{
		printf("û�в��ҵ���%d��Ԫ��\n",k);
	}

	e = 100;
	k = LocateElem(L,e);

	if(k == 0)
	{
		printf("û�в��ҵ��ڵ�����Ϊ:%d�Ľڵ�\n",e);
	}else{
		printf("�ڵ�����Ϊ:%d�Ľڵ�λ��Ϊ:%d\n",e,k);
	}
	ClearList(&L);
	j =  ListLength(L);
	printf("����������ݺ�,����Ĳ���Ϊ:%d\n",j);
	
	CreateListHead(&L,10);
	printf("ͷ������10���ڵ������Ϊ:\n");
	ListTraverse(L);
	ClearList(&L);
	j =  ListLength(L);
	printf("����������ݺ�,����Ĳ���Ϊ:%d\n",j);
	
	CreateListTail(&L,10);
	printf("β������10���ڵ������Ϊ:\n");
	ListTraverse(L);
	
	
	return 0;
	

	
	 
}