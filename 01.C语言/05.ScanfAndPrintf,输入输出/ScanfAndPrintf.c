#include <Windows.h>
#include <stdio.h>


int main()
{
	double d = 1.5e30;
	printf("整型：%i\n浮点型：%f\n符号：%c\n",123,45.6,'$');
	printf("十六进制%x, 八进制%o\n", 763, 763);
	printf("float/double去掉了尾随的0:%g\n",45.6);
	printf("**************\n\n");
	/////////////指数//////////////////
	printf("d as double:%g\n", d);
	printf("d as integer:%d\n", d);
	printf("d as e:%e\n",d);

	//////////////类型转换/////////////////
	printf("**************\n\n");
	printf("%d\n", (int)d);
	printf("\n****************************************\n\n");

	///////////////scanf//////////////////
	int age;
	float assets;
	char pet[30];
	printf("Enter your age, assets, and favorite pet.\n");
	scanf("%d %f", &age, &assets);
	// 这里要使用&
	scanf("%s", pet);
	// 字符数组不使用&
	printf("%d $%.2f %s\n", age, assets, pet);
	printf("\n****************************************\n\n");

	////////////////printf////////////////
	printf("%d\n",7);
	printf("%4d\n",7);//数字占四个位置
	printf("%-4d\n",7);//-表示数字左对齐
	printf("%04d\n",7);//没有占满的位置用0
	printf("%d,%c\n",'a','a');//字符类型数据%c，字符用ASCLL码表存储，%c的时候编译器会去查表。%d则直接输出数字。
	printf("%f\n",1.5f);//浮点类型数据用%f
	printf("%5.2\n",1.5f);//一共占五个位置，小数点占后两位
	printf("%lf\n",1.5);//双精度浮点数用%lf表示



	system("pause");
	return 0;
}


