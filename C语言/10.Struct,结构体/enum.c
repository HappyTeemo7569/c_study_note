#include <stdio.h>

enum Days
{
	saturday,                    // saturday = 0 Ĭ��ֵ
	sunday = 0,                  // sunday = 0
	monday,                      // monday = 1
	tuesday,                     // tuesday = 2
	wednesday,                   // ��������
	thursday,
	friday
} today;  // ����Days���͵ı���today

int main()
{
	//int  tuesday;           // �����ظ�������߸þ���Ч����ӡ���ʱ��δ����Ĵ���
	//printf("%d\n", tuesday);

	///////////////////////////////

	enum Days yesterday;      // ��C��C++�ж��Ϸ�
	//Days tomorrow;          // ֻ��C++�кϷ�
	yesterday = monday;       // Ϊyesterday������ֵΪMonday
	//yesterday = 0;          // ������Ϊû�н�������ת��
	//yesterday = (Days)0;    // ��Ч�����ǽ����ȷ������ȷ��Ϊsaturday����sunday��

	/////////////////////////

	//int i = tuesday;          // ��Ч��i = 2
	//printf("%d\n",i);

	return 0;
}