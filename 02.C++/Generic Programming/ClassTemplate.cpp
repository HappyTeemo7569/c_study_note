#include<iostream>
#include <stdio.h>
using namespace std;

template<typename T>    //定义一个类模板
class AA
{
public:
	AA(T a)
	{
		this->a = a;
	}
	void setA(T a)
	{
		this->a = a;
	}
	T getA()
	{
		return this->a;
	}
	void printA() const;
protected:
private:
	T a;
};

class BB : public AA<int>       //子类继承模板父类还需要指定类型
{
public:
	//BB(int a, int b) : AA(a)   报错
	BB(int a, int b) : AA<int>(a)   //用a初始化AA的构造函数的a，用b初始化BB的b  
	{
		this->b = b;
	}

private:
	int b;
};

//友元函数和模板
template<typename T>
class Complex
{
public:
    Complex(T r = 0, T i = 0);
    Complex(T a)
    {
        Real = a; Image = 0;
    }
    void print();
    friend Complex<T>operator+(Complex<T> &c1, Complex<T>&c2)    //Complex 要写在里面，写在外面会出错
    {
        T r = c1.Real + c2.Real;     
		T i = c1.Image + c2.Image;
        return Complex<T>(r, i);
    }
protected:
private:
    T Real,Image;
};
 
template<typename T>
Complex<T>::Complex(T r, T i)
{
    Real = r; Image = i;
}
 
template<typename T>
void Complex<T>::print()
{
    cout << '(' << Real << " , " << Image << ')' << endl;
}

///////////////////////数组类/////////////////////
template <class T>
//一个简单的模板类，只有构造函数、析构函数、添加元素函数，但已经能够说明模板类的特征了。
class MyArray
{
private:
	int m_nTotalSize;    //数组总长度
	int m_nValidSize;    //数组有效长度，即当前元素数
	T * m_pData;    //数据指针
public:
	//构造函数
	MyArray(int nSize=2)    //假设默认数组长度为2
	{
		m_pData=new T[nSize];
		m_nTotalSize=nSize;
		m_nValidSize=0;
	}

	//获取数组有效长度
	int GetValidSize()
	{
		return m_nValidSize;
	}

	//获取数组总长度
	int GetTotalSize()
	{
		return m_nTotalSize;
	}

	//返回某一位置元素
	T Get(int pos)
	{
		return m_pData[pos];
	}

	//添加一个元素
	void Add(T value)
	{
		if(m_nValidSize<m_nTotalSize)    //若数组未满
		{
			m_pData[m_nValidSize]=value;
			m_nValidSize++;
		}
		else    //数组满时动态增加数组大小
		{
			T * pOldData=m_pData;    //保存当前数据指针
			m_pData=new T[m_nTotalSize*2];    //原先数组空间大小扩大两倍
			for(int i=0;i<m_nTotalSize;i++)    //拷贝原先数据
			{
				m_pData[i]=pOldData[i];
			}
			m_nTotalSize*=2;    //当前数组总长度更新
			delete pOldData;    //释放旧数组占用的内存
			m_pData[m_nValidSize]=value;    //添加新元素
			m_nValidSize++;    //更新数组有效程度
		}
	}
	//析构函数
	virtual ~MyArray()
	{
		if(m_pData!=NULL)
		{
			delete []m_pData;
			m_pData=NULL;
		}
	}
};


int main()
{
	//要把类模板具体成类型后，才能定义变量 （语法）
	AA<int> a(10);             
	BB b1(1, 2);

	///////////////////////友元类和模板///////////////////
	Complex<int>c1(1, 2);
	Complex<int>c2(3, 4);
	Complex<int>c3 = c1 + c2;
	c3.print();

	///////////////////////数组类////////////////////////
	MyArray<int> array1;
	cout<<"数组总长度:"<<array1.GetTotalSize()<<" 数组有效长度:"<<array1.GetValidSize()<<endl;
	array1.Add(1);
	array1.Add(2);
	array1.Add(3);
	cout<<"数组总长度:"<<array1.GetTotalSize()<<" 数组有效长度:"<<array1.GetValidSize()<<endl;
	cout<<array1.Get(0)<<" "<<array1.Get(1)<<" "<<array1.Get(2)<<endl;

	MyArray<double> array2;
	cout<<"数组总长度:"<<array2.GetTotalSize()<<" 数组有效长度:"<<array2.GetValidSize()<<endl;
	array2.Add(1.1);
	array2.Add(2.2);
	array2.Add(3.3);
	cout<<"数组总长度:"<<array2.GetTotalSize()<<" 数组有效长度:"<<array2.GetValidSize()<<endl;
	cout<<array2.Get(0)<<" "<<array2.Get(1)<<" "<<array2.Get(2)<<endl;


	return 0;
}

/**********************
类模板里面有static数据成员或者成员函数。
假设int型生成了i1,i2,i3,则共用static1;
float生成了f1,f2,f3,则共用static2;
***********************/