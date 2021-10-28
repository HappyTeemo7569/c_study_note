#include "iostream"
#include "vector"
using namespace std;


void printfArray(vector<int> &v)
{

	int size = v.size();  //  v��Ȼ�൱�����飬�������鲻һ��������Ҫ����num����Ϊ����class����װ��num
	for (int i=0; i<v.size(); i++)
	{
		cout<<v[i];
	}
	cout<<endl;
}

struct Teacher
{
	int age ;
	char name[10];
};

int main()
{
	//����һ�����飨�������飩
	vector<int> v1(5); //�൱��int v[5]
	//vector<int>ģ�����ͣ� �Զ����== != [] =  �Ȳ���������

	for (int i=0; i<5; i++)
	{
		v1[i] = i+1;
	}

	vector<int> v2(10);
	v2 = v1;

	for (int i=0; i<5; i++)
	{
		cout<<v2[i];
	}
	cout<<endl;
	printfArray(v2);

	v2.resize(0);
	cout<<v2.size()<<endl;   //size=0

	//׷��
	vector<int> v3(10);  //Ĭ����0
	v3.push_back(3); //�Ӻ���ӣ���ǰѹ
	v3.push_back(4);
	v3.push_back(5);
	printfArray(v3);

	//�Žṹ��
	struct Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> v4(0);  //ָ��棺vector<Teacher*> v3(0);
	v4.push_back(t1);       //v3.push_back(&t1);
	v4.push_back(t2);
	v4.push_back(t3);
	for (int i=0; i<3; i++)
	{
		cout<<v4[i].age<<endl;
		//struct Teacher *tmp = (struct Teacher *)v3[i];  //����ת����ʡ��������
		//cout<<tmp->age<<endl;
	}

	return 0;
}

