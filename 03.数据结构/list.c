
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 //线性表最大存储空间，使用数组实现

typedef int Status;    //用Status来表示函数返回状态码,是上面定义的OK等数据状态
typedef int ElemType;    //ElemType是表示我们存储数据的类型，根据情况而定，这里设置为int

typedef struct
{
    ElemType data[MAXSIZE];    //数组存储数据元素
    int length;    //线性表当前长度
}SqList;    //表名

//四个基本操作，初始，清空，判断是否为空，获取长度
Status InitList(SqList* L);
Status ClearList(SqList* L);
Status ListEmpty(SqList L);
int ListLength(SqList L);

//四个元素操作，插入，删除，两种查找
Status GetElem(SqList L,int i,ElemType* e);
int LocateElem(SqList L, ElemType e);
Status ListInsert(SqList* L, int i, ElemType e);
Status ListDelete(SqList* L, int i, ElemType* e);


void PrintList(SqList L);

/*
复习注意：
我们要进行初始，增加，删除，是需要在原来线性表中进行，所以需要用到引用对原数据进行操作，
而对于查找，获取长度，不需要对原来数据进行操作，我们直接对赋值后的局部变量（含有原线性表的所有数据）参数进行操作，即可
*/

//四个基本操作，初始，清空，判断是否为空，获取长度
//初始线性表
Status InitList(SqList* L)
{
    L->length = 0;

    for (int i = 0; i < MAXSIZE; i++)
    {
        L->data[i] = 0;
    }

    return OK;
}

//清空线性表数据
Status ClearList(SqList* L)
{
    L->length = 0;
    for (int i = 0; i < MAXSIZE; i++)
        L->data[i] = 0;

    return OK;
}

//判断列表是否为空
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    return FALSE;
}

//获取线性表的长度
int ListLength(SqList L)
{
    return L.length;
}

//四个元素操作，插入，删除，两种查找
//获取指定位置的元素，返回在指针元素中
Status GetElem(SqList L, int i, ElemType* e)
{
    if (L.length == 0 || i<1 || L.length < i)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

//查找元素在线性表中的位置
int LocateElem(SqList L, ElemType e)
{
    int i = 0;

    if (L.length == 0)
        return 0;

    for (; i < MAXSIZE;i++)
        if (L.data[i] == e)
            break;
    if (i >= MAXSIZE)
        return 0;

    return i+1;    //注意线性表中的位置不是按照数组一样从0开始，而是按照我们正常习惯1开始的
}

//向线性表中指定位置插入元素
Status ListInsert(SqList* L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)//线性表满
        return ERROR;
    if (i<1 || i>L->length+1)
        return ERROR;
    //开始进行插入操作，先判断元素插入位置，在将后面元素向后移动一位，进行插入
    if (i <= L->length)
    {
        for (k = L->length; k >= i;k--)    //只考虑插入到i=1（数组0），会简单点
            L->data[k] = L->data[k - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

//删除指定位置处的元素
Status ListDelete(SqList* L, int i, ElemType* e)
{
    int k;
    if (L->length == 0 || i < 1 || i > L->length)
        return ERROR;

    //删除元素，是将后面元素前移，再将最后的元素删除
    *e = L->data[i - 1];
    if (i < L->length)
    {
        for (k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k];
    }
    L->data[L->length-1] = 0;
    L->length--;

    return OK;
}

//打印链表数据
void PrintList(SqList L)
{
    printf("print list begin...\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\nprint list end...\n");
}


int main()
{
    SqList L;
    ElemType e;
    printf("1.InitList\n");
    InitList(&L);

    printf("2.1 ListInsert 1-10\n");
    for (int i = 1; i <= 10; i++)
        ListInsert(&L, i, i*i + 1);

    printf("2.2 ListInsert 5\n");
    ListInsert(&L, 5, 256);
    printf("2.3 ListInsert 19 Error\n");
    if (ListInsert(&L, 19, 99) == ERROR)
        printf("ListInsert(&L, 19, 99) Error:Out of range");

    PrintList(L);

    printf("3.ListDelete the first:");
    ListDelete(&L, 1, &e);
    printf("%d\n", e);

    printf("4.ListDelete the end:");
    ListDelete(&L, ListLength(L), &e);
    printf("%d\n", e);

    PrintList(L);

    printf("5.1 find element use GetElem by index(6): ");
    GetElem(L, 6, &e);
    printf("%d\n", e);

    printf("5.1 find element:256 index by LocateElem:");
    printf("%d\n", LocateElem(L, 256));

    printf("6.Get List length:%d\n", ListLength(L));

    printf("7.ClearList\n");
    ClearList(&L);
    if (ListEmpty(L)==OK)
        printf("8.ListEmpty\n");

    system("pause");
    return 0;
}
