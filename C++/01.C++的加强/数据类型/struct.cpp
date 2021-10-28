/*
struct类型的加强：
C语言的struct定义了一组变量的集合，C编译器并不认为这是一种新的类型 。
C++中的struct是一个新类型的定义声明 。
*/

//studet是一个新的类型（类）
//类是把属性和方法进行了抽象
struct Student
{
	char name[100];
	int age;
	int getAge() {return age;}
};

int main(int argc, char *argv[])
{
	//c++不用写struct
	Student s1 = {"wang", 1};
	Student s2 = {"wang2", 2};   
	return 0;
}
