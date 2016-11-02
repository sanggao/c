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

//获取线性表的长度
int ListLength(SqList L)
{
	return L.length;
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

//查找元素的位置
Status LocateElem(SqList L,ElemType e)
{	
	int i;
	//判断线性表长度
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

//判断线性表是否为空
Status ListEmpty(SqList L)
{
	if(L.length == 0)
	{
		return TRUE; 
	}
	return FALSE;
} 


//清空线性表
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
	
    printf("初始化L后：L.length=%d\n",L.length);
    
    for(j=1;j<=5;j++)
	{
		i = ListInsert(&L,1,j);
	} 
	
	printf("在L表头依次插入1~5之后,数据为:\n");
	ListTraverse(L);
	
	printf("L的长度为:%d\n",L.length);
	
	i = ListEmpty(L);
	printf("L是否为空:i=%d(1:是,0:否)\n",i);
	
	i = ClearList(&L);
	printf("清空L后:L的长度为%d\n",L.length);
	
	i = ListEmpty(L);
	printf("L是否为空:i=%d(1:是,0:否)\n",i);
	
	for(j=1;j<=10;j++)
	{
		ListInsert(&L,1,j);
	}
	
	printf("在L末尾插入1~10个元素后,L数据为:");
	ListTraverse(L);
	
	printf("L的长度为%d\n",L.length);
	
	GetElem(L,5,&e);
	printf("低五个元素为:%d\n",e);
	
	//查找元素6的位置
	i = LocateElem(L,5);
	if(i==FALSE)
	{
		printf("没有查到元素为%d的位置\n",5);
	}else{
		printf("第%d个位置的元素为%d\n",i,5);
	}
	
	//获取线性表的长度 
	k = ListLength(L);
	
	printf("线性表现在的长度为:%d\n",k);
	for(j=k+1;j>=k-1;j--)
	{	
		ElemType e = 1;
		i = ListDelete(&L,j,&e);
		if(i==OK)
		{
			printf("删除第%d个元素成功,元素为:%d\n",j,e);
		}else{
			printf("删除第%d个元素失败!\n",j);
		}
	}
	
	//构造另外一个线性表 
    InitList(&Lb);
    for(j=6;j<=15;j++)
    {
    	ListInsert(&Lb,1,j);
    }
    printf("La的数据如下:\n");
    ListTraverse(L);
    printf("Lb的数据如下:\n");
    ListTraverse(Lb);
    
   	//求两个线性表的合集 
    SqList tmp;
    tmp = Lunion(L,Lb);
 	ListTraverse(tmp);


} 



