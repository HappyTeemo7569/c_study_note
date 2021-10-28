/**********************
覆盖override
重载：同一个类中（同一个作用域），重名不同参数的函数。（不能重载父类函数，只会被同名覆盖）是在编译期间根据参数类型和个数决定函数调用。
重写：派生类重新定义基类的虚函数（名字、参数、返回值都一样，不能有static）。多态，在运行期间根据具体对象的类型决定函数调用。
虚函数重载是晚绑定，动态链接编译；否则称为重定义，静态编译。
重写函数的访问修饰符可以不同。（private可以变为public之类的）
***********************/

#include <stdio.h>
#include <iostream>
using namespace std;

class Parent01
{
public:
	Parent01()  //构造函数
	{
		cout << "P1" << endl;
	}
public:
	void func()
	{
		cout << "P1 void" << endl;
	}
	virtual void func(int i)
	{
		cout << "P1 int" << endl;
	}
	virtual void func(int i,int j)
	{
		cout << "P1 2 int" << endl;
	}
	void run01(Parent01* p)
	{
		p->func(1,2);
	}
};

class Child01:public Parent01
{
public:
	void func(int i,int j)
	{
		cout << "C1 2 int" << endl;
	}

	void func(int i,int j,int k)
	{
		cout << "C1 3 int" << endl;
	}
};

int main()
{
	Parent01 p;
	p.func();
	p.func(1);
	p.func(1,2);

	Child01 c;
	//c.func(); //如果父类的函数已经被覆盖，不能再被调用。
	c.Parent01::func();  //这样就是调用父类作用域里面的函数
	c.func(1,2);
	c.func(1,2,3);


	//因为都没有被覆盖，所以父类和子类都可以调用
	p.run01(&p);
	p.run01(&c);

	c.run01(&p);
	c.run01(&c);
}