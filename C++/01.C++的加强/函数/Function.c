/*
��C�����У��ظ�������ͬ����ȫ�ֱ����ǺϷ��ģ����ͬ����ȫ�ֱ������ջᱻ���ӵ�ȫ����������ͬһ����ַ�ռ��ϣ�C++����������ͬ����ȫ�ֱ�����

C++�����еı����ͺ��������������ͣ�C�����е�Ĭ��������C++���ǲ��Ϸ��ġ�

��C������
int f( )����ʾ����ֵΪint��������������ĺ���
int f(void)����ʾ����ֵΪint���޲κ���

C++��
int f( );��int f(void)������ͬ�����壬����ʾ����ֵΪint���޲κ���
C++����ǿ�����ͣ�����ĳ���Ԫ�ض�������ʾָ������
*/

//C������
#include <stdio.h>

f(i)//Ĭ�ϲ�������Ϊint
{
	printf("i = %d\n", i);
}

g()//Ĭ�Ϸ���ֵΪint
{
	return 5;
}

int main(int argc, char *argv[])
{

	f(10);

	printf("g() = %d\n", g(1, 2, 3, 4, 5));

	getchar();
	return 0;
}

//Ĭ�ϲ�����ռλ����
//C++�к�������ʱû���ṩֵ��ϵͳ����ṩһ��Ĭ��ֵ��

void Func(int i = 1, float f = 2.0f, double d = 3.0)
{
	cout << i << ", " << f << ", " << d << endl ;
}

int main(void)
{
	Func() ; // 1, 2, 3
	Func(10) ; // 10, 2, 3
	Func(10, 20.0f) ; // 10, 20, 3
	Func(10, 20.0f, 30.0) ; // 10, 20, 30return 0 ;
}

//���������Ǳ��ʽ
class Test
{
public:
	static int getValue()
	{
		return 1;
	}

	int func(int a, int b = getValue())
	{
		return b;
	}
} ;

//ֻ�к󲿷ֲ������ԡ����ĳ��������Ĭ�ϲ����������Ĳ�����������Ĭ�ϲ�����
//�����������������
void Func(int i, float f = 2.0f, double d = 3.0) ;
void Func(int i, float f, double d = 3.0) ;
//���������Ͳ�����
void Func(int i, float f = 2.0f, double d) ;

///////////////////////////////////////////////////////////
/*
����ռλ����
ռλ����ֻ�в���������������û�в���������
һ������£��ں������ڲ��޷�ʹ��ռλ����
*/

int func(int a, int b, int )
{
	return a + b;
}

int main01(int argc, char *argv[])
{
	printf("func(1, 2, 3) = %d\n", func(1, 2, 3)); // ����
	printf("func(1, 2) = %d\n", func(1, 2));    // ������

	printf("Press enter to continue ...");
	getchar();
	return 0;
}

///////////////////////////////////////////////////////
/*
���Խ�ռλ������Ĭ�ϲ����������ʹ��
����
Ϊ�Ժ�������չ��������������ʹ�ã�
����C���Գ����п��ܳ��ֵĲ��淶д��
*/

//C++��������ռλ��������ռλ������һ�����ڳ�����չ�Ͷ�C����ļ���

int func(int a, int b, int = 0)  //int = 0��Ĭ��+ռλ��������
{
	return a + b;
}

int main66(int argc, char *argv[])
{
	printf("func(10, 20) = %d\n", func(10, 20)); // ����
	func(10, 20, 30)��//����

	printf("Press enter to continue ...");
	getchar();
	return 0;
}
