//�������أ�Overload��:��ͬһ���������岻ͬ�ĺ��������������Ͳ�ͬ��������ʱ���������岻ͬ��

#include "iostream"
#include <cstdio>
using namespace std;


void myprintf(int a)
{
	printf("a:%d\n ", a );
}
void myprintf(double a)
{
	printf("a:%f\n ", a );
}

void myprintf(char *p, int b)
{
	printf("p:%s, b:%d", p, b);
}

void myprintf(int b, char *p)
{
	printf("b:%d, p:%s", b, p);
}

//�����������Ͳ��Ǻ������ص��жϱ�׼

void myprintf(int a, int b)
{
	printf("a:%d, b:%d\n", a, b);
}

//�������������� ����Ĭ�ϲ���
int  myprintf(int a, int b, int c=0)     
{
	printf("a:%d, b:%d c:%d \n", a, b, c);
	return a;
}

int main()
{
	int a = 1;
	myprintf(a);  //����void myprintf(int a)

	//myprintf(1,2); //������,�޷��ж���void myprintf(int a, int b)����int  myprintf(int a, int b, int c=0) ,����ʧ�ܡ�
	myprintf(1,2,3);//��������
	
	return 0;
}
/*
//�����ѵ㣺
	���غ�����Ĭ�Ϻ����������
	���غ����ͺ���ָ��

���������������������һ��������
	����������ͬ
	�������Ͳ�ͬ
	����˳��ͬ

�������������غ�����׼��:
	������ͬ��������Ϊ��ѡ��
	����Ѱ�ҿ��еĺ�ѡ����
	��ȷƥ��ʵ��
	ͨ��Ĭ�ϲ����ܹ�ƥ��ʵ��
	ͨ��Ĭ������ת��ƥ��ʵ��
	ƥ��ʧ��
	����Ѱ�ҵ��Ŀ��к�ѡ������Ψһ������ֶ����ԣ�����ʧ�ܡ�
	�޷�ƥ�����к�ѡ�ߣ�����δ���壬����ʧ�ܡ�

�������ص�ע������
	���غ����ڱ��������໥�����Ĳ�ͬ��������̬���ࣩ
	���غ����ĺ��������ǲ�ͬ��
	��������ֵ������Ϊ�������ص�����
	�����������ɺ������Ͳ����б������ġ�

*/