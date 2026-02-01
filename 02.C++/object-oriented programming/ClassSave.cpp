/**********************
类对象中的成员变量和成员函数是分开存储的
成员变量：
普通成员变量：存储于对象中，与struct变量有相同的内存布局和字节对齐方式。
静态成员变量：存储于全局数据区中。
成员函数：存储于代码段中。
***********************/

#include "iostream"
#include <stdio.h>
using namespace std;

class C1
{
public:
	int i; //4
	int j; //4
	int k; //4
protected:
private:
}; //12

class C2
{
public:
	int i; //4
	int j; //4
	int k; //4

	static int m; //4   不占用对象的空间，方在全局区 
public:
	int getK() const { return k; } //函数分配4个字节，方在代码区
	void setK(int val) { k = val; } //

protected:
private:
}; //12

struct S1
{
	int i;
	int j;
	int k;
}; //12

struct S2
{
	int i;
	int j;
	int k;
	static int m; //全局区
}; //12

///////////////////////////
//很多对象公用一块代码？代码是如何区分具体对象的那？
//加了this指针： 类的普通成员函数都隐式包含一个指向当前对象的this指针。（静态成员函数没有）
class Test
{
private:
	int n1;
public:
	Test(int i)
	{
		n1 = i;
	}
	int get1()
	{
		return n1;
	}
	static void Print1()
	{
		printf("This is class1 Test.\n");
	}
};

//编译器将属性抽象为结构体
struct Test2
{
	int n1;
};

//成员函数转成普通函数，带有对象指针
void Test2_init(Test2* pThis,int i)
{
	pThis->n1 = i;
}

int Test2_get1(Test2* pThis)
{
	return pThis->n1;
}

//静态成员函数不带对象指针
void Test2_print()
{
	printf("This is class2 Test.\n");
}


int main()
{
	printf("c1:%d \n", sizeof(C1));
	printf("c2:%d \n", sizeof(C2));
	printf("s1:%d \n", sizeof(S1));
	printf("s2:%d \n", sizeof(S2));

	////////////////////////////
	Test a(10);
	a.get1();
	Test::Print1();

	Test2 a2;
	Test2_init(&a2,20);
	Test2_get1(&a2);
	Test2_print();

	return 0;
}


