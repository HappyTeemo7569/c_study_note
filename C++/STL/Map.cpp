/**********************
1   ͷ�ļ�
#include  <map>

2   ����
map<string,int> my_Map;
������typedef  map<string,int>  MY_MAP;

3   ��������
(1)  my_Map["a"]   =   1;
(2)  my_Map.insert(map<string,   int>::value_type("b",2));
(3)  my_Map.insert(pair<string,int>("c",3));
(4)  my_Map.insert(make_pair<string,int>("d",4));

4   �������ݺ��޸�����
(1) int i  = my_Map["a"];
my_Map["a"]  =  i;
(2) MY_MAP::iterator  my_Itr;
my_Itr.find("b");
int  j  =  my_Itr->second;
my_Itr->second  =  j;
����ע�⣬�������ǲ��ܱ��޸ĵģ�����ɾ����

5   ɾ������
(1)  my_Map.erase(my_Itr);
(2)  my_Map.erase("c");
����ע�⣬��һ������ڵ����ڼ��ǲ��ܱ�ɾ���ģ������foreachʱ����ɾ��Ԫ��һ����

6   ��������
for(my_Itr=my_Map.begin();  my_Itr!=my_Map.end();  ++my_Itr)   {}

7   ��������
my_Map.size()        ����Ԫ����Ŀ
my_Map.empty()       �ж��Ƿ�Ϊ��
my_Map.clear()       �������Ԫ��
����ֱ�ӽ��и�ֵ�ͱȽϣ�=,   >,   >=,   <,   <=,   !=   �ȵ�
***********************/