#include <iostream>
using namespace std;

class complex
{
private:
	int a,b;
	//通过友元函数（全局函数）实现+操作,
	friend complex operator+(complex &c1, complex &c2);
	//友元函数   全局函数 前置++
	friend complex &operator++(complex &c2);
	//后置++
	friend complex operator++(complex &c2,int); 
public:
	complex(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << "+" << b << "i" << endl;
	}
public:
	//通过类的成员函数实现-操作
	complex operator-(complex &c2)    //this可以不写（内含）
	{
		complex tmp;
		tmp.a = this->a -c2.a;
		tmp.b = b -c2.b;
		return tmp;  //注意返回值
	}

	// 前置--
	complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;//注意返回值
	}
};

complex operator+(complex &c1, complex &c2)
{
	complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

//前置++ 全局函数
complex& operator++(complex &c2)   //返回变量本身，所以用引用
{
	c2.a++;
	c2.b++;
	return c2;
}

//后置++ ：先使用c2，再用属性++
complex operator++(complex &c2,int)   
{
	complex tmp;  //需要一个临时变量
	tmp=c2;
	c2.a++;
	c2.b++;
	return tmp;
}

int main()
{
	complex c1(1, 2), c2(3, 4);

	// +操作符有两个参数 左操作数 和 右操作数
	complex c3 = c1 + c2;
	c3.printCom();
	

	complex c5 = c1 - c2 ; //c1是做操作符，  等价于Complex c5 = c1.operator-(c2);      
	//通过类的成员函数，完成操作符重载
	c5.printCom();
	/*-------------------------------------------------------------------------
	目标 通过类的成员函数，完成操作符重载
	1 要承认操作符重载是一个函数，要写函数原型   operator-
	2 找出需要的函数参数， 写出函数调用语言 c1.operator-(c2)        //Complex c5 = c1 - c2 ;
	3 完善函数原型：返回值
	-------------------------------------------------------------------------- */
	++c2;  //全局变量++
	c2.printCom();
	//全局函数原型推导 //Complex& operator++(Complex &c2);    //Complex& operator++(this,Complex &c2); this指针被隐藏

	c2++;  //后置++
	c2.printCom();

	
	return 0;
}