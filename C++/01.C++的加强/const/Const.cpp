/**********************
C语言的const变量是只读变量，有自己的存储空间。
C++中的const常量：
	可能分配存储空间（符号表，C++编译器生成，key和value对应），例如：
		当const常量为全局，并且需要在其他文件中使用。（使用了extern）
		当使用&操作符取const常量的地址。（为了兼容C的操作，会再在四区内分配一个，但是字符表里面的不会修改）
	也可能不分配。
***********************/

#include <stdio.h>

/*
int main()
{
	
	//a 是一个只读的常量，有自己的存储空间，按照理论应该不能被修改
	//在c++里面通过const修饰的东西，真正意义的const，被定义后会被放在符号表（脱离四区）
	
	const int a = 10;
	int *p = NULL;
	p = (int *)&a; //对a取地址，当你对a取地址的时候，有一个内存空间（&a a的内存空间）
	*p = 11;  //C竟然可以修改 ，伪const C++不可以修改,a的值还是10

	printf("修改之后a:%d \n", a); //C语言里面是11，C++里面是10
	printf("*p:%d \n", *p);  //*p的值为11
	
	//////////////////////////////////////////

	const int a = 1; //编译期间放在符号表中，值定下来
	const int b = 2;
	int array[a + b] = {0};  //c语言中错误，a + b为只读的变量，不是真正的常量;c++正确


	int i = 0;

	for(i=0; i<(a+b); i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	
	return 0;
}
*/

//C++中的define和const作用域不同
void fun1()
{
	#define a 10      
	const int b = 20;       //推荐使用const常量替代宏常数定义
}
void fun2()
{
	printf("a = %d\n", a);  //可以调用a
	//printf("b = %d\n", b);  //不可以调用b
}
int main()
{
	fun1();
	fun2();
	return 0;
}