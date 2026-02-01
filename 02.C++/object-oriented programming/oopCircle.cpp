/**********************
面向对象编程（oop: object-oriented programming）
类（class）-->实例化--->对象（object）：内存中具有类型的区域。
对象拥有：属性（atribute）<静态>和方法（method）<动态>
成员：属性方法对象都称为成员
属性也称为数据成员（data member）或成员变量(member variables)
方法也称为成员函数(member function) 或函数成员

类所占存储空间大小至少为其所有非静态数据成员所占空间的总和，还要考虑内存对齐机制的影响，和结构体大小的分析完全一样。
一个类的所有对象共享一份方法方法代码。 

访问权限修饰符：说明类中成员的访问权限
	Private：私有，只能在类体中访问，(或者通过方法间接调用)。
	Protect：保护，为子类而生。
	Public：公有，都可以访问。
用class定义类，成员默认为私有。
用struct定义类，成员默认为共有。

C++开发规范：
类的声明和实现分离，将类的声明放在头文件中，实现放在源文件中，文件名的主文件名都为类名。
This指针：类中的隐含数据成员，代表当前对象的指针，不占存储空间。

***********************/

/*
//面向过程的方法
//加工数据，入口---函数---出口
void main()
{
	double r;
	double s ;
	cout<<"请键入圆的半径";
	cin>>r;

	s = 3.14*r*r;

	cout<<"圆的面积为："<<s;
	system("pause");
}
================================================================*/
	//c++面向对象编程三大概念 抽象 继承 多态
	//定义一个圆类：
	//数据成员：半径
	//成员函数：置半径值，求圆的半径，求周长，求面积。

struct circle    //抽象一个数据类型（我们自定义了一个数据类型）
{
	double m_r; //属性  //成员变量
	void setR(double r) //方法成员函数
	{
		m_r = r ;
	}

	double getR() //方法
	{
		return m_r;
	}

	double getS() //求面积
	{
		return 3.14*m_r*m_r;
	}
};

void main()
{
	circle c1; // c需要写成   struct  circle c1
	c1.setR(10);  // c1里的m_r=10
	cout<<"半径"<<c1.getR()<<"面积是："<<c1.getS();
	c1.setR(11);
	cout<<"半径"<<c1.getR()<<"面积是："<<c1.getS();
	system("pause");
}

/*易错模型

#include<iostream>
using namespace std;//c++的命名空间

class circle
{
public:
	double r;

	double pi = 3.1415926;
	//double area = pi*r*r;    //错误，初始化=pi*垃圾值*垃圾值

	double getS()           //正确    代码区
	{
		return area = 3.14*r*r;
	}
};
int main()
{
	circle pi;
	cout << "请输入area" << endl;
	//cin >> pi.r;

	cout << pi.area << endl;    //乱码

	pi.r = 100; // r与s互不印象
	pi.getS();
	cout << pi.area << endl;  //r变，s没改

	system("pause");
	return 0;
}
*/

/**********************
类和类之间的关系
1.没关系
2.使用（use a，一个类的部分使用另一个类）。使用私有成员需要：友元类
3.组合关系（包含关系，has a关系）
4.继承关系（父子关系，从属关系，is a 关系）
***********************/