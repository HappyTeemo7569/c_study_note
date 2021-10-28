
#include "iostream"
#include "Array.h"
using namespace std;


Array::Array(int length)
{
    if( length < 0 )
    {
        length = 0;
    }
    
    mLength = length;
    mSpace = new int[mLength];
}

//copy构造函数，不定义会段错误
Array::Array(const Array& obj)
{
    mLength = obj.mLength;
    
    mSpace = new int[mLength];
    
    for(int i=0; i<mLength; i++)
    {
        mSpace[i] = obj.mSpace[i];
    }
}

int Array::length()
{
    return mLength;
}

void Array::setData(int index, int value)
{
    mSpace[index] = value;
}

int Array::getData(int index)
{
    return mSpace[index];
}

Array::~Array()
{
    mLength = -1;
    delete[] mSpace;
}

//操作符重载
//printf("array %d: %d\n", i, a1[i]) ;
//a1[i] = 1;
int&  Array::operator[] (int i)  //返回元素本身，返回值用引用
{
	 return mSpace[i];
}


//Array a3(100);
//a3 = a2; //执行=操作
// 	1)如果a3已经分配内存需要释放
//	2）根据a2开辟内存空间 把a2的值copy到a3中
Array&  Array::operator=(Array &a2)
{
	if (this->mSpace != NULL)
	{
		delete[] mSpace;
		mLength = 0;
	}
	this->mLength = a2.mLength;
	this->mSpace = new int[this->mLength];

	for (int i=0; i<this->mLength; i++)
	{
		mSpace[i] = a2[i];  //调用拷贝构造函数
	}
	return *this;  //注意返回值，如果是void不支持连等。
}


//a2.operator==(a1);
//if (a2==a1)
bool Array::operator==(Array &a1)
{
	//a1和a2的长度是不是相等
	if (this->mLength != a1.mLength)
	{
		return false;
	}
	//a1 a2的每一个数组元素是不是相等
	for (int i=0; i<this->mLength; i++)
	{
		if (this->mSpace[i] != a1[i])
		{
			return false;
		}
	}
	return true;
}

//if (a2 != a1)
bool  Array::operator!=(Array &a1)
{
	return !(*this == a1 );  //调用==
}


