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


//判断栈是否为空
Status StackEmpty(LinkStack S)
{
	if(S.count == 0)
	{
		return TRUE;
	}
	return FALSE;	
} 

//入栈操作 
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

//出栈操作
Status Pop(LinkStack *S,SElemType *e)
{	
	//判断栈是否为空 
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



//初始化链栈 
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

//遍历打印栈
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

//获取栈顶元素 
Status GetTop(LinkStack S,SElemType *e)
{	
	//判断栈是否为空 
	if(StackEmpty(S))
	{
		return ERROR;
	}
	
	*e = S.top->data;
	return OK;	
}

//清空栈 
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
	
	printf("push进去10个元素后,元素为:\n");
	StackTraverse(s);
	Pop(&s,&e);
	printf("pop出的元素为%d\n",e);
	Pop(&s,&e);
	printf("pop出的元素为%d\n",e);
	
	j = StackEmpty(s);
	j==TRUE?printf("栈为空!\n"):printf("栈不为空!\n");
	
	if(GetTop(s,&e) == OK)
	{
		printf("现在的栈顶元素为:%d\n",e);
	}else{
		printf("栈为空,获取栈顶元素失败!");
	}
	
	ClearStack(&s);
	printf("执行情况操作后,");
	j = StackEmpty(s);
	j==TRUE?printf("栈为空!\n"):printf("栈不为空!\n");
	
	if(GetTop(s,&e) == OK)
	{
		printf("现在的栈顶元素为:%d\n",e);
	}else{
		printf("栈为空,获取栈顶元素失败!");
	}
	
	return 0;
} 