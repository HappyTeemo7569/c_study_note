/**********************
����ָ������ָ��һ������
�������Ǻ��������ڵ�ַ���������һ��ָ��

ͨ���������Ͷ��庯��ָ�룺FuncType* pointer;
ֱ�Ӷ��壺type(*pointer)(parameter list);
pointer         Ϊ����ָ�������
type            Ϊָ�����ķ���ֵ����
parameter list  Ϊָ�����Ĳ��������б�
***********************/

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int array2[10];  //����һ����������
typedef int(ArrayType)[10];
//����һ��ָ������� ����ָ������
typedef int(*PArrayType)[10];  // int *

int test(int a)
{
	return a*a;
}

int main()
{
	ArrayType array; //int array2[10];  //���������Ͷ������
	array[0] = 1;

	//������ָ������  ȥ����һ��ָ��               
	PArrayType arrayp;     //����һ��ָ������     ���͵�ָ��
	arrayp = &array;
	(*arrayp)[0] = 2;    // array[0] = 2;

						 //ֱ�Ӷ���һ��ָ���������͵�ָ��
	int(*myParray)[10] = &array;
	(*myParray)[0] = 3;


	/////////////����ָ������ֶ��巽��///////////////////
	//1.����һ����������
	typedef int Func(int);
	Func *myfun = NULL;   //�ú������Ͷ���һ������ָ��
	myfun = test;         //������ַ������ָ��
	printf("%d \n", myfun(2));
	//�൱��ִ����int test(int a)     //ͨ��ͨ������ָ�����ִ��һ����������


	//2.����һ��ָ�������͵�ָ������
	typedef int(*MyFun)(int);
	MyFun aa;
	aa = test;
	printf("%d \n", aa(3));

	//(*(*(test)));   ����ȡ���ٸ�*��ֵ����һ���ģ�����������

	//3.ֱ�Ӷ���һ������ָ�룬���Ҹ�ֵ
	int(*myf1)() = test;
	int(*myf2)() = &test; //ȡ��ȡ��ַ��һ��
	printf("%d \n", myf1(4));
	printf("%d \n", myf1(5));

	return 0;
}