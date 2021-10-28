/**********************
虚析构函数（virtual destructor）
在堆区中定义一个子类对象，然后将其指针赋给父类指针变量，最后通过父类指针去释放该子类对象时，
如果父类的析构函数不是析构函数，那么只会调用父类的析构函数，而子类的析构函数不会被调用，可能会导致内存泄露，
如果父类的析构函数为虚函数，那么首先会调用子类的析构函数，然后再调用父类的析构函数。
C++编码规范：在定义一个类时，将他的析构函数定义为虚函数
***********************/

#include<iostream>
using namespace std;

class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); 
	}
	virtual ~AA()
	{
		cout<<"P XiGou do"<<endl;
	}

	virtual void print()
	{
		cout<<"P"<<"a"<<a<<endl;
	}

protected:
	int a ;
};

class BB : public AA
{
public:
	BB(int a= 0, int b = 0)
	{
		this->a = a;
		this->b = b;

	}

	~BB()
	{
		cout<<"C XiGou do"<<endl;
	}
	virtual void print()
	{
		cout<<"C"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToDelete(AA *pBase)
{
	delete pBase;
}
int main()
{
	BB *b1 = new BB(1, 2);

	b1->print();

	howToDelete(b1);
	//delete b1;
	return 0;
}