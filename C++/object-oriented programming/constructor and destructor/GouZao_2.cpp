#include <iostream>
#include <stdio.h>
using namespace std;

class DD
{
public:
	DD(int d) //DD�ж������вι��캯��
	{
		cout<<d<<endl;  //���1,2
		m_d = d;
	}
private:
	int m_d;
};

class EE
{
public:
	//���캯���ĳ�ʼ���б�
	EE(int _a):d1(1),d2(2)//����д��EE(int _a):d1(2),d2(1)������˳��1.���ձ��������˳��ȥ��ʼ������d
	{
		//����˳��2.���ù��캯���������
		a = _a;
		cout<<_a<<endl; //���3
	}

protected:
private:
	int a;
	DD d1;  //���ձ��������˳��
	DD d2;
};

int main()
{
	EE e1(3);
	return 0;	
}

//������1��2��3  ��(d1��d2��e1)
//�����һ�����Ա��������һ�����ṹ�����Ҹó�Աֻ��һ���������Ĺ��캯����û��Ĭ�Ϲ��캯����
//���������ʼ����ʱ��ͱ����ȵ��ø����Ա�Ĵ��ι��캯�������û�г�ʼ���б���ô������
