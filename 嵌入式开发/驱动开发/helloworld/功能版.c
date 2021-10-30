#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#define MAJOR_NUM 250

static ssize_t hello_read(struct file*,char*,size_t,loff_t*);
static ssize_t hello_write(struct file*,const char*,size_t,loff_t*);

struct file_operations hello_fops={ 
//指定初始化
    .read=hello_read,
    .write=hello_write
};

//static devfs_handle_t devfs_handle;
static struct class* mycla;

static int buff;
//加载函数
static int __init hello_init(void)
{
/*
    printk("<2>""Hello,Kernel!\n");

    return 0;
*/

    int ret;

    ret=register_chrdev(MAJOR_NUM,"hello",&hello_fops);

    if(ret<0)
    {
        printk(KERN_ALERT"hello register fail!\n");
    }
    else
    {
        printk(KERN_ALERT"hello register success!%d\n",ret);
    }

    /*
    devfs_handle=devfs_register(NULL,"hello",DEVFS_FL_DEFAULT,MAJOR_NUM,&hello_fops,NULL);
    */

    mycla=class_create(THIS_MODULE,"myclass");

    if(IS_ERR(mycla))
    {
        printk(KERN_ALERT"class_create fail!\n");
        unregister_chrdev(MAJOR_NUM,"hello");
        return -1;
    }

    device_create(mycla,NULL,MKDEV(MAJOR_NUM,0),NULL,"hello");

    return ret;
}
//卸载函数
static void __exit hello_exit(void)
{
    //printk(KERN_ALERT"Hello module exit!\n");

    //devfs_unregister(devfs_handle);
    device_destroy(mycla,MKDEV(MAJOR_NUM,0)); //内核API函数，销毁设备
    class_destroy(mycla); //销毁设备类

    unregister_chrdev(MAJOR_NUM,"hello"); 
    printk("<1>""hello unregister success!\n");
}

static ssize_t hello_read(struct file* filp,char* buf,size_t len,loff_t* off)
{
    if(!copy_to_user(buf,&buff,sizeof(buff)))   //从内核空间拷贝到用户空间
    {
        return sizeof(buff);
    }
    else
    {
        return -EFAULT;
    }
}

static ssize_t hello_write(struct file* filp,const char* buf,size_t len,loff_t* off)
{
    if(copy_from_user(&buff,buf,sizeof(buff)))  
    {
        return -EFAULT;
    }
    else
    {
        return sizeof(buff);
    }
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("dj");
MODULE_DESCRIPTION("This is Hello module!");

