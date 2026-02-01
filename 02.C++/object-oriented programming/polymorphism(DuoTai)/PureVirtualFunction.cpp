/**********************
纯虚函数（Pure Virtual Function）和抽象类（Abstract Class）
纯虚函数：只有声明没有实现的虚函数，并且要在声明部分的后面添加“= 0”。

抽象类：含有纯虚函数的类。
抽象类不能被实例化，即通过抽象类不能定义任意对象，抽象类通常是用来作为其他类的父类使用的，即抽象基类。
	如果一个抽象类的子类不重写其父类中的所有纯虚函数，那么该子类也是抽象类，不能用来定义对象，
	反之它将是一个具体类（concrete class），可以用来定义对象。
***********************/

//可以用纯属函数实现接口，接口中只有函数原型定义，没有任何数据定义。

#include <iostream>
using namespace std;

class figure  //抽象类
{
public:
	virtual  void show_area() = 0 ; //纯虚函数
	void printf()
	{
		cout<<"test"<<endl;
	}

protected:
	double x;
	double y;
};

class tri : public figure     //三角形
{
public:
	tri(double x= 1, double y = 2)     //设定默认值 
	{
		this->x = x;
		this->y = y;
	}

	void show_area()  //子类继承抽象类，只有把所有的纯虚函数都实现了才能实例化。
	{
		cout<<"3_Area:"<<x*y*0.5<<endl;
	}
protected:
private:
};

class square  : public figure   //四边形
{
public:
	square(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"4_Area:"<<x*y<<endl;
	}
protected:
private:
};

class  circle  : public figure     //圆
{
public:
	circle(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"0_Area:"<<3.14*x*x<<endl;
	}
protected:
private:
};

//接口类型，传入一个图形，显示面积。
//比继承更好的框架。
//不要用多继承，代码的复杂性远大于便利。应该配合纯虚函数实现接口。
void objShow(figure *pBase)   //多态的入口
{
	pBase->show_area();
}

int main()
{
	//figure f1;  error，直接用抽象类定义具体的对象（语法规定）
	figure *pBase = NULL;    
	//figure f();  error,抽象类不能作为返回类型
	//void g(figure); error,抽象类不能作为函数参数
	//figure & h(figure &); ok,可以声明抽象类的引用

	tri t1;
	square s1;
	circle c1;
	
	//调用方式1：不用外部函数实现一一对应调用
	figure *i1 = &t1;
	figure *i2 = &s1;
	figure *i3 = &c1;
	i1->show_area();
	i2->show_area() ;
	i3->show_area();
	

	//调用方式2：多态版
	objShow(&t1);
	objShow(&s1);
	objShow(&c1);

	return 0;
}