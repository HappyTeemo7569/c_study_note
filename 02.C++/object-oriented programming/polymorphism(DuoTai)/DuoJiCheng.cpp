#include"iostream"
using namespace std;

class base1
{
public:
	int i;
	void printI()
	{
		cout<<i<<endl;
	}
protected:
private:

};

class base2
{
public:
	int j;
	void printJ()
	{
		cout<<j<<endl;
	}
protected:
private:
};

class  C : public base1, public base2   //¶à¼Ì³Ð
{
public:
protected:
private:
};

int main()
{

	C c1;
	c1.i = 10;  //public base1,
	c1.j = 20;  //public base2   
	c1.printI();
	c1.printJ();

	return 0;
}