// Pointer1.cpp : �������̨Ӧ�ó������ڵ㡣
//
/**********************
*�ӱ�׼�����ж�ȡ�����в��ڱ�׼����д�ӡ��Щ�����
*ÿ������еĺ���һ���ǰ������ȡ��һ����
*
*����ĵ�һ����һ���б�ţ����������һ�����Ž�β
*���Ӧ�óɶԳ��֣���ĳ�е�ĳ��
*���磬0 3 10 12 -1��ʾ0-3�У�10-12�б���ȡ��ӡ
*
***********************/

//#include "stdafx.h"
//#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20    /*���ܴ��������к�*/
#define MAX_INPUT 1000 /*ÿ�������е���󳤶�*/


int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int const columns[]);

int main()
{
	int n_columns; //���д�����б��
	int columns[MAX_COLS]; //��Ҫ���������
	char input[MAX_INPUT]; //���������е�����
	char output[MAX_INPUT]; //��������е�����

	//��ȡ�ô��б��
	n_columns = read_column_numbers(columns,MAX_COLS);

	//��ȡ��������ӡʣ���������
	//gets��������׼�����ȡһ���ı����洢����Ϊ�������ݸ����������С��ᶪ�����з����洢һ��'\0'�����ط�NULL��ʾ���ɹ���ȡ��
	//�ַ�������һ����'\0'�ַ���β���ַ���
	while(gets(input) != NULL)
	{
		printf("Original input : %s\n",input);
		rearrange(output,input,n_columns,columns);//������Ϊ�������洢����ֵ��
		printf("Rearranged line : %s\n",output);
	}

	//system("pause");
	return 0;
}

//��ȡ�кţ�������Χ�������
//������������������ⳤ�ȵ�һλ���飬����û�취֪������ĳ��ȣ�ֻ�ܼӸ��������ݡ�
int read_column_numbers(int columns[],int max)
{
	int num = 0;
	int ch;//��û�г�ʼ������Ϊ��һ���������Ǹ�ֵ��

	//ȡ���б�ţ������ȡ����С��0��ֹͣ
	//scanf�ķ���ֵ�ǳɹ�ת�����洢�ڲ����е�ֵ�ø���
	while( num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0 )
		num += 1;

	//ȷ���б�ųɶԳ���
	if ( num%2 != 0 )
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	//���������а������һ�����ֵ��ǲ�������
	while( (ch = getchar()) != EOF && ch != '\n')
		;

	return num;
}

//���������У���ָ���е��ַ�������һ���������NULL��β��
//input�ɱ�,*input���ɱ�
void rearrange(char *output,char const *input,int n_columns,int const columns[])
{
	int col; //columns������±�
	int output_col; //����м�����
	int len; //�����еĳ���

	len = strlen(input);
	output_col = 0;

	//����ÿ���б��
	for (col=0;col<n_columns;col+=2)
	{
		int nchars = columns[col+1] - columns[col] + 1;

		//��������н���������������������ͽ�������
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
		{
			break;;
		}

		//�����������ݿռ䲻����ֻ���ƿ������ɵ�����
		if (output_col + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - output_col - 1;
		}

		//������ص�����
		//char *strncpy(o,s,n);��Դ�ַ���s�е�n���ַ����Ƶ�Ŀ���ַ���o�У�������s�����sС��n����'\0'���
		strncpy(output + output_col , input + columns[col] , nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}

