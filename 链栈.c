#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

typedef struct StackNode
{
	SElemType data;
	struct StackNode *Next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{	
	LinkStackPtr top;
	int count;
}LinkStack;


//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S)
{
	if(S.count == 0)
	{
		return TRUE;
	}
	return FALSE;	
} 

//��ջ���� 
Status Push(LinkStack *S,SElemType e)
{
	LinkStackPtr L;
	L = (LinkStackPtr)malloc(sizeof(StackNode));
	L->data = e;
	
	L->Next = S->top;
	S->top = L;
	S->count++;
	return OK;
}

//��ջ����
Status Pop(LinkStack *S,SElemType *e)
{	
	//�ж�ջ�Ƿ�Ϊ�� 
	if(StackEmpty(*S))
	{
		return ERROR;
	}

	LinkStackPtr L; 
	
	L = S->top;
	*e = L->data;
	S->top = L->Next;
	free(L);
	S->count--;
	return OK;
} 



//��ʼ����ջ 
Status InitLinkStack(LinkStack *S)
{	
	S->top =  (LinkStackPtr)malloc(sizeof(StackNode));
	if(!S->top)
	{
		return ERROR;
	}
	S->top = NULL;
	S->count = 0;
	return OK;
}

//������ӡջ
void StackTraverse(LinkStack S)
{	
	LinkStackPtr p = S.top;
	while(p)
	{
		printf("%d ",p->data);
		p = p->Next;
	}
	printf("\n");
	
} 

//��ȡջ��Ԫ�� 
Status GetTop(LinkStack S,SElemType *e)
{	
	//�ж�ջ�Ƿ�Ϊ�� 
	if(StackEmpty(S))
	{
		return ERROR;
	}
	
	*e = S.top->data;
	return OK;	
}

//���ջ 
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p;
	while(S->top)
	{
		p = S->top;
		S->top = p->Next;
		free(p);
		S->count--;
	}
	return OK;
}

int main()
{	
	
	LinkStack s;
	SElemType e;
	int j;
	
	if(InitLinkStack(&s) == OK)
	{
		for(j=1;j<=10;j++)
		{
			Push(&s,j);
		}
	}
	
	printf("push��ȥ10��Ԫ�غ�,Ԫ��Ϊ:\n");
	StackTraverse(s);
	Pop(&s,&e);
	printf("pop����Ԫ��Ϊ%d\n",e);
	Pop(&s,&e);
	printf("pop����Ԫ��Ϊ%d\n",e);
	
	j = StackEmpty(s);
	j==TRUE?printf("ջΪ��!\n"):printf("ջ��Ϊ��!\n");
	
	if(GetTop(s,&e) == OK)
	{
		printf("���ڵ�ջ��Ԫ��Ϊ:%d\n",e);
	}else{
		printf("ջΪ��,��ȡջ��Ԫ��ʧ��!");
	}
	
	ClearStack(&s);
	printf("ִ�����������,");
	j = StackEmpty(s);
	j==TRUE?printf("ջΪ��!\n"):printf("ջ��Ϊ��!\n");
	
	if(GetTop(s,&e) == OK)
	{
		printf("���ڵ�ջ��Ԫ��Ϊ:%d\n",e);
	}else{
		printf("ջΪ��,��ȡջ��Ԫ��ʧ��!");
	}
	
	return 0;
} 