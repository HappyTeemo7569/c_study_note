//BOOl����ֻ��1��0��1���棬0�Ǽ١�ռһ���ֽ�

#include <stdio.h>
using namespace std;

int main()
{
	bool b_a = true;
	bool b_b = false;

	printf("\n%d",b_a);  //1
	printf("\n%d",b_b);  //0

	//������֮���ת����0�Ǽټ�0���������漴1
	int a = 0;

	b_a = a;   //b_a = 0;
	int c = b_a;

	printf("\nb_a:%d",b_a);
	printf("\nc:%d",c);

	return 0;
}



