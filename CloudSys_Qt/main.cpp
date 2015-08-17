#include "mainwindow.h"
#include <QApplication>
#include "filehandler.h"
#include "iconprovider.h"
#include "icondisplayerwidget.h"
#include "login.h"
#include "fileinforesolver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
//    Login login;
//    login.show();
    IconDisplayerWidget widget;
=======
    Login login;
    login.show();
//    MainWindow m;
//    m.show();
>>>>>>> origin/master

    QList<QString> fileInfoList;
    fileInfoList.push_back("1.txt");
    fileInfoList.push_back("1.doc");
    fileInfoList.push_back("1.jpg");
    fileInfoList.push_back("1.zip");
    fileInfoList.push_back("1.ppt");
    FileInfoResolver resolver(fileInfoList);
    resolver.addIconToQListWidget(widget.getListWidget());
  //  widget.addIcon(provider.fileExtensionIcon(".doc"), (QString)"word文档");
    widget.show();
    return a.exec();
}
