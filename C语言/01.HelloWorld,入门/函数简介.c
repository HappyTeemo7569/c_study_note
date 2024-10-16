#include <stdio.h>

void butler(void); //函数原型（prototype） 

int main(void)
{
	printf("I will summon the butler function.\n");
	butler(); //函数调用（function call）
	printf("Yes. Bring me some tea and writeable CD-ROMS.\n");

	return 0;
}

//函数定义（function definiition）
void butler(void)       
{
	printf("You rang, sir?\n");
}

//函数总共出现了三次：声明原型，定义，调用。
//何时调用butler取决于它在主函数的位置，而不是定义的位置。
//如果定义在调用的前面，可以省略声明。但是建议使用上文的顺序，因为方便查询和使用。
//无论main放在哪里，都是从main开始执行。
