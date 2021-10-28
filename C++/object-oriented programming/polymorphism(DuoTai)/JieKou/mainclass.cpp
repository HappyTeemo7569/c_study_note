#include"iostream"
#include "socketimp1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
C++��û�нӿڵĸ���
C++�п���ʹ�ô��麯��ʵ�ֽӿ�
�ӿ�����ֻ�к���ԭ�Ͷ��壬û���κ����ݵĶ��塣

*/

class Interface1
{
public:
	virtual void print() = 0;
	virtual int add(int i, int j) = 0;
};

class Interface2
{
public:
	virtual int add(int i, int j) = 0;
	virtual int minus(int i, int j) = 0;
};
class parent
{
public:
	int i;
};

class Child : public parent, public Interface1, public Interface2
{
public:
	void print()
	{
		cout << "Child::print" << endl;
	}

	int add(int i, int j)
	{
		return i + j;
	}

	int minus(int i, int j)
	{
		return i - j;
	}
};

class MainOp  //���沢û��ʵ�ֳ�����ķ�����ֱ�ӿ�����
{
public:
	MainOp(SocketIF *sIf)
	{
		this->sIF =sIf; //�Ѷ���Ž�ȥ��
	}
	MainOp()
	{
		;
	}
public:
	int Op1(unsigned char*in,int inlen,unsigned char *out,int *outlen)
	{
		int ret = 0;
		ret = this->sIF->cltSocketInit();
		ret = this->sIF->cltSocketSend(in,inlen);
		ret = this->sIF->cltSocketRev(out,outlen);
		ret = this->sIF->cltSocketDestory();
		return ret;
	}
	int Op2(SocketIF *sIF,unsigned char *in,int inlen,unsigned char *out,int *outlen)//�ò�������
	{
		int ret = 0;
		ret = sIF->cltSocketInit();
		ret = sIF->cltSocketSend(in,inlen);
		ret = sIF->cltSocketRev(out,outlen);
		ret = sIF->cltSocketDestory();
		return ret;
	}
protected:
private:
	SocketIF *sIF;  //����ӿ���
};

int main()
{
	Child c;

	c.print();

	cout << c.add(3, 5) << endl;
	cout << c.minus(4, 6) << endl;

	Interface1 * i1 = &c;
	Interface2 * i2 = &c;

	cout << i1->add(7, 8) << endl;
	cout << i2->add(7, 8) << endl;

	/////////////////////////////////////
	unsigned char buf[1024];
	strcpy((char*)buf,"ddddddsssssss");
	int buflen = 10;  //ֻ�ܷ�10λ

	unsigned char out[1024] = {0};
	int outlen = 10;

	//////////////////ע��///////////////////
	SocketIF *sIF = new SocketImp1();
	MainOp mop(sIF);  
	mop.Op1(buf,buflen,out,&outlen);
	printf("out:%s",out);
	delete sIF;

	////////////////��ע��////////////////////
	SocketIF *sIF2 = new SocketImp1();
	MainOp mop2;
	mop2.Op2(sIF2,buf,buflen,out,&outlen);
	printf("out:%s",out);
	delete sIF2;
	
	return 0;
}