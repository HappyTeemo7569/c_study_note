// checking.c -- 输入验证
#include <stdio.h>
#include <stdbool.h>

// 验证输入是一个整数
long get_long(void);
// 验证范围的上下限是否有效
bool bad_limits(long begin,long end,long low,long high);
// 计算a～b之间的整数平方和
double sum_squares(long a,long b);

int main(void)
{
    const long MIN = -10000000L;// 范围的下限
    const long MAX = +10000000L;// 范围的上限
    long start;// 用户指定的范围最小值
    long stop;// 用户指定的范围最大值
    double answer;
    printf("在范围：-10000000到+10000000内,计算两个整数之间的平方和。\n输入一个最小值：(均为0表示结束程序) ");
    start = get_long();
    printf("输入一个最大值：(均为0表示结束程序) ");
    stop = get_long();
    while(start != 0 || stop != 0)
    {
        if(bad_limits(start,stop,MIN,MAX))
            printf("超出范围，请重新输入：\n");
        else
        {
            answer = sum_squares(start,stop);
            printf("从%ld到%ld的平方和是：%g\n",start,stop,answer);
        }
        printf("最小值：(均为0表示结束程序)");
        start = get_long();

        printf("最大值：(均为0表示结束程序)");
        stop = get_long();
    }
    printf("Done.\n");
    return 0;
}
long get_long(void)
{
    long input;
    char ch;
    while(scanf("%ld",&input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch);       //处理错误输入
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

double sum_squares(long a, long b)
{
    double total = 0;
    long i;
    for (i = a; i <= b; i++)
        total += (double) i * (double) i;
    return total;
}

bool bad_limits(long begin, long end,long low, long high)
{
    bool not_good = false;
    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }
    return not_good;
}
