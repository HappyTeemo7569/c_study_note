#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class name
{
public :
	name(char *pn) ; 
	
	name(name &obj) //避免浅拷贝的方法
	{
		cout <<" copy" << endl ;
		char *pn = obj.getPn();
		pname = (char *)malloc(strlen(pn) +1);  //给对象2的pname开空间赋值
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		size = strlen(pn) ;
	}
	~ name() ;
	
protected :
	char *pname ;      
	int size ;
public:
	char * getPn()
	{
		return pname  ;
	}    
	
	void operator=(name &obj1)      //自定义的等号操作
	{
		cout <<" =" << endl ;
		//执行malloc前先把之前的空间释放掉。
		if(pname!=NULL)
		{ 
			free(pname);
			pname=NULL;//避免野指针
			size=0;
		}
		char *pn = obj1.getPn();
		pname = (char *)malloc(strlen(pn) +1);  //对象2
		if (pname!=NULL) strcpy(pname,pn) ;
		//pname = new char[strlen(pn)+1] ;
		//if (pname!=0) strcpy(pname,pn) ;
		pname[0] = 'm';  
		size = strlen(pn) ;
	}
} ;


name::name(char *pn)                       
{
	cout <<" GouZao " << pn << endl ;
	pname = (char *)malloc(strlen(pn) +1);
	if (pname!=0) strcpy(pname,pn) ;
	//pname = new char[strlen(pn)+1] ;
	//if (pname!=0) strcpy(pname,pn) ;
	size = strlen(pn) ;
}

name :: ~ name()
{
	cout << " XIGou " << pname << endl ;
	pname[0] = '\0' ;
	//delete  []pname ;
	free(pname);
	size = 0 ;
}

void playmain()
{
	name obj1("name1");
	name obj2 = obj1; //调动拷贝构造函数

	obj2 = obj1;
	//这里调用的是对象2的等号操作。obj1是形参。
	
	cout<<obj2.getPn()<<endl;
}

int main()
{
	playmain();
	return 0;
}

/**********************
*1.当类中没有定义任何构造函数时，编译器会提供无参构造函数和拷贝构造函数（浅拷贝）。
*2.定义了非拷贝构造函数（无参、有参），则不提供无参构造函数。
*3.定义了拷贝构造函数，则不提供浅拷贝。
*4.浅拷贝则是成员变量简单赋值。
*5.只要写了构造函数就必须用，系统不会再给默认的方式。
***********************/