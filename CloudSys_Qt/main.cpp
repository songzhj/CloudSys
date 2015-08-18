#include "mainwindow.h"
#include <QApplication>
#include "filehandler.h"
#include "iconprovider.h"
#include "icondisplayerwidget.h"
#include "login.h"
#include "fileinforesolver.h"
#include "tcp.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    login.show();
//    IconDisplayerWidget widget;
//    widget.show();
    return a.exec();
}
