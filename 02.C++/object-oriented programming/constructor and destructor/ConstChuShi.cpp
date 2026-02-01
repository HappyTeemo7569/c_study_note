#include <iostream>
#include <stdio.h>
using namespace std;

class ABC
{
public:
	ABC(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("ABC construct ..\n");
	}
	~ABC()
	{
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("~ABC() ..\n");
	}
protected:
private:
	int a;
	int b;
	int c;
};


class MyD
{
public:
	MyD():abc1(1,2,3),abc2(4,5,6),m(100)
	{
		cout<<"MyD()"<<endl;
	}
	~MyD()
	{
		cout<<"~MyD()"<<endl;
	}

protected:
private:
	ABC abc1; //c++编译器不知道如何构造abc1,让ABC自己初始化
	ABC abc2;
	const int m;
};


int run()
{
	MyD myD;
	return 0;
}

int main()
{
	run();
	return 0;
}

/**********************
类成员中若有const修饰，必须在对象初始化的时候，给const int m 赋值。
当类成员中含有一个const对象时，或者是一个引用时，他们也必须要通过成员初始化列表进行初始化，
因为这两种对象要在声明后马上初始化，而在构造函数中，做的是对他们的赋值，这样是不被允许的
***********************/