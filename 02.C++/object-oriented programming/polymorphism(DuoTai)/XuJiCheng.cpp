/**********************
	多态（polymorphism）:多种状态，在面向对象编程中，调用不同对象的同种方法会产生不同的行为。
	多态是通过虚函数实现的。
	多态机制：将子类对象的指针赋给父类指针变量，或将子类对象赋给父类引用，通过父类指针或引用去调用父类中的某个虚函数，
如果子类重写了该虚函数，那么调用的将是子类中的虚函数，否则将调用父类中的虚函数。

	多态成立的三个条件（面向对象编程领域C++，java，.net，php）：
	1.要与继承（子父类 ）
	2.要有virtual重写
	3.要有父类指针指向子类对象

	C函数指针是C++至高无上的荣耀。C函数指针一般有两种用法（正、反）。
***********************/

#include"iostream"
using namespace std;

class base
{
public:
	int k;

	void printI()
	{
		cout << "k1：" << k << endl;;    //没机会，覆盖了
	}
	virtual void printJ()
	{
		cout << "k2：" << k << endl;  //没机会，重写了
	}
	virtual void printK()
	{
		cout << "k3：" << k << endl;  //有机会
	}
protected:
private:

};
//class base1 ，class base2 不加virtual会报错：菱形继承
//两个子类继承同一个父类，而又有子类又分别继承这两个子类
//虚拟继承消除二义性，但是虚拟继承的开销是增加虚函数指针。等于base1和base2都有一份base的拷贝。
//虚函数只是继承了原函数的指针，没有新的形成，非虚则是拷贝了一份。
class base1 :virtual public base
{
public:
	int i;
	void printI()  //覆盖，拷贝了一份
	{
		cout << "i：" << i << endl;
	}
protected:
private:

};

class base2 : virtual public base
{
public:
	int j;
	//默认是虚函数，可以不用加virtual关键字，但为了增加可读性，建议加上virtual关键字修饰。
	void printJ()//重写，添加了虚指针
	{
		cout << "j：" << j << endl;
	}
protected:
private:
};

class  C : public base1, public base2
{
public:
protected:
private:
};

int main()
{

	C c1;
	c1.i = 1;
	//c1.j = 2;
	c1.k = 100;
	
	c1.printI();
	c1.printJ(); //如果j未定义输出垃圾值
	//虚继承调用时候，如果子类没有重写，才会找父类。
	c1.printK();
	return 0;
}