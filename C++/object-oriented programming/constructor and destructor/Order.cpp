#include <iostream>
#include <stdio.h>
using namespace std;

class ABCD
{
public:
	ABCD(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		//����˳��1.1
		printf("ABCD() construct, a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	~ABCD()
	{
		printf("~ABCD() destructor,a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
	}
	int getA()
	{
		return this->a;
	}
protected:
private:
	int a;
	int b;
	int c;
};

class MyE
{
public:
	//����˳��1
	MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
	{
		cout<<"MyD()"<<endl;//����˳��1.2
	}
	~MyE()
	{
		cout<<"~MyD()"<<endl;
	}
	//����˳��2.1
	MyE(const MyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)  //�������캯����ҲҪ�ӳ�ʼ���б�
	{
		printf("MyD(const MyD & obj)\n");//����˳��2.2
	}

protected:
	//private: 
public:  
	ABCD abcd1; //c++��������֪����ι���abc1
	ABCD abcd2;
	const int m;

};

//����˳��2
int doThing( MyE mye1) //ʵ�ε����βΡ����ÿ������캯�� MyE(constMyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)
{
	//����˳��3
	printf("doThing() mye1.abc1.a:%d \n", mye1.abcd1.getA()); 
	//ʵ�δ����βε�ֵ��abcd1(1,2,3),abcd2(4,5,6)/��������ִ��abcd1(7,8,9),abcd2(10,11,12),m(100) ������doThing(myE)-��mye1.abc1.a=7��   staticֻ��ʼ��һ�Ρ�                    
	return 0;
}

int main()
{
	MyE myE; //���ù��캯��MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)

	doThing(myE);  
	return 0;
}

