/**********************
���麯����Pure Virtual Function���ͳ����ࣨAbstract Class��
���麯����ֻ������û��ʵ�ֵ��麯��������Ҫ���������ֵĺ�����ӡ�= 0����

�����ࣺ���д��麯�����ࡣ
�����಻�ܱ�ʵ��������ͨ�������಻�ܶ���������󣬳�����ͨ����������Ϊ������ĸ���ʹ�õģ���������ࡣ
	���һ������������಻��д�丸���е����д��麯������ô������Ҳ�ǳ����࣬���������������
	��֮������һ�������ࣨconcrete class�������������������
***********************/

//�����ô�������ʵ�ֽӿڣ��ӿ���ֻ�к���ԭ�Ͷ��壬û���κ����ݶ��塣

#include <iostream>
using namespace std;

class figure  //������
{
public:
	virtual  void show_area() = 0 ; //���麯��
	void printf()
	{
		cout<<"test"<<endl;
	}

protected:
	double x;
	double y;
};

class tri : public figure     //������
{
public:
	tri(double x= 1, double y = 2)     //�趨Ĭ��ֵ 
	{
		this->x = x;
		this->y = y;
	}

	void show_area()  //����̳г����ֻ࣬�а����еĴ��麯����ʵ���˲���ʵ������
	{
		cout<<"3_Area:"<<x*y*0.5<<endl;
	}
protected:
private:
};

class square  : public figure   //�ı���
{
public:
	square(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"4_Area:"<<x*y<<endl;
	}
protected:
private:
};

class  circle  : public figure     //Բ
{
public:
	circle(double x= 1, double y = 2)
	{
		this->x = x;
		this->y = y;
	}
	void show_area()
	{
		cout<<"0_Area:"<<3.14*x*x<<endl;
	}
protected:
private:
};

//�ӿ����ͣ�����һ��ͼ�Σ���ʾ�����
//�ȼ̳и��õĿ�ܡ�
//��Ҫ�ö�̳У�����ĸ�����Զ���ڱ�����Ӧ����ϴ��麯��ʵ�ֽӿڡ�
void objShow(figure *pBase)   //��̬�����
{
	pBase->show_area();
}

int main()
{
	//figure f1;  error��ֱ���ó����ඨ�����Ķ����﷨�涨��
	figure *pBase = NULL;    
	//figure f();  error,�����಻����Ϊ��������
	//void g(figure); error,�����಻����Ϊ��������
	//figure & h(figure &); ok,�������������������

	tri t1;
	square s1;
	circle c1;
	
	//���÷�ʽ1�������ⲿ����ʵ��һһ��Ӧ����
	figure *i1 = &t1;
	figure *i2 = &s1;
	figure *i3 = &c1;
	i1->show_area();
	i2->show_area() ;
	i3->show_area();
	

	//���÷�ʽ2����̬��
	objShow(&t1);
	objShow(&s1);
	objShow(&c1);

	return 0;
}