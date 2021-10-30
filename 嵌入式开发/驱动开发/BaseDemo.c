#include <linux/delay.h>
#include <asm/irq.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/list.h>
#include <linux/pci.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/unistd.h>
#include <linux/device.h>
#include <linux/pci.h> //readl和writel
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/kernel.h>
#include <mach/map.h>
#include <linux/ioctl.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio-bank-f.h>
#include <plat/gpio-cfg.h>
#define DEVICE_NAME "buzzer_dj" //设备名
static int buzzer_major = 0; //预定义的主设备号
struct buzzer_dev_t { //字符设备结构体，决定可以执行什么操作
	struct cdev cdev;
} buzzer_dev; //这一段和static struct cdev cdev;表达了一种意思
static struct class *buzzer_class;
//在驱动初始化的代码里调用class_create为该设备创建一个class，再为每个设备调用device_create创建对应的设备
/*目标文件结构体指针；对应放置信息的缓冲区（用户空间）；要读取的信息长度；读的位置相对于文件开头的偏移*/
static ssize_t buzzer_read(struct file *filp, char __user *buf, size_t len, loff_t *offset)
{
	unsigned tmp;
	int state;
	tmp = readl(S3C64XX_GPFDAT);
	state=(tmp & (1 << (14)));
	if(state!=0) state=1;
	if(!copy_to_user(buf,&state,sizeof(state))) { //从用户空间中拷贝到内核空间
		return sizeof(state);
	} else {
		return -EFAULT;
	}
}
/*目标文件结构体指针；要写入放置信息的缓冲区；要写入的信息长度；写的位置相对于文件开头的偏移*/
static ssize_t buzzer_writ(struct file *filp, const char __user *buf, size_t len, loff_t *offset)
{
	int cmd;
	unsigned tmp;
	if(copy_from_user(&cmd,buf,sizeof(cmd))) { //从内核空间中拷贝到用户空间
		return -EFAULT;
	} else {
		if(cmd!=0) cmd=1;
		tmp = readl(S3C64XX_GPFDAT);
		tmp &= ~(1 << (14));
		tmp |= ( (cmd) << (14) );
		writel(tmp, S3C64XX_GPFDAT);
		return sizeof(cmd);
	}
}
//文件操作结构体
static struct file_operations buzzer_fops= {
	.owner = THIS_MODULE,
	.read = buzzer_read,
	.write = buzzer_writ,
};
//设备驱动模块加载函数
static int __init buzzer_init(void)
{
	int result;
	int ret;
	dev_t buzzer_dev_no = MKDEV(buzzer_major,0); //由预定义的主设备号生成dev_t设备号
	if(buzzer_major) {
		result = register_chrdev_region(buzzer_dev_no,1,DEVICE_NAME); //静态申请设备号
	} else {
		result = alloc_chrdev_region(&buzzer_dev_no,0,1,DEVICE_NAME); //动态分配设备号
		buzzer_major = MAJOR(buzzer_dev_no);
	}
	if(result<0)
		return result;
	cdev_init(&buzzer_dev.cdev,&buzzer_fops); //初始化cdev结构
	buzzer_dev.cdev.owner = THIS_MODULE;
	ret = cdev_add(&buzzer_dev.cdev,MKDEV(buzzer_major,0),1); //注册字符设备
	if (ret) {
		printk("cdev add failed\n");
		goto fail1;
	}
	buzzer_class = class_create(THIS_MODULE,"buzzer_class");
	if(IS_ERR(buzzer_class)) {
		printk("Err: failed in creating class./n");
		goto fail2;
	}
	device_create(buzzer_class, NULL, MKDEV(buzzer_major,0), NULL, DEVICE_NAME);
	{
		unsigned tmp;
		tmp = readl(S3C64XX_GPFCON);
		tmp = (tmp & ~(0x3U<<28))|(0x1U<<28);
		writel(tmp, S3C64XX_GPFCON);
		tmp = readl(S3C64XX_GPFDAT);
		tmp &= ~(0x1 << 14);
		writel(tmp, S3C64XX_GPFDAT);
	}
	return 0;
fail2:
	cdev_del(&buzzer_dev.cdev);
fail1:
	unregister_chrdev_region(buzzer_dev_no, 1);
	return result;
}
static void __exit buzzer_exit(void) //设备驱动模块卸载函数
{
	device_destroy(buzzer_class,MKDEV(buzzer_major,0));
	class_destroy(buzzer_class);
	cdev_del(&buzzer_dev.cdev);
	unregister_chrdev_region(MKDEV(buzzer_major,0), 1);
}

module_init(buzzer_init);

module_exit(buzzer_exit);

MODULE_LICENSE("Dual BSD/GPL");

MODULE_AUTHOR("dj");

