#include<iostream>
#include <stdio.h>
using namespace std;

template<typename T>    //����һ����ģ��
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

class BB : public AA<int>       //����̳�ģ�常�໹��Ҫָ������
{
public:
	//BB(int a, int b) : AA(a)   ����
	BB(int a, int b) : AA<int>(a)   //��a��ʼ��AA�Ĺ��캯����a����b��ʼ��BB��b  
	{
		this->b = b;
	}

private:
	int b;
};

//��Ԫ������ģ��
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
    friend Complex<T>operator+(Complex<T> &c1, Complex<T>&c2)    //Complex Ҫд�����棬д����������
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

///////////////////////������/////////////////////
template <class T>
//һ���򵥵�ģ���ֻ࣬�й��캯�����������������Ԫ�غ��������Ѿ��ܹ�˵��ģ����������ˡ�
class MyArray
{
private:
	int m_nTotalSize;    //�����ܳ���
	int m_nValidSize;    //������Ч���ȣ�����ǰԪ����
	T * m_pData;    //����ָ��
public:
	//���캯��
	MyArray(int nSize=2)    //����Ĭ�����鳤��Ϊ2
	{
		m_pData=new T[nSize];
		m_nTotalSize=nSize;
		m_nValidSize=0;
	}

	//��ȡ������Ч����
	int GetValidSize()
	{
		return m_nValidSize;
	}

	//��ȡ�����ܳ���
	int GetTotalSize()
	{
		return m_nTotalSize;
	}

	//����ĳһλ��Ԫ��
	T Get(int pos)
	{
		return m_pData[pos];
	}

	//���һ��Ԫ��
	void Add(T value)
	{
		if(m_nValidSize<m_nTotalSize)    //������δ��
		{
			m_pData[m_nValidSize]=value;
			m_nValidSize++;
		}
		else    //������ʱ��̬���������С
		{
			T * pOldData=m_pData;    //���浱ǰ����ָ��
			m_pData=new T[m_nTotalSize*2];    //ԭ������ռ��С��������
			for(int i=0;i<m_nTotalSize;i++)    //����ԭ������
			{
				m_pData[i]=pOldData[i];
			}
			m_nTotalSize*=2;    //��ǰ�����ܳ��ȸ���
			delete pOldData;    //�ͷž�����ռ�õ��ڴ�
			m_pData[m_nValidSize]=value;    //�����Ԫ��
			m_nValidSize++;    //����������Ч�̶�
		}
	}
	//��������
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
	//Ҫ����ģ���������ͺ󣬲��ܶ������ ���﷨��
	AA<int> a(10);             
	BB b1(1, 2);

	///////////////////////��Ԫ���ģ��///////////////////
	Complex<int>c1(1, 2);
	Complex<int>c2(3, 4);
	Complex<int>c3 = c1 + c2;
	c3.print();

	///////////////////////������////////////////////////
	MyArray<int> array1;
	cout<<"�����ܳ���:"<<array1.GetTotalSize()<<" ������Ч����:"<<array1.GetValidSize()<<endl;
	array1.Add(1);
	array1.Add(2);
	array1.Add(3);
	cout<<"�����ܳ���:"<<array1.GetTotalSize()<<" ������Ч����:"<<array1.GetValidSize()<<endl;
	cout<<array1.Get(0)<<" "<<array1.Get(1)<<" "<<array1.Get(2)<<endl;

	MyArray<double> array2;
	cout<<"�����ܳ���:"<<array2.GetTotalSize()<<" ������Ч����:"<<array2.GetValidSize()<<endl;
	array2.Add(1.1);
	array2.Add(2.2);
	array2.Add(3.3);
	cout<<"�����ܳ���:"<<array2.GetTotalSize()<<" ������Ч����:"<<array2.GetValidSize()<<endl;
	cout<<array2.Get(0)<<" "<<array2.Get(1)<<" "<<array2.Get(2)<<endl;


	return 0;
}

/**********************
��ģ��������static���ݳ�Ա���߳�Ա������
����int��������i1,i2,i3,����static1;
float������f1,f2,f3,����static2;
***********************/