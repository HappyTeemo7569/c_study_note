//GPIO：General Purpose Input/Output Port，通用I/O端口
//S3C6410微处理器芯片具有188个GPIO端口，划分为17组，即17个GPIO端口

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main()
{
     //打开/dev/men文件，/dev/men设备文件代表整个物理内存，即它是物理内存设备的抽象，访问它就是访问物理内存
	int fd=open("/dev/mem",O_RDWR);
	if(fd==-1)
	{
	perror("open /dev/mem fail");
	exit(1);
 	}

	//内存映射文件，将文件映射到内存中
	//#include <sys/mman.h>
	//void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
	//映射的起始地址（内存的），需要映射的文件长度，可进行的操作权限，映射区域的特性，文件指针，分页大小的整数倍（4K）
	void* base=mmap(NULL,0x810,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0x7F008000);
	if(base==MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	
	//开始移位
	//GPKCON0 控制位  0x7F008800;
	//GPKDAT    数据位  0x7F008808;
	unsigned int *GPKCON0=(unsigned int*)((char*)base+0x800);
	unsigned int *GPKDAT=(unsigned int*)((char*)base+0x808);
	*GPKCON0=(*GPKCON0 & (~(0xF<<16))) | (0x1<<16);
	//*GPKCON0 = ((*GPKCON0 & 0xFFF0FFFF)|0x00010000);  先清零再置位
	while(1)
	{
		//LED1亮
		*GPKDAT=(*GPKDAT) & (~(1<<4));
		sleep(1);
		//LED1灭
		*GPKDAT=(*GPKDAT) | (1<<4);
		sleep(1);
	}
	
	//关闭
	munmap(base,0x810);
	close(fd);
	return 0;
}



