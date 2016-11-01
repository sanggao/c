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

//��e����L�е�i������Ԫ�ص�ֵ 
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
	if(L->length==MAXSIZE)  //˳�����Ա����� 
		return ERROR;
	if(i<1 || i>L->length+1) //i�ķ�Χ����ȷ
		return ERROR;
	
	//�������λ�ò��ڱ�β��
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



