/**********************
类的初始化，三种方案：显式 、隐式、构造+析构

构造函数（constructor,构造器）：对新创建对象的数据成员进行初始化。
在定义一个新对象时，根据定义对象的语法形式，有且只有一个匹配的构造函数被自动调用。
构造函数的特点：
1没有返回值。
2.函数名必和类名相同。
3.不能被声明为const的。
4.可以被重载。但是有且只有一个匹配的构造函数会被自动调用。

如果我们在定义类时，不定义任何构造函数，C++编译器会这个类自动添加一个默认的无参构造函数（函数体为空），即这个默认的构造函数什么都不做。
如果我们在定义类时，不定义拷贝构造函数，那么C++编译器会给这个类自动添加一个默认的拷贝构造函数，它实现的就是数据成员的重新赋值，即浅拷贝。要想实现深拷贝，需亲自定义。
带一个参数的构造函数也称为转换构造函数，它可以实现将其他类型数据转换为类的对象。

析构函数（destructor,析构器）：主要执行最后的清理工作，它是一个特殊的成员函数
在一个对象被销毁之前，系统会自动调用其析构函数，等析构函数执行结束返回后系统才会释放该对象所占的存储空间，即该对象被彻底销毁。
析构函数的特点：
1.不允许重载，只有一个。
2.函数名为~和类名构成
3.没有返回值，不带参数。
4.可以被显示调用

连续定义多个对象时，先定义的先构造，后定义的后构造。析构时，先定义的后死，后定义的先死。（栈）

New delete和malloc free 的重要区别
new = malloc+构造；delete = 析构+free
（对于类多用new和delete，对于基本数据类型没什么区别）
1.malloc/free是C/C++语言的标准库函数，new/delete是C++的运算符。
2.new能够自动分配空间大小。

***********************/

#include <iostream>
using namespace std;

class Test88
{
public:
	//自己写，显式
	void init(int a = 0, int b = 0)
	{
		m_a = a;
		m_b = b;
	}

	//有参构造函数
	Test88(int a)
	{
		m_a = a;
	}
	//无参数构造函数
	Test88()
	{
		m_a = 0;
	}
	//四种应用场景
	//赋值构造函数 copy构造函数
	Test88(const Test88 &obj)
	{
		cout<<"GouZao"<<endl;
		m_a = obj.m_a;
	}

	~Test88()
	{
		cout << "XiGou" <<endl;
	}
public:
	void Testprint()
	{
		cout<<"m_a"<<m_a<<endl;
	}
	int GetA() { return m_a ; }
	int GetB() { return m_b ; }
	void SetA(int a) { m_a = a; }
	void SetB(int b) { m_b = b; }
private:
	int m_a;
	int m_b;
};

void f ( Test88  p )    //运行完后，会调用析构函数释放形参
{
	cout << "Funtion:" << p.GetA() << "," << p.GetB() << endl ;
}

Test88 g()
{
	Test88 A(1);
	return A;
	//A是局部的，在其析构前C++编译器创建了一个匿名对象用于接受A对象的数据。
	//赋值完后，A消失 --- 匿名对象消失 ---- T4消失
}

int main()
{
	Test88 b1,b2,b3;
	//显示的初始化对象
	b1.init();
	b2.init();
	b3.init();
	Test88 Array[3] = { b1, b2, b3 };
	for (int i=0;i<3;i++)
	{
		cout << Array[i].GetA() << endl;
	}
	///////////////////////////////////////////////

	Test88 t1;  //默认的就是无参的
	t1.SetA(1);
	t1.Testprint();

	//第一种，赋值构造函数（和=操作是两个不同的概念）
	Test88 t2 = t1; 
	t2.Testprint();  

	//第二种，用t1初始化t2，和第一种差不多
	Test88 t3(t1); 
	t3.Testprint();

	//第三种，实参去构造形参
	Test88 t4(30);
	f(t4);
	t4.Testprint();

	//第四种，返回值构造
	Test88 t5;
	t5 = g();  //此时用的是浅拷贝，就是=操作
	t5.Testprint();

	t2 = t1; //是对象的=操作，系统提供的浅拷贝
	
	return 0;
}