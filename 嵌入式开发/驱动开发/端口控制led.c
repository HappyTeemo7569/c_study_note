//GPIO��General Purpose Input/Output Port��ͨ��I/O�˿�
//S3C6410΢������оƬ����188��GPIO�˿ڣ�����Ϊ17�飬��17��GPIO�˿�

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main()
{
     //��/dev/men�ļ���/dev/men�豸�ļ��������������ڴ棬�����������ڴ��豸�ĳ��󣬷��������Ƿ��������ڴ�
	int fd=open("/dev/mem",O_RDWR);
	if(fd==-1)
	{
	perror("open /dev/mem fail");
	exit(1);
 	}

	//�ڴ�ӳ���ļ������ļ�ӳ�䵽�ڴ���
	//#include <sys/mman.h>
	//void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
	//ӳ�����ʼ��ַ���ڴ�ģ�����Ҫӳ����ļ����ȣ��ɽ��еĲ���Ȩ�ޣ�ӳ����������ԣ��ļ�ָ�룬��ҳ��С����������4K��
	void* base=mmap(NULL,0x810,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0x7F008000);
	if(base==MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	
	//��ʼ��λ
	//GPKCON0 ����λ  0x7F008800;
	//GPKDAT    ����λ  0x7F008808;
	unsigned int *GPKCON0=(unsigned int*)((char*)base+0x800);
	unsigned int *GPKDAT=(unsigned int*)((char*)base+0x808);
	*GPKCON0=(*GPKCON0 & (~(0xF<<16))) | (0x1<<16);
	//*GPKCON0 = ((*GPKCON0 & 0xFFF0FFFF)|0x00010000);  ����������λ
	while(1)
	{
		//LED1��
		*GPKDAT=(*GPKDAT) & (~(1<<4));
		sleep(1);
		//LED1��
		*GPKDAT=(*GPKDAT) | (1<<4);
		sleep(1);
	}
	
	//�ر�
	munmap(base,0x810);
	close(fd);
	return 0;
}



