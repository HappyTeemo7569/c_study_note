#include <stdio.h>

void XiEr_sort(int Numbers[],int n)
{
	int dk = 3 ;
	int i,j;
	for (dk = 3; dk>0; dk--)
	{
		//����ÿ������dk,�����������ֱ������
		for (i=0; i+dk<n; i+=dk) 
		{
			for (j=i+dk; j-dk>=0; j-=dk)
			{
				if (Numbers[j] > Numbers[j-1])
				{
					break;
				}
				else
				{
					int temp = Numbers[j];
					Numbers[j] = Numbers[j-1];
					Numbers[j-1] = temp;
				}
			}
		}
	}

}

int main()
{
	int Numbers[10] = {1,4,2,3,4,5,6,11111,2222,333};
	XiEr_sort(Numbers,10);

	int i;
	for (i=0;i<10;i++)
	{
		printf("%d ",Numbers[i]);
	}

	printf("\n");

	return 0;
}