/**********************
	��̬��polymorphism��:����״̬��������������У����ò�ͬ�����ͬ�ַ����������ͬ����Ϊ��
	��̬��ͨ���麯��ʵ�ֵġ�
	��̬���ƣ�����������ָ�븳������ָ���������������󸳸��������ã�ͨ������ָ�������ȥ���ø����е�ĳ���麯����
���������д�˸��麯������ô���õĽ��������е��麯�������򽫵��ø����е��麯����

	��̬�����������������������������C++��java��.net��php����
	1.Ҫ��̳У��Ӹ��� ��
	2.Ҫ��virtual��д
	3.Ҫ�и���ָ��ָ���������

	C����ָ����C++�������ϵ���ҫ��C����ָ��һ���������÷�������������
***********************/

#include"iostream"
using namespace std;

class base
{
public:
	int k;

	void printI()
	{
		cout << "k1��" << k << endl;;    //û���ᣬ������
	}
	virtual void printJ()
	{
		cout << "k2��" << k << endl;  //û���ᣬ��д��
	}
	virtual void printK()
	{
		cout << "k3��" << k << endl;  //�л���
	}
protected:
private:

};
//class base1 ��class base2 ����virtual�ᱨ�����μ̳�
//��������̳�ͬһ�����࣬�����������ֱַ�̳�����������
//����̳����������ԣ���������̳еĿ����������麯��ָ�롣����base1��base2����һ��base�Ŀ�����
//�麯��ֻ�Ǽ̳���ԭ������ָ�룬û���µ��γɣ��������ǿ�����һ�ݡ�
class base1 :virtual public base
{
public:
	int i;
	void printI()  //���ǣ�������һ��
	{
		cout << "i��" << i << endl;
	}
protected:
private:

};

class base2 : virtual public base
{
public:
	int j;
	//Ĭ�����麯�������Բ��ü�virtual�ؼ��֣���Ϊ�����ӿɶ��ԣ��������virtual�ؼ������Ρ�
	void printJ()//��д���������ָ��
	{
		cout << "j��" << j << endl;
	}
protected:
private:
};

class  C : public base1, public base2
{
public:
protected:
private:
};

int main()
{

	C c1;
	c1.i = 1;
	//c1.j = 2;
	c1.k = 100;
	
	c1.printI();
	c1.printJ(); //���jδ�����������ֵ
	//��̳е���ʱ���������û����д���Ż��Ҹ��ࡣ
	c1.printK();
	return 0;
}