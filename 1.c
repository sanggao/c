#include<stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

//初始化线性表
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
} 

//用e返回L中第i个数据元素的值 
Status GetElem (SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];
	return OK;
}


Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if(L->length==MAXSIZE)  //顺序线性表已满 
		return ERROR;
	if(i<1 || i>L->length+1) //i的范围不正确
		return ERROR;
	
	//若插入的位置不在表尾巴
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1] = L->data[k];
		}
	}
	L->data[i-1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;
	
	if(L->length == 0)
	{
		return ERROR;
	}
	
	//判断位置合法性
	if(i<1 || i>L->length)
	{
		return ERROR;
	} 
	
	e = L->data[i-1];
	
	if(i<L->length)
	{
		/*for(k=i-1;k<L.length-1;k++)
		{
			L.data[k] = L.data[k+1];			
		}*/
		
		for(k=i;k<L->length;k++)
		{
			L->data[k-1] = L->data[k];
		}
		
	}
	L->length--;
	return OK;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
}


int main()
{	
	SqList L;
	ElemType e;
	Status i;
	int j,k;
	InitList(&L);
	
	ListInsert(&L,1,10);
	ListInsert(&L,2,11);
	ListInsert(&L,3,12);
	
	ListTraverse(L);
	//GetElem (L,3,&e);
	//printf("%d\n",e);

} 



