#include <stdio.h>
#define SPACE ' '
#include <Windows.h>
#include <ctype.h>

//输入字符打印后一个字母（按ASC表）
int main() 
{
    char cStr;
    int nNumOfStr = 0;

    cStr = getchar();
    while (cStr != '\n') //while ((cStr = getchar()) != '\n')
    {
        // if (cStr == SPACE)//如果是空格
        //     putchar(cStr);
        // else
        //     putchar(cStr + 1);
             
        if (isalpha(cStr)) //如果是字母
        {
            putchar(cStr+1);
            nNumOfStr++;
        }
        else
        {
            putchar(cStr);
        }

        cStr = getchar();
    }
    putchar(cStr);
    printf("There are %d non-quote characters.\n", nNumOfStr);

    system("pause");
    return 0;
}