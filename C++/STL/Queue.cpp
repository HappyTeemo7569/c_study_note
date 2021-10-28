/**********************
1.back() ����һ�����ã�ָ�����һ��Ԫ��
2.empty() ������п��򷵻���
3.front() ���ص�һ��Ԫ��
4.pop()  ɾ����һ��Ԫ��
5.push() ��ĩβ����һ��Ԫ��
6.size() ���ض�����Ԫ�صĸ���
***********************/

#include"iostream"
#include"queue"
using namespace std;

struct Teacher
{
	int age ;
	char name[10];
};

//  ->��ָ��ָ�����Ա�������
//  .�ǽṹ��ĳ�Ա�����
void printfFont(queue<Teacher *>  & q)   //����
{
	while(!q.empty())
	{
		//��ȡ����ͷԪ��
		Teacher * tmp = q.front();
		cout<<tmp->age<<endl;
		//��������Ԫ��
		q.pop();
	}
}

int main()
{
	queue<int> q;//��һ������
	
	for (int i=0; i<5; i++)
	{
		q.push(i);  //����������һ��Ԫ��

	}
		
	while(!q.empty())     //����
	{
		int tmp = q.front();  //��ȡ����ͷԪ��
		cout<<tmp<<endl;
		q.pop();             //��������Ԫ��
	}

	//�Žṹ��
	queue<Teacher*> q2;
	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	//x����������һ��Ԫ��
	q2.push(&t1);
	q2.push(&t2);
	q2.push(&t3);
	
	//��ӡ����1�� 
	while(!q2.empty())
	{
		//��ȡ����ͷԪ��
		Teacher * tmp = q2.front();
		cout<<tmp->age<<endl;
		//��������Ԫ��
		q2.pop();
	}
		
	//��ӡ����2�� 
	printfFont(q2);
	return 0;
}