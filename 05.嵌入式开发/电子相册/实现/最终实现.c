#include <stdio.h>
#include <string.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;
#pragma pack(1)
typedef struct BITMAPFILEHEADER {
  WORD    bfType;    //两个字节
  DWORD   bfSize; //四个字节
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
typedef struct BITMAPINFOHEADER{
  DWORD  biSize; //表示本结构的大小
  LONG   biWidth; //位图的宽度
  LONG   biHeight; //位图的高度
WORD   biPlanes; //永远为1 ,由于没有用过所以 没做研究 附msdn解释
//Specifies the number of planes for the target device. This value must be set to 1.
  WORD   biBitCount;//位图的位数  分为1 4 8 16 24 32 本文没对1 4 进行研究
  DWORD  biCompression; //本以为压缩类型，但是却另外有作用，稍候解释
  DWORD  biSizeImage; //表示位图数据区域的大小以字节为单位
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack()

//bmp的解码
unsigned char* decode_bmp(const char* pic_file,int* w,int* h);
//jpg的解码
unsigned char *decode_jpeg (char * filename, short *widthPtr, short *heightPtr);
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
    ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);
    w=fb_var.xres;
    h=fb_var.yres;
    bpp=fb_var.bits_per_pixel;//位深
    printf("fbmemeramer w:%d  h:%d bpp:%d\n",w,h,bpp);
    short* fbmem=mmap(NULL,w*h*bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(fbmem==MAP_FAILED)
    {
        perror("mmap");
    }

//堆区数组
    unsigned char** pic=malloc(6*sizeof(unsigned char*));
    int i,j,k;
    char pic_file[50];
    for(i=1;i<=3;i++)
    {
        sprintf(pic_file,"%d.bmp",i);
        pic[i-1]=decode_bmp(pic_file,NULL,NULL);
    }
    short width,height;
    for(i=1;i<=3;i++)
    {
        sprintf(pic_file,"%d.jpg",i);
        pic[i+2]=decode_jpeg(pic_file,&width,&height);
    }
    while(1)
    {
        for(k=0;k<6;k++)
        {
            for(i=0;i<h;i++)
            {
                for(j=0;j<w;j++)
                {
                    //fbmem[i]=0xF800;
                    fbmem[(h-i)*w+j]=pic[k][3*(i*w+j)]>>3;
                    fbmem[(h-i)*w+j]|=(pic[k][3*(i*w+j)+1]>>2)<<5;
                    fbmem[(h-i)*w+j]|=(pic[k][3*(i*w+j)+2]>>3)<<11;
                }
                usleep(1000);
            }
            sleep(1);
        }
    }
    for(k=0;k<6;k++) free(pic[k]);
    free(pic);
    munmap(fbmem,w*h*bpp/8);
    close(fd);
    return 0;
}

//范围值为unsigned char*,传入文件指针，宽和高
unsigned char* decode_bmp(const char* pic_file,int* w,int* h)
{
    FILE* fp=fopen(pic_file,"rb");
    BITMAPINFOHEADER bih;
    fseek(fp,sizeof(BITMAPFILEHEADER),SEEK_SET);//跳过第一个结构体
    fread(&bih,sizeof(BITMAPINFOHEADER),1,fp);//读取第二个结构体到bin
    if(w!=NULL) *w=bih.biWidth;//判断并赋值
    if(h!=NULL) *h=bih.biHeight;
    unsigned char* buff=malloc(bih.biWidth*bih.biHeight*bih.biBitCount/8);//申请堆区
    fread(buff,1,bih.biWidth*bih.biHeight*bih.biBitCount/8,fp);
    fclose(fp);
    return buff;
}
