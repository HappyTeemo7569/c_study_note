#include"iostream"
#include"list"
using namespace std;

int main()
{
	//建立了一个链表
	list<int> l;
	int len = l.size();
	cout<<len<<endl;
	
	for (int i=0; i<5; i++)
	{
		l.push_back(i);    //从链表尾部增加元素（尾插法）
	}
		
	//迭代器就是一个指针iterator
	list<int>::iterator current = l.begin();   
	//链表l的头部，赋给迭代器（一个指针）
	//l.end();  链表尾部
	
	while(current != l.end())   
	//l.end()不等于链表尾部，指向最后一个节点下面那个位置，要不然打不出含值的最后一个元素
	{
		cout<<*current<< " ";
		current++;
	}
	cout << endl;

	//把链表的首位置赋给迭代器指针
	current = l.begin();    // 0
	current ++;     // 1
	current ++;     // 2
	current ++;     // 3
	l.insert(current,100);   //在链表位置3插入，3的原来元素后移.

	for (list<int>::iterator p = l.begin(); p!=l.end(); p++)   //遍历
	{
		cout<<(*p) << " ";
	}
	cout << endl;

	return 0;
}