#include <stdio.h>


void SelectSort(int Numbers[],int Nums)
{
	int i,j;

	for (i=0;i<Nums-1;i++)  //-1�ܹؼ�
	{
		int minIndex = i;  //�ȼٶ���С�����������š�
		for (j=i+1;j<Nums;j++)
		{
			if (Numbers[minIndex] > Numbers[j])
			{
				minIndex = j;  //����б�����С�����޸ı�ǣ����Լ���Ϊ�����ϵĺ�����С�Ļ�����
			}
		}

		if (minIndex != i)  //�����С�Ĳ������ϵ������򻥻�
		{
			int temp = Numbers[minIndex];
			Numbers[minIndex] = Numbers[i];
			Numbers[i] = temp;
		}
	}
}

int main()
{
	int Numbers[10] = {1,4,2,3,4,5,6,11111,2222,333};
	SelectSort(Numbers,10);

	int i;
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}

	printf("\n");

	return 0;
}