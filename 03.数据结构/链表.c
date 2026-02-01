
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int sno;
    char name[31];
    int age;
};

//声明节点数据域的类型
//typedef struct Student VAL_TYPE;
typedef int VAL_TYPE;

//声明节点类型
typedef struct Node
{
    VAL_TYPE data;     //数据域
    struct Node* next; //指针域
    //struct Node* prior; //双向链表会增加一个指针域，指向直接前驱

} Node,*LINK_LIST;

//链表支持的操作

//创建(初始化)链表
void InitList(LINK_LIST* ll)
{
    //创建一个头结点，该头结点不用来存放数据
    *ll=malloc(sizeof(Node));
    (*ll)->next=NULL;
}

//销毁链表
void DestroyList(LINK_LIST ll) //ll为链表的头指针，头指针可以代表整个链表
{
    Node* p=NULL;

    while(ll!=NULL)
    {
        p=ll->next;
        free(ll);
        ll=p;
    }
}

//清空链表(只保留头结点)
void ClearList(LINK_LIST ll) //ll为链表的头指针
{
    DestroyList(ll->next);
    ll->next=NULL;
}

//插入节点

//尾插
void Append(LINK_LIST ll, VAL_TYPE val)
{
    //创建新节点
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->next=NULL;

    //遍历链表，找到尾节点
    while(ll->next!=NULL) ll=ll->next; //循环结束后ll就是尾节点的指针

    //将新节点插入链表尾部
    ll->next=new_node;
}

//头插
void Insert(LINK_LIST ll, VAL_TYPE val)
{
    //创建新节点
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->next=ll->next;

    //将新节点插入到头结点之后，即插入后它将称为第一个节点
    ll->next=new_node;
}

//中插
//在节点n之后插入新节点
void InsertByPos(Node* n, VAL_TYPE val)
{
    //创建新节点
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->next=n->next;

    //将新节点插入到头结点之后，即插入后它将称为第一个节点
    n->next=new_node;
}

//通过节点索引插入新节点
void InsertByIndex(LINK_LIST ll, int index, VAL_TYPE val)
{
    //找到指定索引对应的节点
    while(index-- && ll->next!=NULL)
    {
        ll=ll->next;
    }

    //创建新节点
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=val;
    new_node->next=ll->next;

    //将新节点插入指定索引的节点之后
    ll->next=new_node;
}

//删除指定节点
//删除成功返回1，失败返回0
int Delete(LINK_LIST ll, VAL_TYPE val)
{
    while(ll->next!=NULL && ll->next->data!=val) ll=ll->next;

    if(ll->next==NULL) return 0;

    //循环结束后ll指向待删除节点的直接前驱

    Node* p=ll->next->next;
    free(ll->next);
    ll->next=p;

    return 1;
}

//修改指定节点的数据域
//修改成功返回1，否则返回0
int Update(LINK_LIST ll, VAL_TYPE old_val, VAL_TYPE new_val)
{
    ll=ll->next;

    while(ll!=NULL && ll->data!=old_val)
    {
        ll=ll->next;
    }

    if(NULL==ll) return 0;

    ll->data=new_val;

    return 1;
}

//遍历链表
void Traverse(LINK_LIST ll, int(*visit)(VAL_TYPE* val))
{
    ll=ll->next;

    while(ll!=NULL)
    {
        if(!visit(&(ll->data))) break;

        ll=ll->next;
    }
}

//排序
void Sort(LINK_LIST ll, int(*cmp)(const VAL_TYPE* a, const VAL_TYPE* b))
{
    Node *p=ll->next,*q=NULL,*k=NULL;

    for(;p->next!=NULL;p=p->next)
    {
        k=p;

        for(q=p->next;q!=NULL;q=q->next)
        {
            if(cmp(&(k->data),&(q->data))>0) k=q;
        }

        if(k!=p)
        {
            VAL_TYPE tmp=p->data;
            p->data=k->data;
            k->data=tmp;
        }
    }
}

//逆序
void Reverse(LINK_LIST ll)
{
    /*
    //算法1：
    if(ll->next==NULL) return; //如果链表为空，直接返回

    Node* p=ll->next->next,*q=NULL;

    ll->next->next=NULL;

    while(p!=NULL)
    {
        q=p->next;
        p->next=ll->next;
        ll->next=p;
        p=q;;
    }
    */

    //算法2：
    Node *p=NULL,*q=ll->next,*t;

    while(q!=NULL)
    {
        t=q->next;
        q->next=p;
        p=q;
        q=t;
    }

    ll->next=p;
}

//获取链表长度
int GetLength(LINK_LIST ll)
{
    int cnt=0;

    ll=ll->next;

    while(ll!=NULL)
    {
        cnt++;
        ll=ll->next;
    }

    return cnt;
}

//判断链表是否为空
int Empty(LINK_LIST ll)
{
    return !(ll->next);
}

void Show(LINK_LIST ll)
{
    int cnt=0;

    ll=ll->next;

    while(ll!=NULL)
    {
        printf("%d ",ll->data);

        cnt++;
        ll=ll->next;
    }

    printf("\n共有%d个节点！\n\n",cnt);
}

int cmp(const int* a, const int* b)
{
    return *a-*b;
}

int cmp_desc(const int* a, const int* b)
{
    return *b-*a;
}

int main()
{
    LINK_LIST l1;

    InitList(&l1);

    if(Empty(l1))
    {
        printf("链表为空！\n");
    }

    Append(l1,2001);
    Insert(l1,2003);
    Append(l1,2002);

    InsertByIndex(l1,0,2004);
    InsertByIndex(l1,2,2004);
    InsertByIndex(l1,100,2005);

    Show(l1);

    //Sort(l1,cmp_desc);
    Reverse(l1);
    Show(l1);

    /*
    Delete(l1,2001);
    Delete(l1,2004);
    if(!Delete(l1,3000))
    {
        printf("删除失败！\n");
    }

    Show(l1);

    printf("链表长度为%d\n",GetLength(l1));
    */

    DestroyList(l1);

    return 0;
}
