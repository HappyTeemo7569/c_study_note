#include "iostream"
#include "vector"
using namespace std;


void printfArray(vector<int> &v)
{

	int size = v.size();  //  v虽然相当于数组，但和数组不一样，不需要传入num，因为它是class，封装了num
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
	//定义一个数组（弹性数组）
	vector<int> v1(5); //相当于int v[5]
	//vector<int>模板类型， 自动完成== != [] =  等操作符重载

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

	//追加
	vector<int> v3(10);  //默认是0
	v3.push_back(3); //从后面加，往前压
	v3.push_back(4);
	v3.push_back(5);
	printfArray(v3);

	//放结构体
	struct Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;
	vector<Teacher> v4(0);  //指针版：vector<Teacher*> v3(0);
	v4.push_back(t1);       //v3.push_back(&t1);
	v4.push_back(t2);
	v4.push_back(t3);
	for (int i=0; i<3; i++)
	{
		cout<<v4[i].age<<endl;
		//struct Teacher *tmp = (struct Teacher *)v3[i];  //类型转换，省的他报错。
		//cout<<tmp->age<<endl;
	}

	return 0;
}

