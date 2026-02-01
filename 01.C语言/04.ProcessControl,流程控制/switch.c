#include <Windows.h>
#include <stdio.h>


int main()
{
    int i;
    scanf("%d",&i);

	switch(i) //Switch后的表达式（控制表达式）一般为字符或整形表达式（表达式的值不是整数自动取整），不能为实型。  
    {  
        case 0:
        {
            printf("input 0\n");
            return 0;
        }  
        //Case后的常量表达式应是字符型或整型，不允许含有变量或者函数调用，必须与switch后面括号内的表达式一个类型，且值要互不相同。  
        case 1:
        {
            printf("input 1\n");
            return 0;
        }  
        default://默认值，如果表达式的值与所有case后的值都不相等，则执行default后的语句 
            printf("default\n"); 
    }

	system("pause");
	return 0;
}