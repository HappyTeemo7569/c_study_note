#include <iostream>

typedef int T;

class Vector{
	T* data;
	int sz;
	int capacity;
	void expand(){
		T* Tmp = new T[capacity*2];
		for (int i=0;i<sz;i++)
		{
			Tmp[i] = data[i];
		}
		delete[] data;
		data = Tmp;
	}

public:
	explicit
};

int main()
{

	return 0;
}