#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

int fd;

void sig_fun(int signum)
{
    if(signum==SIGINT)
    {
        int cmd=0;
        write(fd,&cmd,sizeof(cmd));
        close(fd);
        exit(0);
    }
}


int main()
{
    signal(SIGINT,sig_fun);

    fd=open("/dev/buzzer",O_RDWR);

    if(fd==-1)
    {
        perror("open /dev/buzzer");
        exit(1);
    }

    int cmd=0;

    while(1)
    {
        write(fd,&cmd,sizeof(cmd));
        cmd=!cmd;
        sleep(1);
    }

    close(fd);

    return 0;
}

