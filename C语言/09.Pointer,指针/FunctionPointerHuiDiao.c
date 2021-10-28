/**********************
函数指针做函数A参数，传给函数B，则函数B可以通过该指针调用外部函数，形成回调。
***********************/

#include <stdio.h>

int add(int a,int b);
int libfun(int (*pDis)(int a,int b));//函数指针做参数

int main()
{
	int (*pfun)(int a,int b);
	pfun = add;
	libfun(pfun);//调用接口，实际上使用的是动态库。

	return 0;
}

//自己的动态库
int add(int a,int b)
{
	return a+b;
}

//接口，可以二次修改
int libfun(int (*pDis)(int a,int b))
{
	int a,b;
	a = 1;
	b = 2;
	printf("%d\n",pDis(a,b));
}

