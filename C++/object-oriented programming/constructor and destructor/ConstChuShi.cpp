#include <iostream>
#include <stdio.h>
using namespace std;

class ABC
{
public:
	ABC(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("ABC construct ..\n");
	}
	~ABC()
	{
		printf("a:%d,b:%d,c:%d \n", a, b, c);
		printf("~ABC() ..\n");
	}
protected:
private:
	int a;
	int b;
	int c;
};


class MyD
{
public:
	MyD():abc1(1,2,3),abc2(4,5,6),m(100)
	{
		cout<<"MyD()"<<endl;
	}
	~MyD()
	{
		cout<<"~MyD()"<<endl;
	}

protected:
private:
	ABC abc1; //c++��������֪����ι���abc1,��ABC�Լ���ʼ��
	ABC abc2;
	const int m;
};


int run()
{
	MyD myD;
	return 0;
}

int main()
{
	run();
	return 0;
}

/**********************
���Ա������const���Σ������ڶ����ʼ����ʱ�򣬸�const int m ��ֵ��
�����Ա�к���һ��const����ʱ��������һ������ʱ������Ҳ����Ҫͨ����Ա��ʼ���б���г�ʼ����
��Ϊ�����ֶ���Ҫ�����������ϳ�ʼ�������ڹ��캯���У������Ƕ����ǵĸ�ֵ�������ǲ��������
***********************/