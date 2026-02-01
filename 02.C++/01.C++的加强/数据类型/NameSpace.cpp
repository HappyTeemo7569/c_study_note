/**********************
*传统的C将所有全局变量编译到一个命名空间，不允许重名。
*C++拥有多个，默认是std(standard)
*命名空间好像很多厂家，同样是手机，品牌不同则不同。
*如果要指定厂家，用域作用符::
***********************/

#include <iostream>
#include <stdio.h>

using namespace std;
// 不加这句，则需使用 :: 域作用符 std::cout

//命名空间的定义
namespace NameSpaceA
{
	int a = 0;
}

//嵌套定义
namespace NameSpaceB
{
	int a = 1;
	namespace NameSpaceC
	{
		struct Teacher
		{
			char name[10];
			int age;
		};
	}
}


int main()
{
	using namespace NameSpaceA;
	using NameSpaceB::NameSpaceC::Teacher;   //使用命名空间里面的变量

	printf("a = %d\n", a);              //是默认的空间    0
	printf("a = %d\n", NameSpaceB::a);  //使用里面的定义    1

	Teacher t1 = {"aaa", 3};

	printf("t1.name = %s\n", t1.name);
	printf("t1.age = %d\n", t1.age);

	return 0;

}
