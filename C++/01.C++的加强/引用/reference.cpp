/**********************
1.������

* ʵ�ʾ���һ�������洢�ռ�ı�����һ����š�
* ������ͨ�����������벢�����ڴ�ռ䡣
* ͨ��������������ʹ�ô洢�ռ䡣
* һ���������ڴ�ռ�ֻ��ȡһ������ô�����ǣ����þ��Ǳ�����


2.���õĸ���

* �﷨��Type & name = var;    int &b = a;
* ���Կ����Ǳ�������������ָ�볣����ָ��ָ��ĵ�ַ���䣬��ַ��������ݿ��Ա䡣Type& name  ��ͬ��Type* const name
* ��������ռ�õĿռ��С��ָ����ͬ������������û���Լ��Ĵ洢�ռ䣬��ʵ��ϸ�����أ�������ʹ�õ�ʱ������ʼ����
* ���壺���ָ�룬���ö���

int a = 0;
int &b = a; //int * const b = &a
b = 11;  //*b = 11;  a=11;

***********************/

#include <iostream>
#include <stdio.h>
using namespace std;

int myf1()
{
	int a;
	a = 10;
	return a;
}

//ָ�룬�൱�ڷ�����a�ĵ�ַ
int &myf2()
{
	int a;
	a = 11;
	printf("a:%d\n",a);
	return a;
}

//����int& myf2()����ͨ���ͽ�����
int* myf3()
{
	int a;
	//static int a;  ��������static�Ͳ����ͷţ�b3��ֵ����12
	a = 12;
	return &a;
}

int& myA(int &a)
{
	a++;  //����a���βΣ����Ǿֲ������ˡ�
	return a;
}

//������
struct Adv2Teacher
{
	char name[32];
	int age ;
};
void getTeacher03(const Adv2Teacher &  t3) 
{
	//t3.age = 100; //err  //����ֻ�ܶ� ����д���൱�� const Adv2Teacher * const t3 
	printf("age:%d", t3.age);
}

int main()
{
	int b1 = myf1();  //b1=10
	int *b3 = myf3();  //b3 = 12
	int b2 = myf2();  //b2 =11  ���a:11

	printf("b1:%d\n",b1);
	printf("b2:%d\n",b2);
	printf("b3:%d\n",*b3); //��ʱb3ָ���a�ĵ�ַû�䣬����a��ֵ���11��

	//////////////////��ͬ��ʽ������//////////////////////
	int c = 10;
	int &c3 = myA(c); //c3 ����ֵ������ c3 =11
	int c1 = myA(c3); //c = 12 c3 = 12
	int c2 = myA(c3);  //c = 13 c3 = 13
	//int &c3 = myA(c); //c3 ����ֵ������
	printf("c1:%d\n", c1); 
	printf("c2:%d\n", c2); 
	printf("c3:%d\n", c3); 


	//////////////������/////////////////////
	//����ͨ����������޸����󶨱�����ֵ���ͳ���ָ���е���
	//1 const���õ����ã��ñ�����ָ����ڴ�ռ�ֻ��
	//2 ��const���ó�ʼ���������ַ���
	
	//1���ñ�����ʼ��const����
	//int &b = 10; //����
	int b6 = 10; 
	const int &a6 = b6;//��ȷ

	//a6 = 11; //����ͨ��aȥ����޸�b
	b6 = 12; //b��ֱ�ӿ����޸�
		
	//2.const���õĵڶ��ֳ�ʼ����������������ʼ����
	const  int &c6 = 10; //��ȷ        const�ڷ��ű����岻֪����������
	printf("&c:%d\n", c6);

	return 0;
}