#include <stdio.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 30
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

typedef struct Stack
{
	SElemType data [MAXSIZE];
	int top;
			
}Stack;


Status InitStack(Stack *S)
{
	S->top = -1;
	return OK;
}

//��ջ���� 
Status Push(Stack *S,SElemType e)
{
	int i = S->top+1;
	if(i == MAXSIZE)
	{
		return ERROR;
	}
	
	S->data[i] = e;
	S->top = i;
	return OK;
} 

//��ջ���� 
Status Pop(Stack *S,SElemType *e)
{
	if(S->top == -1)
	{
		return ERROR;
	}
	
	*e = S->data[S->top];
	S->top--;
	return OK;
}

//����ջԪ�� 
void StackTraverse(Stack S)
{
	int i;
	for(i=0;i<=S.top;i++)
	{
		printf("%d ",S.data[i]);
	}
	printf("\n");
}

//�ж�ջΪ��
Status StackEmpty(Stack S)
{
	if(S.top == -1)
	{
		return TRUE;
	}
	
	return FALSE;
} 

SElemType GetTop(Stack S)
{
	if(S.top == -1)
	{
		return ERROR;
	}
	
	return S.data[S.top];
}

Status ClearStack(Stack *S)
{
	S->top = -1;
	
	return OK; 
}

int main()
{	
	Stack S; 
	int j;
	SElemType e;
	
	
	InitStack(&S);
	for(j=1;j<=10;j++)
	{
		Push(&S,j);
	}
	
	printf("����ջԪ��Ϊ:");
	StackTraverse(S);
	
	Pop(&S,&e);
	printf("��ջ��Ԫ����%d\n",e);
	
	j = StackEmpty(S);
	if(j==TRUE)
	{
		printf("ջΪ��!\n");
	}else{
		printf("ջ��Ϊ��!\n");
	}
	
	e = GetTop(S);
	
	if(e == ERROR)
	{
		printf("ջΪ��,��ȡʧ��!\n");
	}else{
		printf("ջ��Ԫ��Ϊ%d\n",e);
	}
	
	ClearStack(&S);
    printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(S));
	
	
} 

