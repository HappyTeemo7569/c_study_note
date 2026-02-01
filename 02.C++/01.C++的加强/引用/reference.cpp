/**********************
1.变量名

* 实质就是一段连续存储空间的别名，一个标号。
* 程序中通过变量来申请并命名内存空间。
* 通过变量的名字来使用存储空间。
* 一段连续的内存空间只能取一个名字么？不是，引用就是别名。


2.引用的概念

* 语法：Type & name = var;    int &b = a;
* 可以看做是别名，本质上是指针常量，指针指向的地址不变，地址里面的内容可以变。Type& name  等同于Type* const name
* 所以引用占用的空间大小和指针相同（看起来好像没有自己的存储空间，其实是细节隐藏）。引用使用的时候必须初始化。
* 意义：替代指针，更好读。

int a = 0;
int &b = a; //int * const b = &a
b = 11;  //*b = 11;  a=11;

***********************/

#include <iostream>
#include <stdio.h>
using namespace std;

int myf1()
{
	int a;
	a = 10;
	return a;
}

//指针，相当于返回了a的地址
int &myf2()
{
	int a;
	a = 11;
	printf("a:%d\n",a);
	return a;
}

//等于int& myf2()用普通类型接下来
int* myf3()
{
	int a;
	//static int a;  如果定义成static就不会释放，b3的值还是12
	a = 12;
	return &a;
}

int& myA(int &a)
{
	a++;  //这里a是形参，不是局部变量了。
	return a;
}

//常引用
struct Adv2Teacher
{
	char name[32];
	int age ;
};
void getTeacher03(const Adv2Teacher &  t3) 
{
	//t3.age = 100; //err  //引用只能读 不能写，相当于 const Adv2Teacher * const t3 
	printf("age:%d", t3.age);
}

int main()
{
	int b1 = myf1();  //b1=10
	int *b3 = myf3();  //b3 = 12
	int b2 = myf2();  //b2 =11  输出a:11

	printf("b1:%d\n",b1);
	printf("b2:%d\n",b2);
	printf("b3:%d\n",*b3); //此时b3指向的a的地址没变，但是a的值变成11了

	//////////////////不同方式的引用//////////////////////
	int c = 10;
	int &c3 = myA(c); //c3 返回值的引用 c3 =11
	int c1 = myA(c3); //c = 12 c3 = 12
	int c2 = myA(c3);  //c = 13 c3 = 13
	//int &c3 = myA(c); //c3 返回值的引用
	printf("c1:%d\n", c1); 
	printf("c2:%d\n", c2); 
	printf("c3:%d\n", c3); 


	//////////////常引用/////////////////////
	//不能通过这个引用修改所绑定变量的值（和常量指针有点像）
	//1 const引用的作用：让变量所指向的内存空间只读
	//2 给const引用初始化，有两种方法
	
	//1。让变量初始化const引用
	//int &b = 10; //错误
	int b6 = 10; 
	const int &a6 = b6;//正确

	//a6 = 11; //不能通过a去间接修改b
	b6 = 12; //b是直接可以修改
		
	//2.const引用的第二种初始化方法（字面量初始化）
	const  int &c6 = 10; //正确        const在符号表，具体不知道存在哪里
	printf("&c:%d\n", c6);

	return 0;
}