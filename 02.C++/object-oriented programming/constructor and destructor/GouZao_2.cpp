#include <iostream>
#include <stdio.h>
using namespace std;

class DD
{
public:
	DD(int d) //DD中定义了有参构造函数
	{
		cout<<d<<endl;  //输出1,2
		m_d = d;
	}
private:
	int m_d;
};

class EE
{
public:
	//构造函数的初始化列表
	EE(int _a):d1(1),d2(2)//或是写成EE(int _a):d1(2),d2(1)，调用顺序1.按照变量定义的顺序去初始化变量d
	{
		//调用顺序2.调用构造函数里的内容
		a = _a;
		cout<<_a<<endl; //输出3
	}

protected:
private:
	int a;
	DD d1;  //按照变量定义的顺序
	DD d2;
};

int main()
{
	EE e1(3);
	return 0;	
}

//输出结果1、2、3  即(d1、d2、e1)
//如果有一个类成员，本身是一个类或结构，而且该成员只有一个带参数的构造函数，没有默认构造函数。
//这种情况初始化的时候就必须先调用该类成员的带参构造函数。如果没有初始化列表，那么将报错。
