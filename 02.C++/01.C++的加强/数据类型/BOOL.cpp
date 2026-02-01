//BOOl类型只有1和0；1是真，0是假。占一个字节

#include <stdio.h>
using namespace std;

int main()
{
	bool b_a = true;
	bool b_b = false;

	printf("\n%d",b_a);  //1
	printf("\n%d",b_b);  //0

	//和整型之间的转换：0是假即0，非零是真即1
	int a = 0;

	b_a = a;   //b_a = 0;
	int c = b_a;

	printf("\nb_a:%d",b_a);
	printf("\nc:%d",c);

	return 0;
}



