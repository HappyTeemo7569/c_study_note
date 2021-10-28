#include <stdio.h>

enum Days
{
	saturday,                    // saturday = 0 默认值
	sunday = 0,                  // sunday = 0
	monday,                      // monday = 1
	tuesday,                     // tuesday = 2
	wednesday,                   // 依次类推
	thursday,
	friday
} today;  // 定义Days类型的变量today

int main()
{
	//int  tuesday;           // 错误，重复定义或者该句无效，打印输出时报未定义的错误。
	//printf("%d\n", tuesday);

	///////////////////////////////

	enum Days yesterday;      // 在C和C++中都合法
	//Days tomorrow;          // 只在C++中合法
	yesterday = monday;       // 为yesterday变量赋值为Monday
	//yesterday = 0;          // 错误，因为没有进行类型转换
	//yesterday = (Days)0;    // 有效，但是结果不确定，不确定为saturday还是sunday。

	/////////////////////////

	//int i = tuesday;          // 有效，i = 2
	//printf("%d\n",i);

	return 0;
}