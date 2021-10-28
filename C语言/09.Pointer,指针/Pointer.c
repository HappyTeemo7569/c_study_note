#include <Windows.h>
#include <stdio.h>


int main()
{
	printf("Hello World!\n");


    int userAge = 16;  
    int *ptr = 0;    
    ptr= &userAge;  
    //cout << "指针变量ptr所指向的变量的值是  " << *ptr << endl;    
    printf("%d\n", *ptr);
    //输出时的执行的：
    //找到名字是ptr的内存地址空间 
    //读取ptr中的内容 
    //“跟着”指针指向的地址（也就是ptr的值），找到所在地址的内存空间 
    //读取其中的内容（变量userAge的值）

    system("pause");
    return 0;
}

 
