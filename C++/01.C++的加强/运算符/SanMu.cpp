#include <stdio.h>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int c = 31;

	(a<b?a:b) = 30;

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
//C++中三目运算符返回一个变量，可以作为左值（能被放在=左边，即这段空间能被你写）
//三目运算符是表达式，表达式不可以做左值，但是C++返回的是变量，变量可以做为左值。

