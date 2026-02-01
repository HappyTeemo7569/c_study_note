#include <stdio.h>


void SelectSort(int Numbers[],int Nums)
{
	int i,j;

	for (i=0;i<Nums-1;i++)  //-1很关键
	{
		int minIndex = i;  //先假定最小的是手上这张。
		for (j=i+1;j<Nums;j++)
		{
			if (Numbers[minIndex] > Numbers[j])
			{
				minIndex = j;  //如果有比手上小的则修改标记（可以假想为把手上的和那张小的互换）
			}
		}

		if (minIndex != i)  //如果最小的不是手上的这张则互换
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