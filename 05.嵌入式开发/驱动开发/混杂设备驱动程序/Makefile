KERDIR := /home/dj/linux-2.6.38/
PWD := $(shell pwd)
obj-m := buzzer_dj.o

default:
    $(MAKE) ARCH=arm CROSS_COMPILE=arm-linux- -C $(KERDIR) M=$(PWD) modules # ARM

.PHONY:clean
clean:
    $(MAKE) -C $(KERDIR) M=$(PWD) clean