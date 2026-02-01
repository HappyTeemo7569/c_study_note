#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "dev_ctrl.h"

/*
 * 函数功能：控制LED亮灭状态
 * 参数描述：
 * state [in] LED状态，零表示灭，非零表示亮
 * 返回值：成功返回1，否则返回0，并且向stderr打印错误信息
 *
*/

int led_ctrl(int state)
{
	int fd=open("/dev/mem",O_RDWR);

	if(fd==-1)
	{
		perror("open /dev/mem fail");
		return 0;
	}

	void* base=mmap(NULL,0x810,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0x7F008000);

	if(base==MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		return 0;
	}

	unsigned int *GPKCON0=(unsigned int*)((char*)base+0x800);
	unsigned int *GPKDAT=(unsigned int*)((char*)base+0x808);

	*GPKCON0=(*GPKCON0 & (~(0xF<<16))) | (0x1<<16);

	if(state!=0)
	{
		//LED1亮
		*GPKDAT=(*GPKDAT) & (~(1<<4));
	}
	else
	{
		//LED1灭
		*GPKDAT=(*GPKDAT) | (1<<4);
	}

	munmap(base,0x810);	

	close(fd);

	return 1;
}


