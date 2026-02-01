#include <QtGui/QApplication>
#include "dialog.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Dialog w;
    //w.show();

    QUdpSocket sock;
    sock.bind(9413);

    char cmd[100];

    while(1)
    {
       sock.waitForReadyRead(-1);

       while(sock.hasPendingDatagrams())
       {
           memset(cmd,0,sizeof(cmd)); //某一位 置零
           sock.readDatagram(cmd,sizeof(cmd)-1);

           if(strcmp(cmd,"1")==0)
           {
               QProcess p;
               p.start("shutdown -s -t 0");
               p.waitForFinished(-1);
           }
           else if(strcmp(cmd,"2")==0)
           {

           }
       }
    }

    return a.exec();
}
