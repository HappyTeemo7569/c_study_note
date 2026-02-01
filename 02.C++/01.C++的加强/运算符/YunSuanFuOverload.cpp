/**********************
c++运算符重载规则：
　　不能创造新的运算符
  　在类里面才能定义运算符重载函数。
	不能对基本数据类型重定义运算符。都是针对新增的、自定义类型。
***********************/

#include<iostream>
using namespace std;

class complex //复数类定义
{
public://外部接口
	complex(double r=0.0,double i=0.0)
	{real=r;imag=i;}    //构造函数
	complex operator +(complex c2);//+重载为成员函数
	complex operator -(complex c2);//-重载为成员函数
	void display();//输出复数
private://私有成员
	double real;//复数实部
	double imag;//复数虚部
};

complex complex::operator +(complex c2)//重载函数实现
{
	complex c;
	c.real=c2.real+real;
	c.imag=c2.imag+imag;
	return complex(c.real,c.imag);
}

complex complex::operator -(complex c2)//重载函数实现
{
	complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return complex(c.real,c.imag);
}
//注：调用类的成员函数一定是与某个对象相关的。
void complex::display()
{
	cout<<"("<<real<<","<<imag<<")"<<endl;
}

int main()    //主函数
{
	complex c1(5,4),c2(2,10),c3;//定义算数类的对象
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	c3=c1-c2;   //使用重载运算符完成复数减法
	cout<<"c3=c1-c2=";
	c3.display();
	c3=c1+c2;    //使用重载运算符完成复数加法
	cout<<"c3=c1+c2=";
	c3.display();

	return 0;
}