#生成目标文件
obj-m += test.c

#内核源码位置
KDIR := /KDIR-ARM

default:
	$(MAKE) -C $(KDIR) M='pwd' modules
clean:
	$(MAKE) -C $(KDIR) M='pwd' clean