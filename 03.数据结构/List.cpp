#include <iostream>

typedef int T;

class List{
	struct Node
	{
		T* data;
		Node* next;
		Node(const T& d):data(),next(){}
	};
};

int main
{
	return 0;
}