/**********************
函数指针用于指向一个函数
函数名是函数体的入口地址，本身就是一个指针

通过函数类型定义函数指针：FuncType* pointer;
直接定义：type(*pointer)(parameter list);
	pointer         为函数指针变量名
	type            为指向函数的返回值类型
	parameter list  为指向函数的参数类型列表
***********************/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int array2[10];  //定义一个数组类型
typedef int (ArrayType)[10];
//定义一个指向数组的 数组指针类型
typedef int (*PArrayType)[10];  // int *

int test(int a)
{
	return a*a;
}

int main()
{
	ArrayType array; //int array2[10];  //由数组类型定义变量
	array[0] = 1;
	
	//用数组指针类型  去定义一个指针               
	PArrayType arrayp;     //定义一个指向数组     类型的指针
	arrayp = &array;
	(*arrayp)[0] = 2;    // array[0] = 2;
	
	//直接定义一个指向数组类型的指针
	int (*myParray)[10] =  &array;         
	(*myParray)[0] = 3;

	
	/////////////函数指针的三种定义方法///////////////////
	//1.定义一个函数类型
	typedef int Func(int);
	Func *myfun = NULL;   //用函数类型定义一个函数指针
	myfun = test;         //函数地址传函数指针
	printf("%d \n", myfun(2));   
	//相当于执行了int test(int a)     //通过通过函数指针可以执行一个函数调用


	//2.定义一个指向函数类型的指针类型
	typedef int (*MyFun)(int);
	MyFun aa;
	aa = test;
	printf("%d \n",aa(3)); 

	//(*(*(test)));   不管取多少个*，值都是一样的，还是它本身

	//3.直接定义一个函数指针，并且赋值
	int (*myf1)() = test;
	int (*myf2)() = &test; //取不取地址都一样
	printf("%d \n", myf1(4)); 
	printf("%d \n", myf1(5)); 

	return 0;
}