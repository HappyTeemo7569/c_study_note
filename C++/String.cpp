#include <string>
#include <iostream>
using namespace std;

int main()
{
	/////////////����////////////
	string s1("hehe");

	char chs2[] = "hehe";
	string s2(chs2);
	string s32(chs2,1,3); //ָ����chs2������1��ʼ,�����3���ֽ�
	string s33(chs2,3);   //��chs2ǰ3���ַ���Ϊ��ֵ����
	
	string s4(s1);
	
	string s5(10,'k');    //����10���ַ�,��ֵ����'k'

	/////////////��ֵ/////////////
	s1 = "hehehehe";
	s1.assign("kdje");
	s1.assign("fkdhfkdfd",5); //���·���ָ���ַ�����ǰ5��Ԫ������

	/////////////��������/////////////
	s1.swap(s2);
	s1.replace(2,3,"****");//������2��ʼ3���ֽڵ��ַ�ȫ�滻��"****"

	////////////�������/////////////
	s1 += "gaga";
	s1.append("heihei");  //append()������������ַ���
	s1.push_back('k');    //push_back()����ֻ�����һ���ַ�...

	s1.insert(0,"top");          //��ͷ������
	s1.insert(s1.size(),"end");   //��β������
	s1.insert(s1.size()/2,"mid"); //���м����

	////////////ɾ��/////////////////
	s1.erase(0,1);    //������0������1,
	s1.replace(2,3,"");//����ָ����Χ�ڵ��ַ��滻��"",������ɾ����
	s1.clear();  //ȫɾ
	s1.erase(0,s1.length());  //����ȫɾ


	//==,!=,<,<=,>,>=,compare()  �Ƚ��ַ���
	//size(),length()  �����ַ�����
	//max_size() �����ַ��Ŀ���������
	//empty()  �ж��ַ����Ƿ�Ϊ��
	// [ ], at() ��ȡ��һ�ַ�

	// substr() ����ĳ�����ַ���
	string str = s1.substr(5,3);//������5��ʼ3���ֽ�

	// find ���Һ���
	string pattern = "f";
	string::size_type pos;
	pos = s1.find(pattern,0);        //������0��ʼ,���ҷ����ַ���"f"��ͷ����
	string str2 = s1.substr(pos,pattern.size());

	// begin() end() �ṩ����STL�ĵ�����֧��
	string s = "abcdefg1111";
	for(string::iterator iter = s.begin(); iter!=s.end(); iter++)
	{
		cout<<*iter<<endl;
	}

	return 0;
}