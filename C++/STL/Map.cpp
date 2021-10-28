/**********************
1   头文件
#include  <map>

2   定义
map<string,int> my_Map;
或者是typedef  map<string,int>  MY_MAP;

3   插入数据
(1)  my_Map["a"]   =   1;
(2)  my_Map.insert(map<string,   int>::value_type("b",2));
(3)  my_Map.insert(pair<string,int>("c",3));
(4)  my_Map.insert(make_pair<string,int>("d",4));

4   查找数据和修改数据
(1) int i  = my_Map["a"];
my_Map["a"]  =  i;
(2) MY_MAP::iterator  my_Itr;
my_Itr.find("b");
int  j  =  my_Itr->second;
my_Itr->second  =  j;
不过注意，键本身是不能被修改的，除非删除。

5   删除数据
(1)  my_Map.erase(my_Itr);
(2)  my_Map.erase("c");
还是注意，第一种情况在迭代期间是不能被删除的，道理和foreach时不能删除元素一样。

6   迭代数据
for(my_Itr=my_Map.begin();  my_Itr!=my_Map.end();  ++my_Itr)   {}

7   其它方法
my_Map.size()        返回元素数目
my_Map.empty()       判断是否为空
my_Map.clear()       清空所有元素
可以直接进行赋值和比较：=,   >,   >=,   <,   <=,   !=   等等
***********************/