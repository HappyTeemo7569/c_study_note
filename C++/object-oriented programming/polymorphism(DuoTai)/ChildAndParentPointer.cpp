#include <iostream>
#include <stdio.h>
using namespace std;

class Parent01
{
protected:
	int i;
	int j;
public:
	virtual void f()
	{
		cout<<"Parent01::f"<<endl;
	}
};

class Child01 : public Parent01
{  
public:
	int k;    //��������� p->f()��崻���

public:
	Child01(int i, int j)
	{
		printf("Child01:...do\n");
	}

	virtual void f()
	{
		//printf("Child01::f()...do\n");
		cout << "Child f()" << i << j << endl;
	}
};

void howToF(Parent01 *pBase)           
{
	pBase->f();
}

//ָ��Ĳ��� ��c++������Ȼ��Ч������ָ��Ĳ���������ָ��Ĳ�����һ��
//��̬�ǿ��ٰ�ʵ�ֵģ�vptr+����ָ��ʵ�֣�
int main()
{
	int i = 0;
	Parent01* p = NULL;
	Child01* c = NULL;

	//��Ҫ�Ѹ���������������ͬʱ����һ����������
	Child01 ca[3] = {Child01(1, 2), Child01(3, 4), Child01(5, 6)};

	/*����������
	//��Ҫ�ø���ָ������ֵָ�������ȥ����һ����������顣
	p = ca;
	c = ca;

	p->f();  
	c->f(); //�ж�̬����

	p++; // p++��c++������һ��
	c++;

	p->f();//�ж�̬������崻�
	c->f();

	//����vptrָ��i,j;����ָ��i,j,k;
	*/

	
	//��ȷ������
	for (i=0; i<3; i++)
	{
		howToF(&(ca[i]));
	}

	return 0;
}