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
#define DEVICE_NAME "buzzer_dj" //�豸��
static int buzzer_major = 0; //Ԥ��������豸��
struct buzzer_dev_t { //�ַ��豸�ṹ�壬��������ִ��ʲô����
	struct cdev cdev;
} buzzer_dev; //��һ�κ�static struct cdev cdev;�����һ����˼
static struct class *buzzer_class;
//��������ʼ���Ĵ��������class_createΪ���豸����һ��class����Ϊÿ���豸����device_create������Ӧ���豸
/*Ŀ���ļ��ṹ��ָ�룻��Ӧ������Ϣ�Ļ��������û��ռ䣩��Ҫ��ȡ����Ϣ���ȣ�����λ��������ļ���ͷ��ƫ��*/
static ssize_t buzzer_read(struct file *filp, char __user *buf, size_t len, loff_t *offset)
{
	unsigned tmp;
	int state;
	tmp = readl(S3C64XX_GPFDAT);
	state=(tmp & (1 << (14)));
	if(state!=0) state=1;
	if(!copy_to_user(buf,&state,sizeof(state))) { //���û��ռ��п������ں˿ռ�
		return sizeof(state);
	} else {
		return -EFAULT;
	}
}
/*Ŀ���ļ��ṹ��ָ�룻Ҫд�������Ϣ�Ļ�������Ҫд�����Ϣ���ȣ�д��λ��������ļ���ͷ��ƫ��*/
static ssize_t buzzer_writ(struct file *filp, const char __user *buf, size_t len, loff_t *offset)
{
	int cmd;
	unsigned tmp;
	if(copy_from_user(&cmd,buf,sizeof(cmd))) { //���ں˿ռ��п������û��ռ�
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
//�ļ������ṹ��
static struct file_operations buzzer_fops= {
	.owner = THIS_MODULE,
	.read = buzzer_read,
	.write = buzzer_writ,
};
//�豸����ģ����غ���
static int __init buzzer_init(void)
{
	int result;
	int ret;
	dev_t buzzer_dev_no = MKDEV(buzzer_major,0); //��Ԥ��������豸������dev_t�豸��
	if(buzzer_major) {
		result = register_chrdev_region(buzzer_dev_no,1,DEVICE_NAME); //��̬�����豸��
	} else {
		result = alloc_chrdev_region(&buzzer_dev_no,0,1,DEVICE_NAME); //��̬�����豸��
		buzzer_major = MAJOR(buzzer_dev_no);
	}
	if(result<0)
		return result;
	cdev_init(&buzzer_dev.cdev,&buzzer_fops); //��ʼ��cdev�ṹ
	buzzer_dev.cdev.owner = THIS_MODULE;
	ret = cdev_add(&buzzer_dev.cdev,MKDEV(buzzer_major,0),1); //ע���ַ��豸
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
static void __exit buzzer_exit(void) //�豸����ģ��ж�غ���
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

