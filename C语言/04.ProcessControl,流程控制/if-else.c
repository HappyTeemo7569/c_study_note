#include <stdio.h>
#define SPACE ' '
#include <Windows.h>
#include <ctype.h>

//�����ַ���ӡ��һ����ĸ����ASC��
int main() 
{
    char cStr;
    int nNumOfStr = 0;

    cStr = getchar();
    while (cStr != '\n') //while ((cStr = getchar()) != '\n')
    {
        // if (cStr == SPACE)//����ǿո�
        //     putchar(cStr);
        // else
        //     putchar(cStr + 1);
             
        if (isalpha(cStr)) //�������ĸ
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