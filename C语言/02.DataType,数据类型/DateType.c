#include <stdio.h>

int main()
{
	char c1 = 65;
	short int i1 = 10;
	int i2 = 10;
	long int i3 = 10;
	double d1 = 10.11;
	float f1 = 10.12;

	printf("char:%d Bytes\nshort int:%d Bytes\nint:%d Bytes\nlong int:%d Bytes\ndouble:%d Bytes\nsfloat:%d Bytes\n",
			sizeof(c1),sizeof(i1++),sizeof(i2++),sizeof(i3++),sizeof(d1),sizeof(f1));
	//sizeof���������������һ�����������ͣ���������ռ�Ĵ洢�ռ䡣��ִ�������еļ��㣬���ǲ����н����
	printf("�ַ�����ASC��洢�ģ�%c\n", c1);
	printf("sizeof(i++)��i��ֵ��%d,%d,%d\n",i1,i2,i3);
	printf("\n****************************************\n\n");
	
	int num = 0;
	printf("sizeof(long) is %d,sizeof(num) is %d\n", sizeof(long), sizeof(num));
	printf("sizeof(3 + 5) is %d\n", sizeof(3 + 5));
	printf("sizeof(num = 7) is %d\n", sizeof(num = 7));
	printf("num is %d\n", num);
	return 0;
	printf("\n****************************************\n\n");

	//������ʾ
	int x = 100;
	printf("������ʾ��100\n");
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	printf("\n****************************************\n\n");

	//���
	printf("���\n");
	int i = 2147483647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i+1, i+2);
	printf("%u %u %u\n", j, j+1, j+2);//���������С�Ŀ�ʼ
	printf("\n****************************************\n\n");

	//h���η�������ʾ�ϴ��������ضϳ� short ����ֵ
	unsigned int un = 3000000000; /* intΪ32λ��shortΪ16λ��ϵͳ */
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig= %lld and not %ld\n", verybig, verybig);
	printf("\n****************************************\n\n");

	//ָ����ʾ
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f can be written %e\n", aboat, aboat);
	// ��һ��Ҫ�������֧��C99�����е��������
	printf("And it's %a in hexadecimal, powers of 2 notation\n",aboat);
	printf("%f can be written %e\n", abet, abet);
	printf("%Lf can be written %Le\n", dip, dip);
	printf("\n****************************************\n\n");

	return 0;
}


