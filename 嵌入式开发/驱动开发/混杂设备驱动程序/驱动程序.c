#include <linux/miscdevice.h>
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
#include <linux/pci.h> //readl��writel
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
#define DEVICE_NAME "buzzer" //�豸��
#define BUZZER_MINOR MISC_DYNAMIC_MINOR //��̬������豸��
//#define BUZZER_MINOR 30; //��̬������豸��
static struct semaphore sem;
/*Ŀ���ļ��ṹ��ָ�룻��Ӧ������Ϣ�Ļ��������û��ռ䣩��Ҫ��ȡ����Ϣ���ȣ�����λ��������ļ���ͷ��ƫ��*/
static ssize_t buzzer_read(struct file *filp, char __user *buf, size_t len, loff_t *offset)
{
	unsigned tmp;
	int state;
	tmp = readl(S3C64XX_GPFDAT);
	state=(tmp & (1 << (14)));
	if(state!=0) state=1;
	if(!copy_to_user(buf,&state,sizeof(state)))
	{
		return sizeof(state);
	}
	else
	{
		return -EFAULT;
	}
}
/*Ŀ���ļ��ṹ��ָ�룻Ҫд�������Ϣ�Ļ�������Ҫд�����Ϣ���ȣ�д��λ��������ļ���ͷ��ƫ��*/
static ssize_t buzzer_writ(struct file *filp, const char __user *buf, size_t len, loff_t *offset)
{
	int cmd;
	unsigned tmp;
	if(copy_from_user(&cmd,buf,sizeof(cmd)))
	{
		return -EFAULT;
	}
	else
	{
		if(cmd!=0) cmd=1;
		tmp = readl(S3C64XX_GPFDAT);
		tmp &= ~(1 << (14));
		tmp |= ( (cmd) << (14) );
		writel(tmp, S3C64XX_GPFDAT);
		return sizeof(cmd);
	}
}
static int buzzer_open(struct inode *inode, struct file *filp)
{
	if(down_trylock(&sem))
	{
		return -EBUSY;
	}
	return 0;
}

static int buzzer_release(struct inode *inode, struct file *filp)
{
	up(&sem);
	return 0;
}
static struct file_operations buzzer_fops= //�ļ������ṹ��
{
	.owner = THIS_MODULE,
	.read = buzzer_read,
	.write = buzzer_writ,
	.open = buzzer_open,
	.release = buzzer_release,
};
static struct miscdevice misc = {
	.minor = BUZZER_MINOR,
	.name = DEVICE_NAME,
	.fops = &buzzer_fops,
};
static int __init buzzer_init(void) //�豸����ģ����غ���
{
	int ret;
	{
		unsigned tmp;
		tmp = readl(S3C64XX_GPFCON);
		tmp = (tmp & ~(0x3U<<28))|(0x1U<<28);
		writel(tmp, S3C64XX_GPFCON);
		tmp = readl(S3C64XX_GPFDAT);
		tmp &= ~(0x1 << 14);
		writel(tmp, S3C64XX_GPFDAT);
	}
	ret = misc_register(&misc);
	printk (DEVICE_NAME"\tinitialized\n");
	sema_init(&sem,1);
	return ret;
}
static void __exit buzzer_exit(void) //�豸����ģ��ж�غ���
{
	misc_deregister(&misc);
}

module_init(buzzer_init);

module_exit(buzzer_exit);

MODULE_LICENSE("Dual BSD/GPL");

MODULE_AUTHOR("dj");
 
