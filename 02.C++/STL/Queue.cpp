/**********************
1.back() 返回一个引用，指向最后一个元素
2.empty() 如果队列空则返回真
3.front() 返回第一个元素
4.pop()  删除第一个元素
5.push() 在末尾加入一个元素
6.size() 返回队列中元素的个数
***********************/

#include"iostream"
#include"queue"
using namespace std;

struct Teacher
{
	int age ;
	char name[10];
};

//  ->是指针指向其成员的运算符
//  .是结构体的成员运算符
void printfFont(queue<Teacher *>  & q)   //引用
{
	while(!q.empty())
	{
		//获取队列头元素
		Teacher * tmp = q.front();
		cout<<tmp->age<<endl;
		//弹出队列元素
		q.pop();
	}
}

int main()
{
	queue<int> q;//建一个队列
	
	for (int i=0; i<5; i++)
	{
		q.push(i);  //向队列中添加一个元素

	}
		
	while(!q.empty())     //遍历
	{
		int tmp = q.front();  //获取队列头元素
		cout<<tmp<<endl;
		q.pop();             //弹出队列元素
	}

	//放结构体
	queue<Teacher*> q2;
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	//x向队列中添加一个元素
	q2.push(&t1);
	q2.push(&t2);
	q2.push(&t3);
	
	//打印方法1： 
	while(!q2.empty())
	{
		//获取队列头元素
		Teacher * tmp = q2.front();
		cout<<tmp->age<<endl;
		//弹出队列元素
		q2.pop();
	}
		
	//打印方法2： 
	printfFont(q2);
	return 0;
}