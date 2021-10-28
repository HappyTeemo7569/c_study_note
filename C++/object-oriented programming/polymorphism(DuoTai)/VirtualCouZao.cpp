#include"iostream"
using namespace std;

class AA
{
public:
	AA(int a= 0)
	{    
		this->a = a;
		print(); //�ڹ��캯��������ʵ�ֶ�̬��
	}

	virtual void print()
	{
		cout<<"P"<<"a"<<a<<endl;
	}
protected:
	int a ;
};

class BB : public AA
{
public:
	BB(int a= 0, int b = 0)
	{
		this->a = a;
		this->b = b;

	}
	virtual void print()
	{
		cout<<"C"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToPrintf(AA *pBase)
{
	pBase->print();  
}

int main()
{
	//AA a1;
	BB b1;
	//howToPrintf(&a1);
	howToPrintf(&b1);
	return 0;
}

/**********************
*���캯������ʵ�ֶ�̬
*���๹�죺
1.��ִ�и��๹�죬��ʼ������vptrָ�룬ָ������麯������ʱ���๹���������printf���޷��ҵ�������麯��printf��
2.���๹�캯�����������๹�캯��ִ�У�vptr�ض���������麯����
*ֻ�е���������ɺ����ȷ��vptr��ָ��
***********************/