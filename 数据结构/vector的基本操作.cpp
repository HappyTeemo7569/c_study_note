
#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int sno;
    char name[31];
};

int main()
{
    vector<int> a1;
    vector<float> a2;
    vector<Student> stus;

    a1.push_back(2001);
    a1.push_back(2002);
    a1.push_back(2004);


    //通过迭代器遍历容器中的数据元素
    vector<int>::iterator it; //定义一个迭代器
    for(it=a1.begin();it!=a1.end();it++)
    {
        if(*it==2002) a1.erase(it); //删除值为2002的数据元素
        if(*it==2004) *it=2008;     //将值为2004的数据元素改为2008
        //cout<<*it<<' ';
    }

    cout<<endl;

    //使用反向迭代器可以反向遍历容器
    vector<int>::reverse_iterator rit;
    for(rit=a1.rbegin();rit!=a1.rend();rit++)
    {
        cout<<*rit<<' ';
    }
    cout<<endl;

    a2.push_back(3.14);
    a2.push_back(1.2);
    a2.push_back(-10.899);

    //通过下标也可以遍历vector容器
    int i;
    for(i=0;i<a2.size();i++)
    {
        a2[i]++;
        cout<<a2[i]<<' ';
    }

    cout<<endl;

    cout<<a1.size()<<endl;
    cout<<a2.size()<<endl;

    return 0;
}
