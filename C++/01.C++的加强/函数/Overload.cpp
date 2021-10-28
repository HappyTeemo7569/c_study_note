//函数重载（Overload）:用同一函数名定义不同的函数，当函数名和不同参数搭配时函数的意义不同。

#include "iostream"
#include <cstdio>
using namespace std;


void myprintf(int a)
{
	printf("a:%d\n ", a );
}
void myprintf(double a)
{
	printf("a:%f\n ", a );
}

void myprintf(char *p, int b)
{
	printf("p:%s, b:%d", p, b);
}

void myprintf(int b, char *p)
{
	printf("b:%d, p:%s", b, p);
}

//函数返回类型不是函数重载的判断标准

void myprintf(int a, int b)
{
	printf("a:%d, b:%d\n", a, b);
}

//当函数重载遇上 函数默认参数
int  myprintf(int a, int b, int c=0)     
{
	printf("a:%d, b:%d c:%d \n", a, b, c);
	return a;
}

int main()
{
	int a = 1;
	myprintf(a);  //调用void myprintf(int a)

	//myprintf(1,2); //二义性,无法判断是void myprintf(int a, int b)还是int  myprintf(int a, int b, int c=0) ,调用失败。
	myprintf(1,2,3);//可以区分
	
	return 0;
}
/*
//两个难点：
	重载函数和默认函数参数混搭
	重载函数和函数指针

函数重载至少满足下面的一个条件：
	参数个数不同
	参数类型不同
	参数顺序不同

编译器调用重载函数的准则:
	将所有同名函数作为候选者
	尝试寻找可行的候选函数
	精确匹配实参
	通过默认参数能够匹配实参
	通过默认类型转换匹配实参
	匹配失败
	最终寻找到的可行候选函数不唯一，则出现二义性，编译失败。
	无法匹配所有候选者，函数未定义，编译失败。

函数重载的注意事项
	重载函数在本质上是相互独立的不同函数（静态链编）
	重载函数的函数类型是不同的
	函数返回值不能作为函数重载的依据
	函数重载是由函数名和参数列表决定的。

*/