#include <iostream>
#include <cstdio>
using namespace std;

void GetStatic()
{
	int a = 0;
	static int b = 10; //bֻ��ʼ��һ�Σ��ڶ��ε��ã�������ֵ
	printf("a:%d b:%d \n",a,b);
	a++;
	b++;
}

static void myprintf()//�������myprintfֻ�������.c�б�ʹ�� ��֧�ֱ��.c����ã����Ǽ�extern
{
	printf("�����յ��磬�������ǿ�\n");
	printf("����c���ԣ����������壨c++��\n");
}

class Test3
{
public:
	Test3(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<m_a<<endl;
		count ++;
		cout<<"����ִ��"<<endl;
	}
	~Test3()
	{
		cout<<"����ִ��"<<endl;
	}

	static int getCount(){ return count;}
	void setCount(int i){count = i;}
	void showCount(){cout << count << endl;}

protected:
private:
	int m_a; //���ھ���Ķ���
	int m_b;
	static int count;//static���εı������ߺ�������������࣬�����ھ���Ķ���

};
int Test3::count  = 0;  //�������ε�static���εı������ߺ�����һ��Ҫ��class������������ʼ��
//���ڸ��߱��������ҿ����ڴ档

int main()
{
	Test3 t1(1, 3), t2(3, 4), t3(5, 65);

	//cout<<Test3::getCount()<<endl;//int getCount()��ʧ�ܣ�; //���ֵȼ�  
	//static int getCount();//���ܷ���static count
	t3.setCount(10);
	cout<<t3.getCount()<<endl;

	cout << "***********" << endl;

	t1.setCount(100);
	t2.showCount();
	return 0;
}



/**********************
//c++�����е�static��������һ��static int s����s����һ���࣬�����ھ������ ��
���С���һ������ģ�������������Ҳ��ġ�
***********************/