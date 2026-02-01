// file_eof.c 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ch;
    FILE * fp;
    char fname[50];
    printf("name of file:");
    scanf("%s",fname);
    fp=fopen(fname, "r");
    if (fp == NULL)
    {
        printf("Failed　to　open　file.　Bye\n");
        exit(1);
    }
    //getc(fp)从打开的文件中获取一个字符
    while((ch=getc(fp))!=EOF)
        putchar(ch);

    fclose(fp);
    return 0;
}