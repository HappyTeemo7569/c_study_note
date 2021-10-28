// Pointer1.cpp : 定义控制台应用程序的入口点。
//
/**********************
*从标准输入中读取输入行并在标准输出中打印这些输出行
*每个输出行的后面一行是按标号提取的一部分
*
*输入的第一行是一串列标号，串的最后以一个负号结尾
*标号应该成对出现，从某列到某列
*例如，0 3 10 12 -1表示0-3列，10-12列被提取打印
*
***********************/

//#include "stdafx.h"
//#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20    /*所能处理的最大列号*/
#define MAX_INPUT 1000 /*每个输入行的最大长度*/


int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int const columns[]);

int main()
{
	int n_columns; //进行处理的列标号
	int columns[MAX_COLS]; //需要处理的列数
	char input[MAX_INPUT]; //容纳输入行的数组
	char output[MAX_INPUT]; //容纳输出行的数组

	//读取该串列标号
	n_columns = read_column_numbers(columns,MAX_COLS);

	//读取、处理、打印剩余的输入行
	//gets函数将标准输入读取一行文本并存储于作为参数传递给他的数组中。会丢弃换行符，存储一个'\0'，返回非NULL表示被成功读取。
	//字符串就是一串以'\0'字符结尾的字符。
	while(gets(input) != NULL)
	{
		printf("Original input : %s\n",input);
		rearrange(output,input,n_columns,columns);//数组作为参数，存储返回值。
		printf("Rearranged line : %s\n",output);
	}

	//system("pause");
	return 0;
}

//读取行号，超出范围不予理会
//函数可以随意操作任意长度的一位数组，但是没办法知道数组的长度，只能加个参数传递。
int read_column_numbers(int columns[],int max)
{
	int num = 0;
	int ch;//并没有初始化，因为第一个操作就是赋值。

	//取得列标号，如果读取的数小于0则停止
	//scanf的返回值是成功转换并存储于参数中的值得个数
	while( num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0 )
		num += 1;

	//确认列标号成对出现
	if ( num%2 != 0 )
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	//丢弃该行中包含最后一个数字的那部分内容
	while( (ch = getchar()) != EOF && ch != '\n')
		;

	return num;
}

//处理输入行，将指定列的字符连接在一起，输出行以NULL结尾。
//input可变,*input不可变
void rearrange(char *output,char const *input,int n_columns,int const columns[])
{
	int col; //columns数组的下标
	int output_col; //输出列计算器
	int len; //输入列的长度

	len = strlen(input);
	output_col = 0;

	//处理每对列标号
	for (col=0;col<n_columns;col+=2)
	{
		int nchars = columns[col+1] - columns[col] + 1;

		//如果输入行结束或输出行数组已满，就结束任务
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
		{
			break;;
		}

		//如果输出行数据空间不够，只复制可以容纳的数据
		if (output_col + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - output_col - 1;
		}

		//复制相关的数据
		//char *strncpy(o,s,n);将源字符串s中的n个字符复制到目标字符串o中，并返回s。如果s小于n，用'\0'填充
		strncpy(output + output_col , input + columns[col] , nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}

