/*
在C语言中，重复定义多个同名的全局变量是合法的，多个同名的全局变量最终会被链接到全局数据区的同一个地址空间上，C++不允许定义多个同名的全局变量。

C++中所有的变量和函数都必须有类型，C语言中的默认类型在C++中是不合法的。

在C语言中
int f( )；表示返回值为int，接受任意参数的函数
int f(void)；表示返回值为int的无参函数

C++中
int f( );和int f(void)具有相同的意义，都表示返回值为int的无参函数
C++更加强调类型，任意的程序元素都必须显示指明类型
*/

//C语言中
#include <stdio.h>

f(i)//默认参数类型为int
{
	printf("i = %d\n", i);
}

g()//默认返回值为int
{
	return 5;
}

int main(int argc, char *argv[])
{

	f(10);

	printf("g() = %d\n", g(1, 2, 3, 4, 5));

	getchar();
	return 0;
}

//默认参数和占位符：
//C++中函数声明时没有提供值，系统则会提供一个默认值。

void Func(int i = 1, float f = 2.0f, double d = 3.0)
{
	cout << i << ", " << f << ", " << d << endl ;
}

int main(void)
{
	Func() ; // 1, 2, 3
	Func(10) ; // 10, 2, 3
	Func(10, 20.0f) ; // 10, 20, 3
	Func(10, 20.0f, 30.0) ; // 10, 20, 30return 0 ;
}

//参数可以是表达式
class Test
{
public:
	static int getValue()
	{
		return 1;
	}

	int func(int a, int b = getValue())
	{
		return b;
	}
} ;

//只有后部分参数可以。如果某个参数是默认参数，则后面的参数都必须是默认参数。
//下面两种情况都可以
void Func(int i, float f = 2.0f, double d = 3.0) ;
void Func(int i, float f, double d = 3.0) ;
//但是这样就不可以
void Func(int i, float f = 2.0f, double d) ;

///////////////////////////////////////////////////////////
/*
函数占位参数
占位参数只有参数类型声明，而没有参数名声明
一般情况下，在函数体内部无法使用占位参数
*/

int func(int a, int b, int )
{
	return a + b;
}

int main01(int argc, char *argv[])
{
	printf("func(1, 2, 3) = %d\n", func(1, 2, 3)); // 可以
	printf("func(1, 2) = %d\n", func(1, 2));    // 不可以

	printf("Press enter to continue ...");
	getchar();
	return 0;
}

///////////////////////////////////////////////////////
/*
可以将占位参数与默认参数结合起来使用
意义
为以后程序的扩展留下线索（不常使用）
兼容C语言程序中可能出现的不规范写法
*/

//C++可以声明占位符参数，占位符参数一般用于程序扩展和对C代码的兼容

int func(int a, int b, int = 0)  //int = 0：默认+占位参数（混搭）
{
	return a + b;
}

int main66(int argc, char *argv[])
{
	printf("func(10, 20) = %d\n", func(10, 20)); // 可以
	func(10, 20, 30)；//可以

	printf("Press enter to continue ...");
	getchar();
	return 0;
}
