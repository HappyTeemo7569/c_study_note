//重载和函数指针结合
 
/*
函数重载与函数指针
         当使用重载函数名对函数指针进行赋值时
         根据重载规则挑选与函数指针参数列表一致的候选者
         严格匹配候选者的函数类型与函数指针的函数类型
*/

#include <stdio.h>
#include <string.h>
using namespace std;

int func(int x) // int(int a)
{
	return x;
}

int func(int a, int b)
{
	return a + b;
}

int func(const char* s)
{
	return strlen(s);
}

typedef int(*PFUNC)(int a); // int(int a)
//int *PFUNC(int a)函数
//int (*PFUNC)(int a)  PFUNC是个函数指针，只能指向一个参数和返回值都是int的函数
//typedef int(*PFUNC)(int a); 定义了一个新的类型PFUNC

int main(int argc, char *argv[])
{
	int c = 0;
	PFUNC p = func;

	c = p(1);

	printf("c = %d\n", c);
        
	return 0;
}