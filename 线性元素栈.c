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

//入栈操作 
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

//出栈操作 
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

//遍历栈元素 
void StackTraverse(Stack S)
{
	int i;
	for(i=0;i<=S.top;i++)
	{
		printf("%d ",S.data[i]);
	}
	printf("\n");
}

//判断栈为空
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
	
	printf("遍历栈元素为:");
	StackTraverse(S);
	
	Pop(&S,&e);
	printf("出栈的元素是%d\n",e);
	
	j = StackEmpty(S);
	if(j==TRUE)
	{
		printf("栈为空!\n");
	}else{
		printf("栈不为空!\n");
	}
	
	e = GetTop(S);
	
	if(e == ERROR)
	{
		printf("栈为空,获取失败!\n");
	}else{
		printf("栈顶元素为%d\n",e);
	}
	
	ClearStack(&S);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(S));
	
	
} 

