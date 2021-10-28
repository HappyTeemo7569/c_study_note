#include"iostream"
using namespace std;

class AA
{
public:
	AA(int a= 0)
	{    
		this->a = a;
		print(); //在构造函数里面能实现多态吗？
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
	virtual void print()
	{
		cout<<"C"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToPrintf(AA *pBase)
{
	pBase->print();  
}

int main()
{
	//AA a1;
	BB b1;
	//howToPrintf(&a1);
	howToPrintf(&b1);
	return 0;
}

/**********************
*构造函数不能实现多态
*子类构造：
1.先执行父类构造，初始化子类vptr指针，指向父类的虚函数表，此时父类构造里面调用printf，无法找到子类的虚函数printf。
2.父类构造函数结束，子类构造函数执行，vptr重定向到子类的虚函数表。
*只有当对象构造完成后才能确定vptr的指向。
***********************/