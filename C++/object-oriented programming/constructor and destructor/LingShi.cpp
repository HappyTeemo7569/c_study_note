#include"iostream"
#include <stdio.h>
using namespace std;

class MyTest
{
public:
	MyTest(int a,int b,int c)
	{
		this->a = a;
		this->b = b;
	}
	~MyTest()
	{
		printf("MyTest~:%d, %d, %d\n", a, b, c);// a=1,b=2, c=100;
	}

protected:
private:
	int a;
	int b;
	int c;

public:
	int getC() const { return c; }
	void setC(int val) { c = val; }
};

int main()
{
	MyTest t1(1,2,100);//û�ж���ȥ�ӣ������ͷ�
	printf("c:%d", t1.getC()); //C��ֵΪ����ֵ
	return 0;
}

