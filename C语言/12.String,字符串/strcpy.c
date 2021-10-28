#include<stdio.h>
#include <string.h>

char* strcpy2(char* str1,char*str2)
{
	int n1,n2;
	n1=sizeof(str1);
	n2=sizeof(str2);

	int i;
	for(i=0;(i<n1 && str2[i]!='\0');i++)
	{
		str1[i]=str2[i];
		printf("%s\n",str1);
	}

	if(n1>n2)
	{
		for(i=n1-n2;i<=n1;i++)
		{
			str1[i]='\0';
			printf("%s\n",str1);
		}
	}
}

int main()
{
	char str1[5]="abc";
	char str2[5]="123";
	strcpy2(str1,str2);
	printf("AAA:%s\n",str1);

	char str3[5]="abc";
	char str4[5]="123";
	strcpy(str3,str4);
	printf("BBB:%s\n",str3);
}
