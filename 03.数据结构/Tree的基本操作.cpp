
#include <iostream>
using namespace std;

typedef char VAL_TYPE; //说明此二叉树用来存放字符数据

typedef struct Node
{
    VAL_TYPE data;

    Node* parent;
    Node* lchild;
    Node* rchild;

} Node, *BT;

//创建二叉树
void CreateBT(BT* bt, Node* parent)
{
    char c;
    cin.get(c);

    if(c==' ') *bt=NULL;
    else
    {
        //创建根节点
        *bt=new Node;
        (*bt)->data=c;
        (*bt)->parent=parent;

        //分别创建左子树和右子树
        CreateBT(&((*bt)->lchild),*bt);
        CreateBT(&((*bt)->rchild),*bt);
    }
}

//销毁二叉树
void DestroyBT(BT bt)
{
    if(bt!=NULL)
    {
        DestroyBT(bt->lchild); //销毁左子树
        DestroyBT(bt->rchild); //销毁右子树
        delete bt;             //销毁根节点，注意要放在销毁子树之后进行
    }
}

//先序遍历
void PreOrder(BT bt, int(*visit)(char&))
{
    if(bt!=NULL)
    {
        if(!visit(bt->data)) return; //访问根节点
        PreOrder(bt->lchild,visit);  //先序遍历左子树
        PreOrder(bt->rchild,visit);  //先序遍历右子树
    }
}

//中序遍历
void InOrder(BT bt, int(*visit)(char&))
{
    if(bt!=NULL)
    {
        InOrder(bt->lchild,visit);   //中序遍历左子树
        if(!visit(bt->data)) return; //访问根节点
        InOrder(bt->rchild,visit);   //中序遍历右子树
    }
}

//后序遍历
void PostOrder(BT bt, int(*visit)(char&))
{
    if(bt!=NULL)
    {
        PostOrder(bt->lchild,visit);   //后序遍历左子树
        PostOrder(bt->rchild,visit);   //后序遍历右子树
        if(!visit(bt->data)) return;   //访问根节点
    }
}

int show(char& c)
{
    cout<<c<<' ';
    return 1;
}

int main()
{
    BT bt;

    cout<<"请按照先序遍历方式依次输入各个节点的值："<<endl;
    CreateBT(&bt,NULL);


    cout<<"先序遍历序列：";
    PreOrder(bt,show);
    cout<<endl;

    cout<<"中序遍历序列：";
    InOrder(bt,show);
    cout<<endl;

    cout<<"后序遍历序列：";
    PostOrder(bt,show);
    cout<<endl;

    DestroyBT(bt);

    return 0;
}
