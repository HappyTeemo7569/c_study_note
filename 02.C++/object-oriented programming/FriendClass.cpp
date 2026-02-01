/**********************
友元类
	友元函数是能够访问类中的私有成员的非成员函数。
	友元函数从语法上看，它与普通函数一样，即在定义上和调用上与普通函数一样。
	友元关系不具对称性。即 A 是 B 的友元，但 B 不一定是 A 的友元。
	友元关系不具传递性。即 B 是 A 的友元，C 是 B 的友元，但是 C 不一定是 A 的友元。
作用及特点
	友元提供了不同类的成员函数之间、类的成员函数与一般函数之间进行数据共享的机制。通过友元，一个不同函数或另一个类中的成员函数可以访问类中的私有成员和保护成员。
	友元的正确使用能提高程序的运行效率，但同时也破坏了类的封装性和数据的隐藏性，导致程序可维护性变差。

***********************/

#include<iostream>
#include<cmath>
#define PI 3.14
using namespace std;

//先声明，方便后面定义友元类
class Point;
class MyCircle;

class Point
{
	friend class MyCircle; //声明友元类,所有方法都可以调用点类里面的私有成员了
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	};
	void Getxy();

	//如果不是友元则只能通过这个访问私有变量
	double getX0(){return x;}
	double getY0(){return y;}

	friend double Distance(Point &a, Point &b);  //全局函数作为友元函数
	//friend void MyCircle::showPoint(); 声明某函数的函数作为友元函数
private:
	double x, y;
};

class MyCircle
{
public:
	MyCircle(double r)
	{
		m_r = r;
		MidP.x = 0;
		MidP.y = 0;
	}
public:
	void showPoint();
	void judge(Point &p);
	void setCir(double x, double y, double r);

	double getS()
	{
		m_s = PI*m_r*m_r;
		return m_s;
	}	

private:
	Point MidP;  //圆心
	double m_r;  //圆半径
	double m_s;
};


void Point::Getxy()
{
	cout << "(" << x << "," << y << ")" << endl;
}

void MyCircle::showPoint()
{
	cout << "(" << MidP.x << "," << MidP.y << ")" << endl;
}

void MyCircle::setCir(double x, double y, double r)
{
	//这里面也是类的内部
	MidP.x = x; MidP.y = y; m_r = r;
}

void MyCircle::judge(Point &p)
{
	double s = (MidP.x-p.x)*(MidP.x-p.y) + (MidP.y-p.y)*(MidP.y-p.y) - m_r*m_r ;
	if (s > 0){cout << "out" << endl;}
	else{cout << "int" << endl;}
}


double Distance(Point &a, Point &b)
{
	double dx = a.x - b.x;  //直接访问了私有成员
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
int main(void)
{
	Point p1(3.0, 4.0), p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << "Distance is" << d << endl;

	MyCircle c1(1);
	c1.setCir(0,0,1);
	c1.judge(p1);
	c1.showPoint();

	return 0;
}
