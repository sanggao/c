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
		for(k=L->length-1;k>=i;k--)
		{
			L->data[k+1] = L->data[k];
		}
	} 
}





int main()
{
	return 0;
} 



