#include <stdio.h>

void butler(void); //����ԭ�ͣ�prototype�� 

int main(void)
{
	printf("I will summon the butler function.\n");
	butler(); //�������ã�function call��
	printf("Yes. Bring me some tea and writeable CD-ROMS.\n");

	return 0;
}

//�������壨function definiition��
void butler(void)       
{
	printf("You rang, sir?\n");
}

//�����ܹ����������Σ�����ԭ�ͣ����壬���á�
//��ʱ����butlerȡ����������������λ�ã������Ƕ����λ�á�
//��������ڵ��õ�ǰ�棬����ʡ�����������ǽ���ʹ�����ĵ�˳����Ϊ�����ѯ��ʹ�á�
//����main����������Ǵ�main��ʼִ�С�
