#include <Windows.h>
#include <stdio.h>


int main()
{
	double d = 1.5e30;
	printf("���ͣ�%i\n�����ͣ�%f\n���ţ�%c\n",123,45.6,'$');
	printf("ʮ������%x, �˽���%o\n", 763, 763);
	printf("float/doubleȥ����β���0:%g\n",45.6);
	printf("**************\n\n");
	/////////////ָ��//////////////////
	printf("d as double:%g\n", d);
	printf("d as integer:%d\n", d);
	printf("d as e:%e\n",d);

	//////////////����ת��/////////////////
	printf("**************\n\n");
	printf("%d\n", (int)d);
	printf("\n****************************************\n\n");

	///////////////scanf//////////////////
	int age;
	float assets;
	char pet[30];
	printf("Enter your age, assets, and favorite pet.\n");
	scanf("%d %f", &age, &assets);
	// ����Ҫʹ��&
	scanf("%s", pet);
	// �ַ����鲻ʹ��&
	printf("%d $%.2f %s\n", age, assets, pet);
	printf("\n****************************************\n\n");

	////////////////printf////////////////
	printf("%d\n",7);
	printf("%4d\n",7);//����ռ�ĸ�λ��
	printf("%-4d\n",7);//-��ʾ���������
	printf("%04d\n",7);//û��ռ����λ����0
	printf("%d,%c\n",'a','a');//�ַ���������%c���ַ���ASCLL���洢��%c��ʱ���������ȥ���%d��ֱ��������֡�
	printf("%f\n",1.5f);//��������������%f
	printf("%5.2\n",1.5f);//һ��ռ���λ�ã�С����ռ����λ
	printf("%lf\n",1.5);//˫���ȸ�������%lf��ʾ



	system("pause");
	return 0;
}


