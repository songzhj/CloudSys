#include "mainwindow.h"
#include <QApplication>
#include "filehandler.h"
#include "iconprovider.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login login;
    login.show();
//    MainWindow m;
//    m.show();

    return a.exec();
}
