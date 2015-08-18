#include "mainwindow.h"
#include <QApplication>
#include "filehandler.h"
#include "iconprovider.h"
#include "login.h"


#include "tcp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Login login;
//    login.show();
//    MainWindow m;
//    m.show();
    TCP *tcp = new TCP("49.140.98.76", 23333);
    tcp->send("qazws");
    tcp->send("#END#");
    qDebug() << tcp->receive();
    return a.exec();
}
