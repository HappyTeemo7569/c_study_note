//���غͺ���ָ����
 
/*
���������뺯��ָ��
         ��ʹ�����غ������Ժ���ָ����и�ֵʱ
         �������ع�����ѡ�뺯��ָ������б�һ�µĺ�ѡ��
         �ϸ�ƥ���ѡ�ߵĺ��������뺯��ָ��ĺ�������
*/

#include <stdio.h>
#include <string.h>
using namespace std;

int func(int x) // int(int a)
{
	return x;
}

int func(int a, int b)
{
	return a + b;
}

int func(const char* s)
{
	return strlen(s);
}

typedef int(*PFUNC)(int a); // int(int a)
//int *PFUNC(int a)����
//int (*PFUNC)(int a)  PFUNC�Ǹ�����ָ�룬ֻ��ָ��һ�������ͷ���ֵ����int�ĺ���
//typedef int(*PFUNC)(int a); ������һ���µ�����PFUNC

int main(int argc, char *argv[])
{
	int c = 0;
	PFUNC p = func;

	c = p(1);

	printf("c = %d\n", c);
        
	return 0;
}