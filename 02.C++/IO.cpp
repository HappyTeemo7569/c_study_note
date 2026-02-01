#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	//格式输出
	int n=510;
	cout<<"ten: "<<n<<endl;
	cout<<"OX: "<<hex<<n<<endl;
	cout<<"eight: "<<oct<<n<<endl;
	cout<<"ten: "<<dec<<n<<endl;
	cout<<"OX_little:"<<hex<<n<<endl;
	cout<<"OX_big: "<<setiosflags(ios::uppercase)<<hex<<n<<endl;
	cout<<"reset: "<<resetiosflags(ios::uppercase)<<hex<<n<<endl;


	//设置域宽
	int m=1234;
	cout<<setw(3)<<m<<endl;
	cout<<setw(5)<<m<<endl;
	//设置填充字符
	cout<<setfill('*')<<setw(5)<<m<<endl;
	//设置对其方式
	cout<<setiosflags(ios::left)<<setw(10)<<m<<endl;
	cout<<setiosflags(ios::right)<<setw(10)<<m<<endl;

	//显示小数点、尾和数符
	double d1=10/5,d2=22.0/7;
	cout<<d1<<endl;
	cout<<setiosflags(ios::showpoint)<<d1<<endl; //强制显示小数点和尾
	cout<<setiosflags(ios::showpos)<<d2<<endl;   //强制显示符号
	cout<<resetiosflags(ios::showpos);           //重置

	double dd=123.4567;
	cout<<setiosflags(ios::scientific)<<dd<<endl;  //科学计数法
	cout<<setiosflags(ios::fixed)<<dd<<endl;       //定点数
	//设置精度
	cout<<setprecision(2)<<dd<<endl;
	cout<<setprecision(3)<<dd<<endl;

	//put(字符型)  功能：输出单一个字符
	/**********************
	*get( )函数
	*a)不带参数的get()函数   cin.get()  读入一个字符(包括回车、tab、空格等空白字符)
		char ch;
		while( (ch=cin.get()) !=EOF)   //EOF为文件结束符，按ctrl+z 输入
		cout.put(ch);
	*b)带一个参数的get()函数 cin.get(ch)  功能：读入一个字符,成功返回真,如失败(遇到文件结束符)返回假
		char ch;
		while(cin.get(ch))
		{  cout.put(ch);  }
	*c)带三个参数的get()函数  
	*cin.get(字符数组，字符个数n,终止字符)或 cin.get(字符指针，字符个数n,终止字符)
		char str[80];
		cout<<"请输入一个字符串：";
		cin.get(str,80,'\n');
		cout<<str<<endl;
	*
	***********************/
	//getline( )函数  cin.getline(字符数组或字符指针，字符个数n[,终止字符])  默认'\n'
	//eof()函数：是”end of file”的缩写，表示“文件结束”。

	return 0;
}