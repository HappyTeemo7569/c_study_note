/**********************
*��ͳ��C������ȫ�ֱ������뵽һ�������ռ䣬������������
*C++ӵ�ж����Ĭ����std(standard)
*�����ռ����ܶ೧�ң�ͬ�����ֻ���Ʒ�Ʋ�ͬ��ͬ��
*���Ҫָ�����ң��������÷�::
***********************/

#include <iostream>
#include <stdio.h>

using namespace std;
// ������䣬����ʹ�� :: �����÷� std::cout

//�����ռ�Ķ���
namespace NameSpaceA
{
	int a = 0;
}

//Ƕ�׶���
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
	using NameSpaceB::NameSpaceC::Teacher;   //ʹ�������ռ�����ı���

	printf("a = %d\n", a);              //��Ĭ�ϵĿռ�    0
	printf("a = %d\n", NameSpaceB::a);  //ʹ������Ķ���    1

	Teacher t1 = {"aaa", 3};

	printf("t1.name = %s\n", t1.name);
	printf("t1.age = %d\n", t1.age);

	return 0;

}
