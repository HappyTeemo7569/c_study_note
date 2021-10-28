
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 //���Ա����洢�ռ䣬ʹ������ʵ��

typedef int Status;    //��Status����ʾ��������״̬��,�����涨���OK������״̬
typedef int ElemType;    //ElemType�Ǳ�ʾ���Ǵ洢���ݵ����ͣ����������������������Ϊint

typedef struct
{
    ElemType data[MAXSIZE];    //����洢����Ԫ��
    int length;    //���Ա�ǰ����
}SqList;    //����

//�ĸ�������������ʼ����գ��ж��Ƿ�Ϊ�գ���ȡ����
Status InitList(SqList* L);
Status ClearList(SqList* L);
Status ListEmpty(SqList L);
int ListLength(SqList L);

//�ĸ�Ԫ�ز��������룬ɾ�������ֲ���
Status GetElem(SqList L,int i,ElemType* e);
int LocateElem(SqList L, ElemType e);
Status ListInsert(SqList* L, int i, ElemType e);
Status ListDelete(SqList* L, int i, ElemType* e);


void PrintList(SqList L);

/*
��ϰע�⣺
����Ҫ���г�ʼ�����ӣ�ɾ��������Ҫ��ԭ�����Ա��н��У�������Ҫ�õ����ö�ԭ���ݽ��в�����
�����ڲ��ң���ȡ���ȣ�����Ҫ��ԭ�����ݽ��в���������ֱ�ӶԸ�ֵ��ľֲ�����������ԭ���Ա���������ݣ��������в���������
*/

//�ĸ�������������ʼ����գ��ж��Ƿ�Ϊ�գ���ȡ����
//��ʼ���Ա�
Status InitList(SqList* L)
{
    L->length = 0;

    for (int i = 0; i < MAXSIZE; i++)
    {
        L->data[i] = 0;
    }

    return OK;
}

//������Ա�����
Status ClearList(SqList* L)
{
    L->length = 0;
    for (int i = 0; i < MAXSIZE; i++)
        L->data[i] = 0;

    return OK;
}

//�ж��б��Ƿ�Ϊ��
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    return FALSE;
}

//��ȡ���Ա�ĳ���
int ListLength(SqList L)
{
    return L.length;
}

//�ĸ�Ԫ�ز��������룬ɾ�������ֲ���
//��ȡָ��λ�õ�Ԫ�أ�������ָ��Ԫ����
Status GetElem(SqList L, int i, ElemType* e)
{
    if (L.length == 0 || i<1 || L.length < i)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

//����Ԫ�������Ա��е�λ��
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

    return i+1;    //ע�����Ա��е�λ�ò��ǰ�������һ����0��ʼ�����ǰ�����������ϰ��1��ʼ��
}

//�����Ա���ָ��λ�ò���Ԫ��
Status ListInsert(SqList* L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)//���Ա���
        return ERROR;
    if (i<1 || i>L->length+1)
        return ERROR;
    //��ʼ���в�����������ж�Ԫ�ز���λ�ã��ڽ�����Ԫ������ƶ�һλ�����в���
    if (i <= L->length)
    {
        for (k = L->length; k >= i;k--)    //ֻ���ǲ��뵽i=1������0������򵥵�
            L->data[k] = L->data[k - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

//ɾ��ָ��λ�ô���Ԫ��
Status ListDelete(SqList* L, int i, ElemType* e)
{
    int k;
    if (L->length == 0 || i < 1 || i > L->length)
        return ERROR;

    //ɾ��Ԫ�أ��ǽ�����Ԫ��ǰ�ƣ��ٽ�����Ԫ��ɾ��
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

//��ӡ��������
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
