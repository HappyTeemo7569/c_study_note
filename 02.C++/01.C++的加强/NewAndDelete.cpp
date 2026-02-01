#include <stdio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class Test1
{
public:
	Test1(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"GouZao"<<endl;
	}
	~Test1()
	{
		cout<<"XiGou"<<endl;
	}
	void printTest()
	{
		cout << m_a << m_b << endl;
	}
protected:
private:
	int m_a;
	int m_b;
};


//指针做函数参数
//Test1 *p5 = NULL; CreateTest1(&p5); p5是地址，&p5（即p）存的是p5地址
int CreateTest1(Test1 **p)    //p是二级指针，一级指针取地址是二级指针
{
	Test1 *tmp = new Test1(5, 6);
	*p = tmp;//二级指针p存了实参（指针P3）的地址 *（实参的地址）去间接修改实参（P3）的值
	return 0;
}


int CreateTest2(Test1 * &myp)  // 编译器遇到&myp（引用）自动帮你取地址 
{
	myp = new Test1(7, 8); //p是实参的地址 *（实参的地址）去间接修改实参的值
	return 0;
}

int main()
{
	///////////////基本类型///////////////
	int *p1 = new int;  //int *p = (int*)malloc(sizeof(int));
	*p1 = 10;
	printf("%d\n",*p1);
	delete p1;

	//////////////数组///////////////////
	int *p2 = new int[10]; //int *p = (int *)malloc(10*sizeof(int));
	for (int i=0; i<10; i++)  //填值
	{
		p2[i] = i+1;
		printf("%d\n", p2[i]);
	}
	delete[] p2;  //释放  delete p1[];错误   delete p1;没释放完

	//////////////类////////////////////
	Test1 *p3 = new  Test1(3, 4);//c++中的new能自动的调用类的构造函数
	p3->printTest();
	delete p3;   //delete能调用类的析构函数
		
	Test1 *p4 = (Test1 *)malloc(sizeof(Test1));//malloc不会调用类的构造函数 
	p4->printTest();
	free(p4);   //free也不会调用类的析构函数

	cout << "*****************" << endl; 
	////////////指针做函数参数///////////
	Test1 *p5 = NULL;
	CreateTest1(&p5);
	p5->printTest();
	CreateTest2(p5);
	p5->printTest();
	delete p5;

	return 0;
}