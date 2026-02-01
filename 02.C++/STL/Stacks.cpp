/**********************
empty() 判断是否为空，是则返回真
pop()  移除栈顶
push() 栈顶添加
size() 返回大小
top()  返回栈顶
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

void printfStack( stack<Teacher> &s)   //打印age
{
	//栈遍历
	while(!s.empty())
	{
		//获取栈顶元素
		cout<<s.top().age<<endl;
		//弹出栈顶元素
		s.pop();
	}
}

int main()
{

	//定义一个栈
	stack<int> s;
	//栈赋值
	for (int i=0; i<5; i++)
	{
		//往栈中放元素
		s.push(i+1);
	}

	//栈遍历
	while(!s.empty())  //非空进入
	{
		int tmp = s.top();   //获取栈顶元素

		s.pop();             //弹出栈顶元素
		printf("%d \n", tmp);
	}

	////放结构体/////////
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	
	stack<Teacher> s2;
	s2.push(t1);
	s2.push(t2);
	s2.push(t3);

	printfStack(s2);   //打印age
	return 0;
}