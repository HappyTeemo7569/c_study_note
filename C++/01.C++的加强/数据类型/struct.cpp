/*
struct���͵ļ�ǿ��
C���Ե�struct������һ������ļ��ϣ�C������������Ϊ����һ���µ����� ��
C++�е�struct��һ�������͵Ķ������� ��
*/

//studet��һ���µ����ͣ��ࣩ
//���ǰ����Ժͷ��������˳���
struct Student
{
	char name[100];
	int age;
	int getAge() {return age;}
};

int main(int argc, char *argv[])
{
	//c++����дstruct
	Student s1 = {"wang", 1};
	Student s2 = {"wang2", 2};   
	return 0;
}
