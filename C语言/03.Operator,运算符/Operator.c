#include <Windows.h>
#include <stdio.h>


int main()
{
	int a=0;
	int b=0;

	printf("%d %d %d\n",b=a++ +(a++ +2),b,a=b++);
	printf("%d %d\n",a,b);

	system("pause");

	system("pause");
	return 0;
}