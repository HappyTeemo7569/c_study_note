/**********************
����ָ��������A��������������B������B����ͨ����ָ������ⲿ�������γɻص���
***********************/

#include <stdio.h>

int add(int a,int b);
int libfun(int (*pDis)(int a,int b));//����ָ��������

int main()
{
	int (*pfun)(int a,int b);
	pfun = add;
	libfun(pfun);//���ýӿڣ�ʵ����ʹ�õ��Ƕ�̬�⡣

	return 0;
}

//�Լ��Ķ�̬��
int add(int a,int b)
{
	return a+b;
}

//�ӿڣ����Զ����޸�
int libfun(int (*pDis)(int a,int b))
{
	int a,b;
	a = 1;
	b = 2;
	printf("%d\n",pDis(a,b));
}

