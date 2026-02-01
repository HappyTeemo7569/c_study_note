#include <stdio.h>
#include <string.h>

char* strcat1(char*a,const char*b);

int main()
{
	char a[100]="1234545";
	char b[30]="sfjisdf";
	char *c=strcat1(a,b);
	printf("AAA:%s\n",c);

	char d[100]="1234545";
	char e[30]="sfjisdf";
	char *f=strcat1(d,e);
	printf("BBB:%s\n",f);

	return 0;
}

char* strcat1(char*a,const char*b)
{
	char*c=a;
	while((a!=NULL)&&(b!=NULL))
	{

		while(*a)
		{
			a++;
		}
		while(*a++=*b++)
		{
			NULL;
		}
		return c;
	}
}
