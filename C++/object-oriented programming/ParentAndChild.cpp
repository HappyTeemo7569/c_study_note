/**********************
�̳У�inberitance��:��һ���Ѿ����ڵ���Ļ����ϴ���һ������
���ࣨfather class������ࣨbase class��
���ࣨchild class�����������ࣨderived class��
����̳и��࣬��������������
���������������丸�������г�Ա�����������캯��������������,��������Ҳ���������³�Ա��

3�ּ̳з�ʽ��
������˽�г�Ա�����಻�ɷ��ʣ����ɼ���
public:���м̳У������еĹ��кͱ�����Ա�������л��Ǳ��ֲ��䣬�����䣩
protected:�����̳У������еĹ��кͱ�����Ա�������ж���Ϊ�����ģ�����Ϊ������
private:˽�м̳У������еĹ��кͱ�����Ա�������ж���Ϊ˽�еģ���Ϊ˽�У�
���м̳���ã�����༶�̳У�

���๹��---���๹��----��������-----�����������Ȱ������ٰ����ӣ��Ȳ������ٲ���̣�

ͬ�����ǣ�����д�� �������غ͸���

����͸�������ת�����⣻
1������������ת��Ϊ������󣬴�ʱ�������������Խ����ضϣ���Ϊ���Ǵ���ڸ��ֽڴ�����ʵ�õ��ľ��ǴӸ���̳еĲ��֡��������ת��Ϊ����û�����壬��Ϊ���������ռ�洢�ռ������ȸ�������
2���������û�ָ��ָ����������ǿ��Եģ���ʱ����ָ�����ʵ���������Ӹ���̳еĲ��֣�����֮û�����塣

һ���̳�
�༶�̳У�ֱ�����࣬������ֱࣻ�Ӹ��࣬��Ӹ���
���̳У�single inheritance��:�����ֱ�Ӹ���ֻ��һ����
���ؼ̳�(multiple inheritance)�������ֱ�Ӹ����ж����
���ؼ̳е����ӣ����Ӽ̳������¿���ص�
���γ����μ̳У���̳п��Ա��� virtual
***********************/

#include<cstdlib>
#include<iostream>

using namespace std;

class A
{
private:
	int a;
	friend void SetAA(A *a,int m_b);//ȫ�ֺ�������Ԫ
protected:
	int b;
public:
	int c;

	A()
	{
		a = 0;
		b = 0;
		c = 0;
	}

	void set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void print()
	{
		cout<<"a"<<a<<"b"<<b<<endl;
	}
};

class B : public A
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err   
		cout<<"Bb = "<< b;  //�����ڲ� ��A��public ��A����protected
		cout<<"Bc = "<< c << endl; //�����ڲ� ��A��public ��A����public
	}
};

class C : protected A
{
public:
	void print()
	{
		//cout<<"a = "<<a; //err   �����ڲ� ��A��protected ��A����private
		cout<<"Cb = "<<b;      //   �����ڲ� ��A��protected ��A����protected
		cout<<"Cc = "<<c <<endl;   //   �����ڲ� ��A��protected ��A����protected
	}
};

class D : private A
{
public:
	void print()
	{
		//cout<<"Da = "<<a; //err    �����ڲ� ��A��private ��A����private
		cout<<"Db = "<<b;  //ok  �����ڲ� ��A��private ��A����private ������������˽��=�����ڲ�����ʹ��
		cout<<"Dc = "<<c<<endl;  //ok �����ڲ� ��A��private ��A����private ������������˽��=�����ڲ�����ʹ��
	}
};

void SetAA(A *a,int m_b)
{
	cout << "serAA" << a->a << endl;;
	return;
}


int main()
{
	A aa;  //����     //��Ա��a˽��b����c����
	B bb;  //���м̳� //��Ա��b����c����
	C cc;  //�����̳� //��Ա��b����c����
	D dd;  //˽�м̳� //��Ա��b˽��c˽��
	

	aa.c = 100; //ok  
	bb.c = 100; //ok   �����ⲿ  ��A��public ��A����public
	//cc.c = 100; //err  �����ⲿ  ��A��protected ��A����public  -��תΪprotected  �����ⲿ�����Ե���
	//dd.c = 100; //err  �����ⲿ  ��A��public ��A����public   -��תΪprivate  

	aa.set(1, 2, 3);
	bb.set(10, 20, 30); // ok    bb��A��set����  �����ⲿ  ��A��public ��A����public
	//cc.set(40, 50, 60); //err   �����ⲿ  ��A��protected ��A����public  -��תΪprotected  �����ⲿ�����Ե��� ������ڲ�ʹ��
	//dd.set(70, 80, 90); //err   �����ⲿ  ��A��public ��A����public   -��תΪprivate     �����ⲿ�����Ե��� ������ڲ�ʹ��

	bb.print();  //ok�����Լ���public
	cc.print();	 //ok�����Լ���public
	dd.print();  //ok�����Լ���public
		
	//������һ������ĸ��࣬������Ե�����=>��ֵ������ԭ��

	SetAA(&aa, 1);
	SetAA(&bb, 1);  // �Ѻ��ӵ�ֵ�������׵��Ѻ�����������

	//////////////////////////
	A *pA = NULL;  //�����ָ��ָ������
	pA = &bb;
	pA->print();

	A &myb = bb;  //���������ָ������
	myb.print();


	return 0;
}