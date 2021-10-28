
#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 100      //初始容量
#define INCREMENT_SIZE 10  //扩容单位

typedef int ELEM_TYPE; //声明数据元素类型
//或者：#define int datatype;

//声明顺序表数据类型
typedef struct SEQ_LIST
{
    ELEM_TYPE *data; //即 int* data;
    int cap; //顺序表的容量
    int len; //顺序表实际存储的元素的个数

} SEQ_LIST;

//顺序表支持的操作

//创建(初始化)顺序表
void InitList(SEQ_LIST* sl)
{
    sl->data=(ELEM_TYPE*)malloc(INIT_SIZE);  //根据初始容量来申请数据空间
    sl->cap=INIT_SIZE;      //初始容量
    sl->len=0;              //初始长度为0
}

//销毁顺序表
void DestroyList(SEQ_LIST* sl)
{
    free(sl->data); //释放数据空间
    sl->cap=0;      //容量清0
    sl->len=0;      //长度清0
}

//清空顺序表
void ClearList(SEQ_LIST* sl)
{
    sl->len=0;
}

//插入元素

//在尾部插入
void Append(SEQ_LIST* sl, ELEM_TYPE data)
{
    //如果当前顺序表已满，要扩容
    if(sl->len>=sl->cap)
    {
        sl->data=realloc(sl->data,sl->cap+INCREMENT_SIZE);
        sl->cap+=INCREMENT_SIZE;
    }

    sl->data[sl->len]=data;
    sl->len++;
}

//在指定位置插入
void Insert(SEQ_LIST* sl, int pos, ELEM_TYPE data)
{
    //如果当前顺序表已满，要扩容
    if(sl->len>=sl->cap)
    {
        sl->data=realloc(sl->data,sl->cap+INCREMENT_SIZE);
        sl->cap+=INCREMENT_SIZE;
    }

    int i;
    for(i=sl->len-1;i>=pos;i--) sl->data[i+1]=sl->data[i];

    sl->data[pos]=data;
    sl->len++;
}

//删除数据元素
//根据数据元素的值删除
int DeleteByData(SEQ_LIST* sl, ELEM_TYPE data)
{
    int i;
    for(i=0;i<sl->len;i++)
    {
        if(sl->data[i]==data) break;
    }

    if(i==sl->len) return 0; //删除失败返回0

    for(;i<sl->len-1;i++) sl->data[i]=sl->data[i+1];
    sl->len--;
}

//根据数据元素的索引(位置)删除
int DeleteByIndex(SEQ_LIST* sl, int pos)
{
    if(pos<0 || pos>=sl->len) return 0;

    int i;
    for(i=pos;i<sl->len-1;i++) sl->data[i]=sl->data[i+1];

    sl->len--;
}

//修改指定数据元素的值，修改成功返回1，失败返回0
//根据数据元素的值去修改
int UpdateByData(SEQ_LIST* sl, ELEM_TYPE old_data, ELEM_TYPE new_data)
{
    int i;
    for(i=0;i<sl->len;i++)
    {
        if(sl->data[i] == old_data) break;
    }

    if(i == sl->len) return 0;

    sl->data[i] = new_data;
}

//根据数据元素的索引去修改
int UpdateByIndex(SEQ_LIST* sl, int pos, ELEM_TYPE new_data)
{
    if(pos<0 || pos>=sl->len) return 0;
    int i;
    i = pos;
    sl->data[i] = new_data;

}

//遍历顺序表，即访问它的所有数据元素
//visit为访问回调函数，如果它的返回值为0，表示不继续往下遍历，即停止遍历，否则继续往下遍历
void Traverse(SEQ_LIST* sl, int(*visit)(ELEM_TYPE* data))
{
    int i;
    for(i=0;i<sl->len;i++)
    {
        if(!visit(sl->data+i)) break;;
    }
}

int cmp(const void *a,const void *b)
{
    return(*(int*)a-*(int*)b);
}
//排序
void Sort(SEQ_LIST* sl, int(*cmp)(const ELEM_TYPE* a, const ELEM_TYPE* b))
{
    int i = 0;
    int a[100];

        for(i=0;i<sl->len;i++)
        a[i] = sl->data[i];

    qsort(a,sl->len,sizeof(int),(void*)(*cmp));

    for(i=0;i<sl->len;i++)
    printf("%d ",a[i]);

    printf("\n");

}

//逆序
void Reverse(SEQ_LIST* sl)
{

}

//获取顺序表的长度
int GetLength(SEQ_LIST* sl)
{
    return sl->len;
}

//判断顺序表是否为空
int IsEmpty(SEQ_LIST* sl)
{
    return !(sl->len);
}

//访问函数
int ShowAll(ELEM_TYPE* data)
{
    static int cnt=0;

    cnt++;

    if(cnt>=3)
    {
        cnt=0;
        return 0;
    }

    printf("%d ",*data);

    return 1;
}

void Show(SEQ_LIST* sl)
{
    printf("共有%d个数据元素，分别为：\n",sl->len);

    int i;
    for(i=0;i<sl->len;i++)
    {
        printf("%d ",sl->data[i]);
    }

    printf("\n\n");
}

int main()
{
    SEQ_LIST sl1; //sl1为一个顺序表
    SEQ_LIST sl2; //sl2为一个顺序表

    InitList(&sl1);
    InitList(&sl2);

    Append(&sl1,1000);
    Append(&sl1,1020);
    Append(&sl1,1011);
    Append(&sl1,1412);
    Append(&sl1,1234);
    Append(&sl1,1345);
    Append(&sl1,1456);
    Append(&sl1,1255);
    Append(&sl1,1657);
    Append(&sl1,6787);

    UpdateByData(&sl1,1000,1333);
    Show(&sl1);
    Sort(&sl1,(void*)(*cmp));
    UpdateByIndex(&sl1,3,1200);
    Show(&sl1);
    return 0;
}
