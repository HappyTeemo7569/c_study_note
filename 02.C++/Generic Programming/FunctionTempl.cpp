#include<iostream>
using namespace std;


int Max(int a, int b)
{
	cout<<"int Max(int a, int b)"<<endl;
	return a > b ? a : b;
}

//模板类型不能提供类型的隐式转换
template<typename T>
T Max(T a, T b)
{
	cout<<"T Max(T a, T b)"<<endl;
	return a > b ? a : b;
}

template<typename T>
T Max(T a, T b, T c)
{
	cout<<"T Max(T a, T b, T c)"<<endl;
	return Max(Max(a, b), c);
}


int main()
{
	int a = 1;
	int b = 2;

	cout<<Max(a, b)<<endl;  // 普通函数
	cout<<Max<>(a, b)<<endl;  //模板函数
	cout<<Max(3.0, 4.0)<<endl; //函数模板产生更好的匹配，模板函数
	cout<<Max(5.0, 6.0, 7.0)<<endl; // 函数模板  
	cout<<Max('a', 100)<<endl;   //会调用普通函数，因为只有普通函数可以自动类型转换-》'a'

	return 0;
}

/*
    1 函数模板可以像普通函数一样被重载
    2 C++编译器优先考虑普通函数
    3 如果函数模板可以产生一个更好的匹配，那么再选择模板
    4 可以通过空模板实参列表的语法强制限定编译器只通过模板匹配
*/

/*
函数模板的深入理解
    ― 编译器并不是把函数模板处理成能够处理任意类型的函数
    ― 编译器从函数模板通过具体类型产生不同的函数
    ― 编译器会对函数模板进行两次编译：  （C++编译器自己手工多写）
         1.在声明的地方对模板代码本身进行编译
         2.在调用的地方对参数替换后的代码进行编译
*/
 
//template告诉编译器，这里开始进行泛型编程
//typename告诉编译器，类型名称为T 编译器你看到类型T 不要乱报错。
//T为类型，类型参数化而已