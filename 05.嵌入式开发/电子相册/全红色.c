#include <stdio.h>
#include <string.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

int main()
{
    int fd;
    fd=open("/dev/fb0",O_RDWR);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    int w,h,bpp;
    struct fb_var_screeninfo fb_var;
    ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);//io控制，获取信息，获取状态，参数信息

    //宽、高、位深
    w=fb_var.xres;
    h=fb_var.yres;
    bpp=fb_var.bits_per_pixel;//位深，每个像素占多少位
    printf("fbmemeramer w:%d  h:%d bpp:%d\n",w,h,bpp);

    //得到帧缓冲区的首地址，内存拷贝比较耗费时间，使用内存映射的方式比较方便，提高效率
    short* fbmem=mmap(NULL,w*h*bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(fbmem==MAP_FAILED)
    {
        perror("mmap");
    }

    int i;
    for(i=0;i<w*h;i++)
    {
        fbmem[i]=0xF800;
    }

    munmap(fbmem,w*h*bpp/8);
    close(fd);
    return 0;
}

