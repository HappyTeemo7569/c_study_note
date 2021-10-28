#include <iostream>
#include <stdio.h>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		//调用顺序1.1
		printf("ABCD() construct, a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	~ABCD()
	{
		printf("~ABCD() destructor,a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	//调用顺序1
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout<<"MyD()"<<endl;//调用顺序1.2
	}
	~MyE()
	{
		cout<<"~MyD()"<<endl;
	}
	//调用顺序2.1
	MyE(const MyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)  //拷贝构造函数，也要加初始化列表
	{
		printf("MyD(const MyD & obj)\n");//调用顺序2.2
	}

protected:
	//private: 
public:  
	ABCD abcd1; //c++编译器不知道如何构造abc1
	ABCD abcd2;
	const int m;

};

//调用顺序2
int doThing( MyE mye1) //实参调用形参。调用拷贝构造函数 MyE(constMyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)
{
	//调用顺序3
	printf("doThing() mye1.abc1.a:%d \n", mye1.abcd1.getA()); 
	//实参传给形参的值是abcd1(1,2,3),abcd2(4,5,6)/，但它会执行abcd1(7,8,9),abcd2(10,11,12),m(100) ，所以doThing(myE)-》mye1.abc1.a=7。   static只初始化一次。                    
	return 0;
}

int main()
{
	MyE myE; //调用构造函数MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)

	doThing(myE);  
	return 0;
}

