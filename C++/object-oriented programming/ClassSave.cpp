/**********************
������еĳ�Ա�����ͳ�Ա�����Ƿֿ��洢��
��Ա������
��ͨ��Ա�������洢�ڶ����У���struct��������ͬ���ڴ沼�ֺ��ֽڶ��뷽ʽ��
��̬��Ա�������洢��ȫ���������С�
��Ա�������洢�ڴ�����С�
***********************/

#include "iostream"
#include <stdio.h>
using namespace std;

class C1
{
public:
	int i; //4
	int j; //4
	int k; //4
protected:
private:
}; //12

class C2
{
public:
	int i; //4
	int j; //4
	int k; //4

	static int m; //4   ��ռ�ö���Ŀռ䣬����ȫ���� 
public:
	int getK() const { return k; } //��������4���ֽڣ����ڴ�����
	void setK(int val) { k = val; } //

protected:
private:
}; //12

struct S1
{
	int i;
	int j;
	int k;
}; //12

struct S2
{
	int i;
	int j;
	int k;
	static int m; //ȫ����
}; //12

///////////////////////////
//�ܶ������һ����룿������������־��������ǣ�
//����thisָ�룺 �����ͨ��Ա��������ʽ����һ��ָ��ǰ�����thisָ�롣����̬��Ա����û�У�
class Test
{
private:
	int n1;
public:
	Test(int i)
	{
		n1 = i;
	}
	int get1()
	{
		return n1;
	}
	static void Print1()
	{
		printf("This is class1 Test.\n");
	}
};

//�����������Գ���Ϊ�ṹ��
struct Test2
{
	int n1;
};

//��Ա����ת����ͨ���������ж���ָ��
void Test2_init(Test2* pThis,int i)
{
	pThis->n1 = i;
}

int Test2_get1(Test2* pThis)
{
	return pThis->n1;
}

//��̬��Ա������������ָ��
void Test2_print()
{
	printf("This is class2 Test.\n");
}


int main()
{
	printf("c1:%d \n", sizeof(C1));
	printf("c2:%d \n", sizeof(C2));
	printf("s1:%d \n", sizeof(S1));
	printf("s2:%d \n", sizeof(S2));

	////////////////////////////
	Test a(10);
	a.get1();
	Test::Print1();

	Test2 a2;
	Test2_init(&a2,20);
	Test2_get1(&a2);
	Test2_print();

	return 0;
}


