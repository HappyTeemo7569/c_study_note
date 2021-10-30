#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/ioctl.h>

// ��������
void ds18b20_delay(int i);

int main()
{
    int fd, i;
    unsigned char result[2];           // ��ds18b20�����Ľ����result[0]��ŵͰ�λ
    unsigned char integer_value = 0;
    float temperature, decimal_value;  // �¶���ֵ,decimal_valueΪС�����ֵ�ֵ
    fd = open("/dev/ds18b20", 0);
    if (fd < 0)
    {
        perror("open device failed\n");
	exit(1);
    }
    while (1)
    {
        i++;
        read(fd, &result, sizeof(result));
        integer_value = ((result[0] & 0xf0) >> 4) | ((result[1] & 0x07) << 4);
        // ��ȷ��0.25��
        decimal_value = 0.5 * ((result[0] & 0x0f) >> 3) + 0.25 * ((result[0] & 0x07) >> 2);
        temperature = (float)integer_value + decimal_value;
	printf("The temperature is %6.2f\n",temperature);
	if (i % 20 == 0)
	    printf("\n");
	ds18b20_delay(50);
    }
}

/* ��������: ds18b20_delay() */

void ds18b20_delay(int i)
{
    int j, k;
    for (j = 0; j < i; j++)
        for(k = 0; k < 50000; k++);
}

