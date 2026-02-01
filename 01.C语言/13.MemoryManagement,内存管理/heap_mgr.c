#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>


void test();

int main()
{
	/*
	int* p1=(int*)malloc(5); //在堆区中申请5Byte的内存空间，将首字节地址赋给p1，后面就可以通过p1去访问这块内存空间

	//如果申请失败，malloc函数返回NULL，通常原因是系统堆区空间不够造成的
	if(NULL == p1)
	{
	printf("动态申请内存空间失败！\n");
	return 1;
	}

	*p1=100;
	char* p2=(char*)(p1+1);
	*p2='a';

	printf("%p\n",p1);
	printf("%d\n",*p1);
	printf("%c\n",*p2);

	free(p1); //使用完堆区空间后一定要记得释放
	*/

	//////////////////////////////////////////

	/*
	int i=0;
	while(1)
	{
	void* p=malloc(1024*1024);
	//反复申请，直到满
	if(NULL == p)
	{
	printf("fail!\n");
	break;
	}
	i++;
	sleep(1);
	}

	printf("%d\n",i);
	*/

	//////////////////////////////////////////

	/*
	char* str=NULL;
	str=malloc(1001); //堆区数组
	char str2[1001]; //栈区数组

	//bzero库函数的作用：将指定内存空间清零
	bzero(str2,sizeof(str2));
	bzero(str,1001);

	//memset库函数的作用：将指定内存空间设置为某个值
	memset(str2,97,sizeof(str2));

	str[0]='a';
	str[1]='b';
	str[2]='c';
	*(str+3)='d';

	//memcpy库函数的作用：内存空间拷贝
	int i=0x41424344;
	memcpy(str,&i,sizeof(int));

	printf("%s\n",str);

	//在堆区申请的内存空间要么整体被释放，要么不释放，不能释放部分空间
	free(str); //free的参数必须为malloc的返回值，基类型任意
	*/

	//////////////////////////////////////////

	/*
	int a1[5]; //栈区数组

	int* const a2=(int*)calloc(5,sizeof(int)); //堆区数组
	//int* const a2=(int*)malloc(5*sizeof(int)); //和上面完全等效

	int i;
	for(i=0;i<5;i++)
	{
	a2[i]=i;
	}

	//free(a1); //画蛇添足
	free(a2);
	//free(a2); //双释放或多重释放错误
	*/

	//////////////////////////////////////////

	char* p1 = malloc(100);

	*p1 = 'a';
	p1[2] = 'b';

	/*
	free(p1);
	p1=malloc(500);
	*/

	p1 = realloc(p1, 500);

	printf("p1=%p\n", p1);
	printf("%c\n", p1[0]);

	free(p1);

	char* p = NULL;
	p = test();
	free(p); //函数内部申请的堆区空间可以由函数调用者负责释放

	p = test();
	free(p);

	//*p='a'; //内存空间被释放后不要再去访问它，否则发生不可预知的后果
	return 0;
}

char* test()
{
	char* p = NULL;
	p = malloc(100);

	return p;
}

/*
realloc内部实现的基本原理：

void* realloc(void* src, size_t new_size)
{
void* p=malloc(new_size);

memcpy(p,src,old_size);
free(src);

return p;
}
*/