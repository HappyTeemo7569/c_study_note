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
	//sizeof（）运算符可以求一个变量，类型，常量等所占的存储空间。会执行括号中的计算，但是不会有结果。
	printf("字符是用ASC码存储的：%c\n", c1);
	printf("sizeof(i++)后i的值：%d,%d,%d\n",i1,i2,i3);
	printf("\n****************************************\n\n");
	
	int num = 0;
	printf("sizeof(long) is %d,sizeof(num) is %d\n", sizeof(long), sizeof(num));
	printf("sizeof(3 + 5) is %d\n", sizeof(3 + 5));
	printf("sizeof(num = 7) is %d\n", sizeof(num = 7));
	printf("num is %d\n", num);
	return 0;
	printf("\n****************************************\n\n");

	//进制显示
	int x = 100;
	printf("进制显示：100\n");
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	printf("\n****************************************\n\n");

	//溢出
	printf("溢出\n");
	int i = 2147483647;
	unsigned int j = 4294967295;
	printf("%d %d %d\n", i, i+1, i+2);
	printf("%u %u %u\n", j, j+1, j+2);//溢出后会从最小的开始
	printf("\n****************************************\n\n");

	//h修饰符可以显示较大整数被截断成 short 类型值
	unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig= %lld and not %ld\n", verybig, verybig);
	printf("\n****************************************\n\n");

	//指数显示
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f can be written %e\n", aboat, aboat);
	// 下一行要求编译器支持C99或其中的相关特性
	printf("And it's %a in hexadecimal, powers of 2 notation\n",aboat);
	printf("%f can be written %e\n", abet, abet);
	printf("%Lf can be written %Le\n", dip, dip);
	printf("\n****************************************\n\n");

	return 0;
}


