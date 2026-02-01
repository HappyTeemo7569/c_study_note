/**********************
����override
���أ�ͬһ�����У�ͬһ�������򣩣�������ͬ�����ĺ��������������ظ��ຯ����ֻ�ᱻͬ�����ǣ����ڱ����ڼ���ݲ������ͺ͸��������������á�
��д�����������¶��������麯�������֡�����������ֵ��һ����������static������̬���������ڼ���ݾ����������;����������á�
�麯�����������󶨣���̬���ӱ��룻�����Ϊ�ض��壬��̬���롣
��д�����ķ������η����Բ�ͬ����private���Ա�Ϊpublic֮��ģ�
***********************/

#include <stdio.h>
#include <iostream>
using namespace std;

class Parent01
{
public:
	Parent01()  //���캯��
	{
		cout << "P1" << endl;
	}
public:
	void func()
	{
		cout << "P1 void" << endl;
	}
	virtual void func(int i)
	{
		cout << "P1 int" << endl;
	}
	virtual void func(int i,int j)
	{
		cout << "P1 2 int" << endl;
	}
	void run01(Parent01* p)
	{
		p->func(1,2);
	}
};

class Child01:public Parent01
{
public:
	void func(int i,int j)
	{
		cout << "C1 2 int" << endl;
	}

	void func(int i,int j,int k)
	{
		cout << "C1 3 int" << endl;
	}
};

int main()
{
	Parent01 p;
	p.func();
	p.func(1);
	p.func(1,2);

	Child01 c;
	//c.func(); //�������ĺ����Ѿ������ǣ������ٱ����á�
	c.Parent01::func();  //�������ǵ��ø�������������ĺ���
	c.func(1,2);
	c.func(1,2,3);


	//��Ϊ��û�б����ǣ����Ը�������඼���Ե���
	p.run01(&p);
	p.run01(&c);

	c.run01(&p);
	c.run01(&c);
}