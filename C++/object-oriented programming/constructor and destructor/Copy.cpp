#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class name
{
public :
	name(char *pn) ; 
	
	name(name &obj) //����ǳ�����ķ���
	{
		cout <<" copy" << endl ;
		char *pn = obj.getPn();
		pname = (char *)malloc(strlen(pn) +1);  //������2��pname���ռ丳ֵ
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
	
	void operator=(name &obj1)      //�Զ���ĵȺŲ���
	{
		cout <<" =" << endl ;
		//ִ��mallocǰ�Ȱ�֮ǰ�Ŀռ��ͷŵ���
		if(pname!=NULL)
		{ 
			free(pname);
			pname=NULL;//����Ұָ��
			size=0;
		}
		char *pn = obj1.getPn();
		pname = (char *)malloc(strlen(pn) +1);  //����2
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
	name obj2 = obj1; //�����������캯��

	obj2 = obj1;
	//������õ��Ƕ���2�ĵȺŲ�����obj1���βΡ�
	
	cout<<obj2.getPn()<<endl;
}

int main()
{
	playmain();
	return 0;
}

/**********************
*1.������û�ж����κι��캯��ʱ�����������ṩ�޲ι��캯���Ϳ������캯����ǳ��������
*2.�����˷ǿ������캯�����޲Ρ��вΣ������ṩ�޲ι��캯����
*3.�����˿������캯�������ṩǳ������
*4.ǳ�������ǳ�Ա�����򵥸�ֵ��
*5.ֻҪд�˹��캯���ͱ����ã�ϵͳ�����ٸ�Ĭ�ϵķ�ʽ��
***********************/