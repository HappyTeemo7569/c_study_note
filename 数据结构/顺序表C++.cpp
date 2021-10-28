
#include <iostream>
#include <cstring>
using namespace std;

template <typename ELEM_TYPE>
class SEQ_LIST
{
private:
    ELEM_TYPE *data;
    int cap;
    int len;

    enum {INIT_SIZE=100, INCREMENT_SIZE=10};

public:
    SEQ_LIST();
    ~SEQ_LIST();

    void Append(const ELEM_TYPE& data);
    void Insert(int pos, const ELEM_TYPE& data);

    void Show();


    template <typename T1>
    friend ostream& operator<<(ostream& o, SEQ_LIST<T1>& sl);
};

template <typename ELEM_TYPE>
SEQ_LIST<ELEM_TYPE>::SEQ_LIST()
{
    this->data=new ELEM_TYPE[INIT_SIZE];
    this->cap=INIT_SIZE;
    this->len=0;
}

template <typename ELEM_TYPE>
SEQ_LIST<ELEM_TYPE>::~SEQ_LIST()
{
    delete []this->data;
    this->cap=0;
    this->len=0;
}

template <typename ELEM_TYPE>
void SEQ_LIST<ELEM_TYPE>::Append(const ELEM_TYPE& data)
{
    if(this->len>=this->cap)
    {
        ELEM_TYPE* p=new ELEM_TYPE[this->cap+INCREMENT_SIZE];
        memcpy(p,this->data,this->cap);
        delete []this->data;
        this->data=p;
        this->cap+=INCREMENT_SIZE;
    }

    this->data[this->len]=data;

    this->len++;
}

template <typename ELEM_TYPE>
void SEQ_LIST<ELEM_TYPE>::Insert(int pos, const ELEM_TYPE& data)
{
    if(this->len>=this->cap)
    {
        ELEM_TYPE* p=new ELEM_TYPE[this->cap+INCREMENT_SIZE];
        memcpy(p,this->data,this->cap);
        delete []this->data;
        this->data=p;
        this->cap+=INCREMENT_SIZE;
    }

    int i;
    for(i=this->len-1;i>=pos;i--)
        this->data[i+1]=this->data[i];

    this->data[pos]=data;

    this->len++;
}

template <typename ELEM_TYPE>
void SEQ_LIST<ELEM_TYPE>::Show()
{
    cout<<"共有"<<this->len<<"个数据元素："<<endl;

    int i;
    for(i=0;i<this->len;i++)
    {
        cout<<this->data[i]<<" ";
    }

    cout<<endl;
}

//类模板的友元函数语法规则
template <typename T1>
ostream& operator<<(ostream& o, SEQ_LIST<T1>& sl)
{
    cout<<"共有"<<sl.len<<"个数据元素："<<endl;

    int i;
    for(i=0;i<sl.len;i++)
    {
        cout<<sl.data[i]<<" ";
    }

    cout<<endl;
}

class Student
{
private:
    int sno;
    string name;
public:
    Student()
    {
    }

    Student(int sno, string name):sno(sno),name(name)
    {
    }

    friend ostream& operator<<(ostream& o, const Student& s);
};

ostream& operator<<(ostream& o, const Student& s)
{
    o<<"("<<s.sno<<","<<s.name<<")";
    return o;
}

int main()
{
    SEQ_LIST<int> sl1;
    SEQ_LIST<Student> sl2;

    Student stu1(1001,string("张三"));
    Student stu2(1002,string("李四"));
    sl2.Append(stu1);
    sl2.Insert(0,stu2);
    //sl2.Show();
    cout<<sl2<<endl;

    int i=1001,j=1002;
    sl1.Append(i);
    sl1.Insert(0,j);
    sl1.Append(1003);

    /*
    sl1.Append(1001);
    sl1.Insert(0,1003);
    sl1.Append(1002);
    */

    //sl1.Show();
    cout<<sl1<<endl;

    return 0;
}
