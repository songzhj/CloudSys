#include "mainwindow.h"
#include <QApplication>
#include "filehandler.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD

=======
>>>>>>> origin/master
    Login login;
    login.show();

    return a.exec();
}
