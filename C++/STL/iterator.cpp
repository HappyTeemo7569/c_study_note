#include"iostream"
#include"list"
using namespace std;

int main()
{
	//������һ������
	list<int> l;
	int len = l.size();
	cout<<len<<endl;
	
	for (int i=0; i<5; i++)
	{
		l.push_back(i);    //������β������Ԫ�أ�β�巨��
	}
		
	//����������һ��ָ��iterator
	list<int>::iterator current = l.begin();   
	//����l��ͷ����������������һ��ָ�룩
	//l.end();  ����β��
	
	while(current != l.end())   
	//l.end()����������β����ָ�����һ���ڵ������Ǹ�λ�ã�Ҫ��Ȼ�򲻳���ֵ�����һ��Ԫ��
	{
		cout<<*current<< " ";
		current++;
	}
	cout << endl;

	//���������λ�ø���������ָ��
	current = l.begin();    // 0
	current ++;     // 1
	current ++;     // 2
	current ++;     // 3
	l.insert(current,100);   //������λ��3���룬3��ԭ��Ԫ�غ���.

	for (list<int>::iterator p = l.begin(); p!=l.end(); p++)   //����
	{
		cout<<(*p) << " ";
	}
	cout << endl;

	return 0;
}