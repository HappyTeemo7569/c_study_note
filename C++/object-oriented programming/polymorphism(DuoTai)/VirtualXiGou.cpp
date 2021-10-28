/**********************
������������virtual destructor��
�ڶ����ж���һ���������Ȼ����ָ�븳������ָ����������ͨ������ָ��ȥ�ͷŸ��������ʱ��
��������������������������������ôֻ����ø��������������������������������ᱻ���ã����ܻᵼ���ڴ�й¶��
����������������Ϊ�麯������ô���Ȼ�������������������Ȼ���ٵ��ø��������������
C++����淶���ڶ���һ����ʱ��������������������Ϊ�麯��
***********************/

#include<iostream>
using namespace std;

class AA
{
public:
	AA(int a= 0)
	{
		this->a = a;
		print(); 
	}
	virtual ~AA()
	{
		cout<<"P XiGou do"<<endl;
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

	~BB()
	{
		cout<<"C XiGou do"<<endl;
	}
	virtual void print()
	{
		cout<<"C"<<"a"<<a<<"b"<<b<<endl;
	}
private:
	int b ;
};

void howToDelete(AA *pBase)
{
	delete pBase;
}
int main()
{
	BB *b1 = new BB(1, 2);

	b1->print();

	howToDelete(b1);
	//delete b1;
	return 0;
}