CC = arm-linux-gcc
CPP = arm-linux-g++

led_ctrl.cgi : main.o dev_ctrl.o
	$(CPP) -o led_ctrl.cgi $^

main.o : dev_ctrl.h main.cpp
	$(CPP) -c main.cpp

dev_ctrl.o : dev_ctrl.h dev_ctrl.c
	$(CC) -c dev_ctrl.c

.phony : clean

clean:
	-rm -f main.o dev_ctrl.o led_ctrl.cgi
	
