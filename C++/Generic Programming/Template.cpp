#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


//����ģ�����м�������Ҫд��������
void  swap(int &a, int &b)       
{
	int c ;
	c = a;
	a = b;
	b = c;
}

void  swap(float &a, float &b)
{
	float c ;
	c = a;
	a = b;
	b = c;
}

//ģ��
template<typename T>//ÿ�ζ�Ҫ����һ������
void swap2(T &a, T &b)
{
	T c;
	c = a;
	a = b;
	b = c;
	cout << a << b << endl;
}

//ģ�������
template<typename T>
void sortArray(T *a, int num)
{
	int i =0, j = 0;
	T tmp;

	for (i=0; i<num; i++)
	{
		for (j=i; j<num; j++)
		{
			if (a[i] < a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

template<class T>//����һ��д��һ��
void printfArray(T *a, int num)
{
	cout<<endl;
	for (int i=0; i<num; i++)
	{
		cout<<a[i]<<" ";
	}
}

template <class T>
T sum(T data[],int nsize)
{
	T sum=0;
	for(int i=0;i<nsize;i++)
	{
		sum+=data[i];
	}
	return sum;
}

int main()
{
	int a = 1, b = 2;
	swap(a, b);
	float a1 = 1, b1 = 2;
	swap(a1, b1);
	
	//��ģ��
	//���ͱ�̵ĵ��÷�ʽ������
	//1.�Զ������Ƶ�
	int x =1, y =2;
	swap2(x, y);
	printf("x:%d y:%d \n", x, y);

	//2.�������͵���
	float x1= 1.0, y1 = 2.0;
	swap2<float>(x1, y1);  //�����﷨��ʽ��<float>�����Ͳ�����
	printf("x1:%f y1:%f \n", x1, y1);

	///////////////ģ������////////////////
	int a5[10] = {1,3,4,5,2,3,44,6,3};
	int num = sizeof(a5)/sizeof(*a5);
	sortArray<int>(a5, num);
	printfArray<int>(a5, num);
	  
	char buf[] = "163addeadfdsafdsaf";
	int len = strlen(buf);
	sortArray<char>(buf, len);
	printfArray<char>(buf, len);

	int data1[]={1,2,3,4,5};
	float data2[]={1.1,2.2,3.3,4.4,5.5};
	double data3[]={1.1,2.2,3.3,4.4,5.5};
	cout<<sum(data1,5)<<endl<<sum(data2,5)<<endl<<sum(data3,5);


	return 0;
}