#include <stdio.h>


void BubbleSort(int Numbers[],int Nums)
{
	int i,j;

	for (i=0;i<Nums-1;i++)  //-1,���һ���Զ����
	{
		for (j=Nums-1;j>i;j--) //�Ӻ���ǰ�Ƚ�
		{
			if (Numbers[j] < Numbers[j-1])
			{
				int temp = Numbers[j];
				Numbers[j] = Numbers[j-1];
				Numbers[j-1] = temp;
			}
		}
	}
}

int main()
{
	int Numbers[10] = {1,4,2,3,4,5,6,11111,2222,333};
	BubbleSort(Numbers,10);

	int i;
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}

	printf("\n");

	return 0;
}