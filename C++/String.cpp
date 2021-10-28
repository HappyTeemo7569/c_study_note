#include <string>
#include <iostream>
using namespace std;

int main()
{
	/////////////定义////////////
	string s1("hehe");

	char chs2[] = "hehe";
	string s2(chs2);
	string s32(chs2,1,3); //指定从chs2的索引1开始,最后复制3个字节
	string s33(chs2,3);   //将chs2前3个字符作为初值构造
	
	string s4(s1);
	
	string s5(10,'k');    //分配10个字符,初值都是'k'

	/////////////赋值/////////////
	s1 = "hehehehe";
	s1.assign("kdje");
	s1.assign("fkdhfkdfd",5); //重新分配指定字符串的前5的元素内容

	/////////////交换数据/////////////
	s1.swap(s2);
	s1.replace(2,3,"****");//从索引2开始3个字节的字符全替换成"****"

	////////////添加数据/////////////
	s1 += "gaga";
	s1.append("heihei");  //append()方法可以添加字符串
	s1.push_back('k');    //push_back()方法只能添加一个字符...

	s1.insert(0,"top");          //在头部插入
	s1.insert(s1.size(),"end");   //在尾部插入
	s1.insert(s1.size()/2,"mid"); //在中间插入

	////////////删除/////////////////
	s1.erase(0,1);    //从索引0到索引1,
	s1.replace(2,3,"");//即将指定范围内的字符替换成"",即变相删除了
	s1.clear();  //全删
	s1.erase(0,s1.length());  //变相全删


	//==,!=,<,<=,>,>=,compare()  比较字符串
	//size(),length()  返回字符数量
	//max_size() 返回字符的可能最大个数
	//empty()  判断字符串是否为空
	// [ ], at() 存取单一字符

	// substr() 返回某个子字符串
	string str = s1.substr(5,3);//从索引5开始3个字节

	// find 查找函数
	string pattern = "f";
	string::size_type pos;
	pos = s1.find(pattern,0);        //从索引0开始,查找符合字符串"f"的头索引
	string str2 = s1.substr(pos,pattern.size());

	// begin() end() 提供类似STL的迭代器支持
	string s = "abcdefg1111";
	for(string::iterator iter = s.begin(); iter!=s.end(); iter++)
	{
		cout<<*iter<<endl;
	}

	return 0;
}