/**********************
继承（inberitance）:在一个已经存在的类的基础上创建一个新类
父类（father class）或基类（base class）
子类（child class）或者派生类（derived class）
子类继承父类，父类派生出子类
子类会无条件获得其父类中所有成员（不包括构造函数和析构函数）,另外子类也可以增加新成员。

3种继承方式：
父类中私有成员在子类不可访问（不可见）
public:共有继承，父类中的公有和保护成员在子类中还是保持不变，（不变）
protected:保护继承，父类中的公有和保护成员在子类中都变为保护的，（升为保护）
private:私有继承，父类中的公有和保护成员在子类中都变为私有的（升为私有）
公有继承最常用，方便多级继承；

父类构造---子类构造----子类析构-----父类析构（先按底盘再按轮子，先拆轮子再拆底盘）

同名覆盖，即重写。 函数重载和覆盖

子类和父类类型转换问题；
1．子类对象可以转型为父类对象，此时子类新增的属性将被截断，因为它们存放在高字节处，其实得到的就是从父类继承的部分。父类对象转型为子类没有意义，因为子类对象所占存储空间往往比父类对象大。
2．父类引用或指针指向子类对象是可以的，此时它们指向的其实是子类对象从父类继承的部分，但反之没有意义。

一级继承
多级继承：直接子类，间接子类；直接父类，间接父类
单继承（single inheritance）:子类的直接父类只有一个。
多重继承(multiple inheritance)：子类的直接父类有多个。
多重继承的例子：骡子继承了马和驴的特点
会形成菱形继承，虚继承可以避免 virtual
***********************/

#include<cstdlib>
#include<iostream>

using namespace std;

class A
{
private:
	int a;
	friend void SetAA(A *a,int m_b);//全局函数当友元
protected:
	int b;
public:
	int c;

	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void print()
	{
		cout<<"a"<<a<<"b"<<b<<endl;
	}
};

class B : public A
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err   
		cout<<"Bb = "<< b;  //子类内部 从A类public 在A中是protected
		cout<<"Bc = "<< c << endl; //子类内部 从A类public 在A中是public
	}
};

class C : protected A
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err   子类内部 从A类protected 在A中是private
		cout<<"Cb = "<<b;      //   子类内部 从A类protected 在A中是protected
		cout<<"Cc = "<<c <<endl;   //   子类内部 从A类protected 在A中是protected
	}
};

class D : private A
{
public:
	void print()
	{
		//cout<<"Da = "<<a; //err    子类内部 从A类private 在A中是private
		cout<<"Db = "<<b;  //ok  子类内部 从A类private 在A中是private 在子类里变成是私有=子类内部可以使用
		cout<<"Dc = "<<c<<endl;  //ok 子类内部 从A类private 在A中是private 在子类里变成是私有=子类内部可以使用
	}
};

void SetAA(A *a,int m_b)
{
	cout << "serAA" << a->a << endl;;
	return;
}


int main()
{
	A aa;  //基类     //成员：a私有b保护c公有
	B bb;  //公有继承 //成员：b保护c公有
	C cc;  //保护继承 //成员：b保护c保护
	D dd;  //私有继承 //成员：b私有c私有
	

	aa.c = 100; //ok  
	bb.c = 100; //ok   子类外部  从A类public 在A中是public
	//cc.c = 100; //err  子类外部  从A类protected 在A中是public  -》转为protected  子类外部不可以调用
	//dd.c = 100; //err  子类外部  从A类public 在A中是public   -》转为private  

	aa.set(1, 2, 3);
	bb.set(10, 20, 30); // ok    bb调A的set方法  子类外部  从A类public 在A中是public
	//cc.set(40, 50, 60); //err   子类外部  从A类protected 在A中是public  -》转为protected  子类外部不可以调用 子类的内部使用
	//dd.set(70, 80, 90); //err   子类外部  从A类public 在A中是public   -》转为private     子类外部不可以调用 子类的内部使用

	bb.print();  //ok，它自己的public
	cc.print();	 //ok，它自己的public
	dd.print();  //ok，它自己的public
		
	//子类是一个特殊的父类，子类可以当父类=>赋值兼容性原则

	SetAA(&aa, 1);
	SetAA(&bb, 1);  // 把孩子的值传给父亲的友函数，不报错

	//////////////////////////
	A *pA = NULL;  //父类的指针指向子类
	pA = &bb;
	pA->print();

	A &myb = bb;  //父类的引用指向子类
	myb.print();


	return 0;
}