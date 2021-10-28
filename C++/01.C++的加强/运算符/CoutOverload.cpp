#include "iostream"
using namespace std;

class Complex
{
private:
	int a;
	int b;
	friend ostream& operator<<(ostream &out, Complex &c1);  // ostream是系统自带cout的类型

public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout<<a<<"+"<<b<<"i"<<endl;
	}
};


ostream  &operator<<(ostream &out, Complex &c1)    //进来后又出去
{
	cout<<"12345,上山打老虎"<<endl;
	cout<<c1.a<<"+"<<c1.b<<"i"<<endl;
	return out;
}

//1操作符重载，首先是通过函数实现的。
int main()
{
	Complex c1(1, 2), c2(3, 4); 
	int a = 10;
	//char *p = "abc";
	//cout<<a<<endl;  //正确
	//cout<<c1<<endl;  //正确
	
	//cout<<c1<<"链式编程测试"<<endl;   //不自定义<<则错误 ，没法打印<<错误自定义版（链式结构）
	//operator<<(cout,c1),cout是左操作数
	//链式编程，c1<<"***" 等价于void<<"***";错误

	//函数返回值当左值的时候，需要返回一个对象的引用， 没有方法在cout类里面添加函数operator<<，只能通过全局函数实现.
	//友元的真正用武之地
	cout.operator<<(c1);
	return 0;
}