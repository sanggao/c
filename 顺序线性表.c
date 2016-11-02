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

//��ʼ�����Ա�
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
} 

//��ȡ���Ա�ĳ���
int ListLength(SqList L)
{
	return L.length;
} 

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
	
	//�ж�λ�úϷ���
	if(i<1 || i>L->length)
	{
		return ERROR;
	} 
	
	*e = L->data[i-1];
	
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
/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
    for(i=0;i<L.length;i++)
            visit(L.data[i]);
    printf("\n");
    return OK;
}

//����Ԫ�ص�λ��
Status LocateElem(SqList L,ElemType e)
{	
	int i;
	//�ж����Ա���
	if(L.length == 0)
	{
		return FALSE;
	} 
	for(i=0;i<L.length;i++)
	{
		if(L.data[i] == e)
		{
			return i+1;
		}
	}
	return FALSE;
} 

//�ж����Ա��Ƿ�Ϊ��
Status ListEmpty(SqList L)
{
	if(L.length == 0)
	{
		return TRUE; 
	}
	return FALSE;
} 


//������Ա�
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}
 
SqList Lunion(SqList La,SqList Lb)
{	
	SqList tmp;
	int i,j;
	ElemType e;
	if(La.length == 0)
	{
		tmp = Lb;
	}else if(Lb.length == 0)
	{
		tmp = La;
	}
	
	if(La.length != 0 && Lb.length != 0)
	{
		tmp = La;
		for(i=0;i<Lb.length;i++)
		{
			GetElem(Lb,i+1,&e);
			if(LocateElem(tmp,e) == FALSE)
			{
				ListInsert(&tmp,1,e);
			}
		}
	}
	return tmp;
	
	 
}
 

int main()
{	
	SqList L;
	SqList Lb;
	ElemType e;
	Status i;
	int j,k;
	InitList(&L);
	
    printf("��ʼ��L��L.length=%d\n",L.length);
    
    for(j=1;j<=5;j++)
	{
		i = ListInsert(&L,1,j);
	} 
	
	printf("��L��ͷ���β���1~5֮��,����Ϊ:\n");
	ListTraverse(L);
	
	printf("L�ĳ���Ϊ:%d\n",L.length);
	
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ��:i=%d(1:��,0:��)\n",i);
	
	i = ClearList(&L);
	printf("���L��:L�ĳ���Ϊ%d\n",L.length);
	
	i = ListEmpty(L);
	printf("L�Ƿ�Ϊ��:i=%d(1:��,0:��)\n",i);
	
	for(j=1;j<=10;j++)
	{
		ListInsert(&L,1,j);
	}
	
	printf("��Lĩβ����1~10��Ԫ�غ�,L����Ϊ:");
	ListTraverse(L);
	
	printf("L�ĳ���Ϊ%d\n",L.length);
	
	GetElem(L,5,&e);
	printf("�����Ԫ��Ϊ:%d\n",e);
	
	//����Ԫ��6��λ��
	i = LocateElem(L,5);
	if(i==FALSE)
	{
		printf("û�в鵽Ԫ��Ϊ%d��λ��\n",5);
	}else{
		printf("��%d��λ�õ�Ԫ��Ϊ%d\n",i,5);
	}
	
	//��ȡ���Ա�ĳ��� 
	k = ListLength(L);
	
	printf("���Ա����ڵĳ���Ϊ:%d\n",k);
	for(j=k+1;j>=k-1;j--)
	{	
		ElemType e = 1;
		i = ListDelete(&L,j,&e);
		if(i==OK)
		{
			printf("ɾ����%d��Ԫ�سɹ�,Ԫ��Ϊ:%d\n",j,e);
		}else{
			printf("ɾ����%d��Ԫ��ʧ��!\n",j);
		}
	}
	
	//��������һ�����Ա� 
    InitList(&Lb);
    for(j=6;j<=15;j++)
    {
    	ListInsert(&Lb,1,j);
    }
    printf("La����������:\n");
    ListTraverse(L);
    printf("Lb����������:\n");
    ListTraverse(Lb);
    
   	//���������Ա�ĺϼ� 
    SqList tmp;
    tmp = Lunion(L,Lb);
 	ListTraverse(tmp);


} 



