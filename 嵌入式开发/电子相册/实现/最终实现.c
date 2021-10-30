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
  WORD    bfType;    //�����ֽ�
  DWORD   bfSize; //�ĸ��ֽ�
  WORD    bfReserved1;
  WORD    bfReserved2;
  DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
typedef struct BITMAPINFOHEADER{
  DWORD  biSize; //��ʾ���ṹ�Ĵ�С
  LONG   biWidth; //λͼ�Ŀ��
  LONG   biHeight; //λͼ�ĸ߶�
WORD   biPlanes; //��ԶΪ1 ,����û���ù����� û���о� ��msdn����
//Specifies the number of planes for the target device. This value must be set to 1.
  WORD   biBitCount;//λͼ��λ��  ��Ϊ1 4 8 16 24 32 ����û��1 4 �����о�
  DWORD  biCompression; //����Ϊѹ�����ͣ�����ȴ���������ã��Ժ����
  DWORD  biSizeImage; //��ʾλͼ��������Ĵ�С���ֽ�Ϊ��λ
  LONG   biXPelsPerMeter;
  LONG   biYPelsPerMeter;
  DWORD  biClrUsed;
  DWORD  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack()

//bmp�Ľ���
unsigned char* decode_bmp(const char* pic_file,int* w,int* h);
//jpg�Ľ���
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
    bpp=fb_var.bits_per_pixel;//λ��
    printf("fbmemeramer w:%d  h:%d bpp:%d\n",w,h,bpp);
    short* fbmem=mmap(NULL,w*h*bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(fbmem==MAP_FAILED)
    {
        perror("mmap");
    }

//��������
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

//��ΧֵΪunsigned char*,�����ļ�ָ�룬��͸�
unsigned char* decode_bmp(const char* pic_file,int* w,int* h)
{
    FILE* fp=fopen(pic_file,"rb");
    BITMAPINFOHEADER bih;
    fseek(fp,sizeof(BITMAPFILEHEADER),SEEK_SET);//������һ���ṹ��
    fread(&bih,sizeof(BITMAPINFOHEADER),1,fp);//��ȡ�ڶ����ṹ�嵽bin
    if(w!=NULL) *w=bih.biWidth;//�жϲ���ֵ
    if(h!=NULL) *h=bih.biHeight;
    unsigned char* buff=malloc(bih.biWidth*bih.biHeight*bih.biBitCount/8);//�������
    fread(buff,1,bih.biWidth*bih.biHeight*bih.biBitCount/8,fp);
    fclose(fp);
    return buff;
}
