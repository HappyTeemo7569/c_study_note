#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class Test1
{
public:
	Test1(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"GouZao"<<endl;
	}
	~Test1()
	{
		cout<<"XiGou"<<endl;
	}
	void printTest()
	{
		cout << m_a << m_b << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};


//ָ������������
//Test1 *p5 = NULL; CreateTest1(&p5); p5�ǵ�ַ��&p5����p�������p5��ַ
int CreateTest1(Test1 **p)    //p�Ƕ���ָ�룬һ��ָ��ȡ��ַ�Ƕ���ָ��
{
	Test1 *tmp = new Test1(5, 6);
	*p = tmp;//����ָ��p����ʵ�Σ�ָ��P3���ĵ�ַ *��ʵ�εĵ�ַ��ȥ����޸�ʵ�Σ�P3����ֵ
	return 0;
}


int CreateTest2(Test1 * &myp)  // ����������&myp�����ã��Զ�����ȡ��ַ 
{
	myp = new Test1(7, 8); //p��ʵ�εĵ�ַ *��ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ
	return 0;
}

int main()
{
	///////////////��������///////////////
	int *p1 = new int;  //int *p = (int*)malloc(sizeof(int));
	*p1 = 10;
	printf("%d\n",*p1);
	delete p1;

	//////////////����///////////////////
	int *p2 = new int[10]; //int *p = (int *)malloc(10*sizeof(int));
	for (int i=0; i<10; i++)  //��ֵ
	{
		p2[i] = i+1;
		printf("%d\n", p2[i]);
	}
	delete[] p2;  //�ͷ�  delete p1[];����   delete p1;û�ͷ���

	//////////////��////////////////////
	Test1 *p3 = new  Test1(3, 4);//c++�е�new���Զ��ĵ�����Ĺ��캯��
	p3->printTest();
	delete p3;   //delete�ܵ��������������
		
	Test1 *p4 = (Test1 *)malloc(sizeof(Test1));//malloc���������Ĺ��캯�� 
	p4->printTest();
	free(p4);   //freeҲ������������������

	cout << "*****************" << endl; 
	////////////ָ������������///////////
	Test1 *p5 = NULL;
	CreateTest1(&p5);
	p5->printTest();
	CreateTest2(p5);
	p5->printTest();
	delete p5;

	return 0;
}