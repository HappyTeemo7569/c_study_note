#include <stdio.h>

int QuickSort(int Numbers[],int low,int high)
{
	if (low >= high)
		return;

	int first = low;
	int last = high;
	//int mid = (low+high)/2;
	int key = Numbers[first]; //��һ����Ϊ�м�λ

	while(first < last)
	{
		while( (first<last) && (Numbers[last]>=key) )  //������м�ֵ�󣬾��Ƶ�����
		{
			--last;
		}
		Numbers[first] = Numbers[last];

		while( (first<last) && (Numbers[first]<=key) ) //������м�ֵС�����Ƶ�ǰ��
		{
			++first;
		}
		Numbers[last] = Numbers[first];
		//���
		int i;
		for (i=0;i<10;i++)
		{
			printf("%d ",Numbers[i]);
		}
		printf("\n");
	}
	Numbers[first] = key; //��һ����Ϊ�м�λ

	QuickSort(Numbers,low,first-1);
	QuickSort(Numbers,first+1,high);
}

int main()
{
	int Numbers[10] = {49,38,65,97,76,13,27,49,22,33};

	int i;
	printf("before:");
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}
	printf("\n");

	QuickSort(Numbers,0,9);

	printf("end:");
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}
	printf("\n");

	return 0;
}