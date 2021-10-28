#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	//��ʽ���
	int n=510;
	cout<<"ten: "<<n<<endl;
	cout<<"OX: "<<hex<<n<<endl;
	cout<<"eight: "<<oct<<n<<endl;
	cout<<"ten: "<<dec<<n<<endl;
	cout<<"OX_little:"<<hex<<n<<endl;
	cout<<"OX_big: "<<setiosflags(ios::uppercase)<<hex<<n<<endl;
	cout<<"reset: "<<resetiosflags(ios::uppercase)<<hex<<n<<endl;


	//�������
	int m=1234;
	cout<<setw(3)<<m<<endl;
	cout<<setw(5)<<m<<endl;
	//��������ַ�
	cout<<setfill('*')<<setw(5)<<m<<endl;
	//���ö��䷽ʽ
	cout<<setiosflags(ios::left)<<setw(10)<<m<<endl;
	cout<<setiosflags(ios::right)<<setw(10)<<m<<endl;

	//��ʾС���㡢β������
	double d1=10/5,d2=22.0/7;
	cout<<d1<<endl;
	cout<<setiosflags(ios::showpoint)<<d1<<endl; //ǿ����ʾС�����β
	cout<<setiosflags(ios::showpos)<<d2<<endl;   //ǿ����ʾ����
	cout<<resetiosflags(ios::showpos);           //����

	double dd=123.4567;
	cout<<setiosflags(ios::scientific)<<dd<<endl;  //��ѧ������
	cout<<setiosflags(ios::fixed)<<dd<<endl;       //������
	//���þ���
	cout<<setprecision(2)<<dd<<endl;
	cout<<setprecision(3)<<dd<<endl;

	//put(�ַ���)  ���ܣ������һ���ַ�
	/**********************
	*get( )����
	*a)����������get()����   cin.get()  ����һ���ַ�(�����س���tab���ո�ȿհ��ַ�)
		char ch;
		while( (ch=cin.get()) !=EOF)   //EOFΪ�ļ�����������ctrl+z ����
		cout.put(ch);
	*b)��һ��������get()���� cin.get(ch)  ���ܣ�����һ���ַ�,�ɹ�������,��ʧ��(�����ļ�������)���ؼ�
		char ch;
		while(cin.get(ch))
		{  cout.put(ch);  }
	*c)������������get()����  
	*cin.get(�ַ����飬�ַ�����n,��ֹ�ַ�)�� cin.get(�ַ�ָ�룬�ַ�����n,��ֹ�ַ�)
		char str[80];
		cout<<"������һ���ַ�����";
		cin.get(str,80,'\n');
		cout<<str<<endl;
	*
	***********************/
	//getline( )����  cin.getline(�ַ�������ַ�ָ�룬�ַ�����n[,��ֹ�ַ�])  Ĭ��'\n'
	//eof()�������ǡ�end of file������д����ʾ���ļ���������

	return 0;
}