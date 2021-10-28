/**********************
��Ԫ��
	��Ԫ�������ܹ��������е�˽�г�Ա�ķǳ�Ա������
	��Ԫ�������﷨�Ͽ���������ͨ����һ�������ڶ����Ϻ͵���������ͨ����һ����
	��Ԫ��ϵ���߶Գ��ԡ��� A �� B ����Ԫ���� B ��һ���� A ����Ԫ��
	��Ԫ��ϵ���ߴ����ԡ��� B �� A ����Ԫ��C �� B ����Ԫ������ C ��һ���� A ����Ԫ��
���ü��ص�
	��Ԫ�ṩ�˲�ͬ��ĳ�Ա����֮�䡢��ĳ�Ա������һ�㺯��֮��������ݹ���Ļ��ơ�ͨ����Ԫ��һ����ͬ��������һ�����еĳ�Ա�������Է������е�˽�г�Ա�ͱ�����Ա��
	��Ԫ����ȷʹ������߳��������Ч�ʣ���ͬʱҲ�ƻ�����ķ�װ�Ժ����ݵ������ԣ����³����ά���Ա�

***********************/

#include<iostream>
#include<cmath>
#define PI 3.14
using namespace std;

//��������������涨����Ԫ��
class Point;
class MyCircle;

class Point
{
	friend class MyCircle; //������Ԫ��,���з��������Ե��õ��������˽�г�Ա��
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	};
	void Getxy();

	//���������Ԫ��ֻ��ͨ���������˽�б���
	double getX0(){return x;}
	double getY0(){return y;}

	friend double Distance(Point &a, Point &b);  //ȫ�ֺ�����Ϊ��Ԫ����
	//friend void MyCircle::showPoint(); ����ĳ�����ĺ�����Ϊ��Ԫ����
private:
	double x, y;
};

class MyCircle
{
public:
	MyCircle(double r)
	{
		m_r = r;
		MidP.x = 0;
		MidP.y = 0;
	}
public:
	void showPoint();
	void judge(Point &p);
	void setCir(double x, double y, double r);

	double getS()
	{
		m_s = PI*m_r*m_r;
		return m_s;
	}	

private:
	Point MidP;  //Բ��
	double m_r;  //Բ�뾶
	double m_s;
};


void Point::Getxy()
{
	cout << "(" << x << "," << y << ")" << endl;
}

void MyCircle::showPoint()
{
	cout << "(" << MidP.x << "," << MidP.y << ")" << endl;
}

void MyCircle::setCir(double x, double y, double r)
{
	//������Ҳ������ڲ�
	MidP.x = x; MidP.y = y; m_r = r;
}

void MyCircle::judge(Point &p)
{
	double s = (MidP.x-p.x)*(MidP.x-p.y) + (MidP.y-p.y)*(MidP.y-p.y) - m_r*m_r ;
	if (s > 0){cout << "out" << endl;}
	else{cout << "int" << endl;}
}


double Distance(Point &a, Point &b)
{
	double dx = a.x - b.x;  //ֱ�ӷ�����˽�г�Ա
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
int main(void)
{
	Point p1(3.0, 4.0), p2(6.0, 8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1, p2);
	cout << "Distance is" << d << endl;

	MyCircle c1(1);
	c1.setCir(0,0,1);
	c1.judge(p1);
	c1.showPoint();

	return 0;
}
