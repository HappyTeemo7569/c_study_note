#include <iostream>
using namespace std;

class complex
{
private:
	int a,b;
	//ͨ����Ԫ������ȫ�ֺ�����ʵ��+����,
	friend complex operator+(complex &c1, complex &c2);
	//��Ԫ����   ȫ�ֺ��� ǰ��++
	friend complex &operator++(complex &c2);
	//����++
	friend complex operator++(complex &c2,int); 
public:
	complex(int a = 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	void printCom()
	{
		cout << a << "+" << b << "i" << endl;
	}
public:
	//ͨ����ĳ�Ա����ʵ��-����
	complex operator-(complex &c2)    //this���Բ�д���ں���
	{
		complex tmp;
		tmp.a = this->a -c2.a;
		tmp.b = b -c2.b;
		return tmp;  //ע�ⷵ��ֵ
	}

	// ǰ��--
	complex& operator--()
	{
		this->a--;
		this->b--;
		return *this;//ע�ⷵ��ֵ
	}
};

complex operator+(complex &c1, complex &c2)
{
	complex tmp;
	tmp.a = c1.a + c2.a;
	tmp.b = c1.b + c2.b;
	return tmp;
}

//ǰ��++ ȫ�ֺ���
complex& operator++(complex &c2)   //���ر�����������������
{
	c2.a++;
	c2.b++;
	return c2;
}

//����++ ����ʹ��c2����������++
complex operator++(complex &c2,int)   
{
	complex tmp;  //��Ҫһ����ʱ����
	tmp=c2;
	c2.a++;
	c2.b++;
	return tmp;
}

int main()
{
	complex c1(1, 2), c2(3, 4);

	// +���������������� ������� �� �Ҳ�����
	complex c3 = c1 + c2;
	c3.printCom();
	

	complex c5 = c1 - c2 ; //c1������������  �ȼ���Complex c5 = c1.operator-(c2);      
	//ͨ����ĳ�Ա��������ɲ���������
	c5.printCom();
	/*-------------------------------------------------------------------------
	Ŀ�� ͨ����ĳ�Ա��������ɲ���������
	1 Ҫ���ϲ�����������һ��������Ҫд����ԭ��   operator-
	2 �ҳ���Ҫ�ĺ��������� д�������������� c1.operator-(c2)        //Complex c5 = c1 - c2 ;
	3 ���ƺ���ԭ�ͣ�����ֵ
	-------------------------------------------------------------------------- */
	++c2;  //ȫ�ֱ���++
	c2.printCom();
	//ȫ�ֺ���ԭ���Ƶ� //Complex& operator++(Complex &c2);    //Complex& operator++(this,Complex &c2); thisָ�뱻����

	c2++;  //����++
	c2.printCom();

	
	return 0;
}