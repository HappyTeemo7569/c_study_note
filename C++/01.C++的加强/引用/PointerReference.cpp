#include <iostream>
#include <stdlib.h>
using namespace std;

struct AdvTeacher
{
	char name[32];
	int age;
};

void getTeacher01(AdvTeacher **p)//����ָ��
{
	AdvTeacher *tmp = (AdvTeacher*)malloc(sizeof(AdvTeacher));
	tmp->age = 10;
	*p = tmp;   //�ö���ָ��˦��һ��
}

//////����� �ṹ�����ָ������� ָ������ã� ����ͬgetTeacher01 ��
//* &p2=>&  *p2    p2�� t2�ı��� ,��p2��ֵ���Ǹ�t2��ֵ
void getTeacher02(AdvTeacher *&p2)
{
	p2 = (AdvTeacher*)malloc(sizeof(AdvTeacher));
	p2->age = 20;
}

void getTeacher03(AdvTeacher &t3)  //����������� ��ô myT3��copy��t3 ,��ò����� myT3.ageû���κι�ϵ
{
	t3.age = 30;
}

int main()
{
	AdvTeacher *t1 = NULL;
	AdvTeacher *t2 = NULL;
	getTeacher01(&t1);  //�����ڴ�ռ䣬�ڽ���аѵ�ַ˦����
	getTeacher02(t2);   //����C++�Զ�ȡ��ַ�����ñ�����һ����ַ

	AdvTeacher  myT3;
	myT3.age = 10;
	getTeacher03(myT3);  //myT3.age = 30;

	cout << t1->age << endl;
	cout << t2->age << endl;
	cout << myT3.age << endl;
	return 0;
}