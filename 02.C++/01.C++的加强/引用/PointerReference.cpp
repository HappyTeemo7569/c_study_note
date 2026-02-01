#include <iostream>
#include <stdlib.h>
using namespace std;

struct AdvTeacher
{
	char name[32];
	int age;
};

void getTeacher01(AdvTeacher **p)//二级指针
{
	AdvTeacher *tmp = (AdvTeacher*)malloc(sizeof(AdvTeacher));
	tmp->age = 10;
	*p = tmp;   //用二级指针甩出一级
}

//////这个是 结构体变量指针的引用 指针的引用， 作用同getTeacher01 。
//* &p2=>&  *p2    p2是 t2的别名 ,给p2赋值就是给t2赋值
void getTeacher02(AdvTeacher *&p2)
{
	p2 = (AdvTeacher*)malloc(sizeof(AdvTeacher));
	p2->age = 20;
}

void getTeacher03(AdvTeacher &t3)  //如果不加引用 那么 myT3会copy给t3 ,则该操作与 myT3.age没有任何关系
{
	t3.age = 30;
}

int main()
{
	AdvTeacher *t1 = NULL;
	AdvTeacher *t2 = NULL;
	getTeacher01(&t1);  //分配内存空间，在结果中把地址甩出来
	getTeacher02(t2);   //引用C++自动取地址，引用本质是一个地址

	AdvTeacher  myT3;
	myT3.age = 10;
	getTeacher03(myT3);  //myT3.age = 30;

	cout << t1->age << endl;
	cout << t2->age << endl;
	cout << myT3.age << endl;
	return 0;
}