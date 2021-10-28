#include <iostream>
#include <stdio.h>
using namespace std;

class Parent01
{
protected:
	int i;
	int j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};

class Child01 : public Parent01
{  
public:
	int k;    //加了这个， p->f()会宕机。

public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		//printf("Child01::f()...do\n");
		cout << "Child f()" << i << j << endl;
	}
};

void howToF(Parent01 *pBase)           
{
	pBase->f();
}

//指针的步长 在c++领域仍然有效，父类指针的步长和子类指针的步长不一样
//多态是靠迟绑定实现的（vptr+函数指针实现）
int main()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;

	//不要把父类对象还有子类对象同时放在一个数组里面
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};

	/*错误做法：
	//不要用父类指针做赋值指针变量，去遍历一个子类的数组。
	p = ca;
	c = ca;

	p->f();  
	c->f(); //有多态发生

	p++; // p++和c++步长不一样
	c++;

	p->f();//有多态发生，宕机
	c->f();

	//父类vptr指向i,j;子类指向i,j,k;
	*/

	
	//正确做法：
	for (i=0; i<3; i++)
	{
		howToF(&(ca[i]));
	}

	return 0;
}