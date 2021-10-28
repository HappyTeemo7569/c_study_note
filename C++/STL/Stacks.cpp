/**********************
empty() �ж��Ƿ�Ϊ�գ����򷵻���
pop()  �Ƴ�ջ��
push() ջ�����
size() ���ش�С
top()  ����ջ��
***********************/

#include"iostream"
#include"stack"
#include <stdio.h>
using namespace std;

struct Teacher
{
	int age ;
	char name[10];
};

void printfStack( stack<Teacher> &s)   //��ӡage
{
	//ջ����
	while(!s.empty())
	{
		//��ȡջ��Ԫ��
		cout<<s.top().age<<endl;
		//����ջ��Ԫ��
		s.pop();
	}
}

int main()
{

	//����һ��ջ
	stack<int> s;
	//ջ��ֵ
	for (int i=0; i<5; i++)
	{
		//��ջ�з�Ԫ��
		s.push(i+1);
	}

	//ջ����
	while(!s.empty())  //�ǿս���
	{
		int tmp = s.top();   //��ȡջ��Ԫ��

		s.pop();             //����ջ��Ԫ��
		printf("%d \n", tmp);
	}

	////�Žṹ��/////////
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	
	stack<Teacher> s2;
	s2.push(t1);
	s2.push(t2);
	s2.push(t3);

	printfStack(s2);   //��ӡage
	return 0;
}