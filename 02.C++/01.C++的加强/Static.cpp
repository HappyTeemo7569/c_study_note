#include <iostream>
#include <cstdio>
using namespace std;

void GetStatic()
{
	int a = 0;
	static int b = 10; //b只初始化一次，第二次调用，保留新值
	printf("a:%d b:%d \n",a,b);
	a++;
	b++;
}

static void myprintf()//这个函数myprintf只能在这个.c中被使用 不支持别的.c里调用，除非加extern
{
	printf("锄禾日当午，生活真是苦\n");
	printf("送走c语言，来了它大叔（c++）\n");
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
		cout<<"构造执行"<<endl;
	}
	~Test3()
	{
		cout<<"析构执行"<<endl;
	}

	static int getCount(){ return count;}
	void setCount(int i){count = i;}
	void showCount(){cout << count << endl;}

protected:
private:
	int m_a; //属于具体的对象
	int m_b;
	static int count;//static修饰的变量或者函数，属于这个类，不属于具体的对象

};
int Test3::count  = 0;  //类中修饰的static修饰的变量或者函数，一定要在class的外面这样初始化
//等于告诉编译器给我开辟内存。

int main()
{
	Test3 t1(1, 3), t2(3, 4), t3(5, 65);

	//cout<<Test3::getCount()<<endl;//int getCount()会失败，; //两种等价  
	//static int getCount();//才能返回static count
	t3.setCount(10);
	cout<<t3.getCount()<<endl;

	cout << "***********" << endl;

	t1.setCount(100);
	t2.showCount();
	return 0;
}



/**********************
//c++语言中的static，类中有一个static int s；则s属于一个类，不属于具体对象 。
公有。有一个对象改，在其他对象中也会改。
***********************/